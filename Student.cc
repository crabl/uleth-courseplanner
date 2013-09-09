/// \file
/// \brief A class to represent a student's course status
/// \author Bradley Ellert 001133286
/// \date November 22, 2010

#include "Student.h"

Major* Student::getMajor () const
{
   return studentMajor;
}

const std::vector <Course*> Student::getCourses () const
{
   return coursesTaken;
}

void Student::write (std::ostream& os) const
{
   os << "Major: " << studentMajor -> getTitle () << std::endl
      << "Courses Taken: ";
   if (coursesTaken.size () == 0)
   {
      os << "None" << std::endl;
   }
   else
   {
      for (unsigned int i = 0; i < coursesTaken.size () - 1; ++i)
	 os << coursesTaken [i] -> getDepartment () << ' ' << coursesTaken [i] -> getNumber () << ", ";
      os << coursesTaken [coursesTaken.size () - 1] -> getDepartment () << ' ' << coursesTaken [coursesTaken.size () - 1] -> getNumber () << std::endl;
   }
   if (status (os))
      os << "Graduated!";
}

void Student::changeMajor (Major* m)
{
   studentMajor = m;
}

void Student::addCourse (Course* c) throw (CourseAlreadyExists)
{
   unsigned int coursesLength = coursesTaken.size();
   for (unsigned int i = 0; i < coursesLength; ++i) {
      if(coursesTaken[i] == c) {
	 throw CourseAlreadyExists("Student has already taken this course!");
      }
   }
   
  coursesTaken.push_back(c);
}

void Student::removeCourse(const Course* c) throw (CourseNotFound)
{
   bool courseErased = false;
   
   for (unsigned int i = 0; i < coursesTaken.size(); i++)
   {
      if (coursesTaken [i] == c)
      {
	 coursesTaken.erase (coursesTaken.begin () + i);
	 courseErased = true;
      }
   }
   
   if(!courseErased)
   {
      throw CourseNotFound("The Student has not taken the course to be deleted!");
   }
}
	 
bool Student::status (std::ostream& os) const
{
   return studentMajor->status(os, coursesTaken);
}

bool Student::canTake (const Course* c) const
{
   if (c -> hasTaken(coursesTaken))
      return false;
   std::ostringstream oss;
   for (unsigned int i = 0; i < c->getPrerequisites().size(); i++)
   {
      if (!( c->getPrerequisites()[i]->status(oss, coursesTaken)))
      {
	 return false;
      }
   }

   // Check that the student hasn't already taken the course
   for (unsigned int i = 0; i < coursesTaken.size(); i++)
   {
      if(coursesTaken[i] == c)
      {
	 return false;
      }
   }

  return true;
}

std::ostream& operator<< (std::ostream& os, const Student& s)
{
   s.write(os);
  return os;
}
