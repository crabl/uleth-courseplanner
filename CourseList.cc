/// \file
/// \brief A master list of courses
/// \author Bradley Ellert 001133286
/// \date November 22, 2010

#include "CourseList.h"

/// Initialize static member variables
CourseList* CourseList::instance = NULL;
bool CourseList::instanceCreated = false;

/// This function removes all the Courses contained in the CourseList when the application exits.
/// It isn't even really necessary, because the only time that the CourseList should be deleted
/// is when the program terminates, and even then, without this function the operating system would
/// simply free the memory that was used by it anyway. So, *technically*, that is not a memory leak.
/// I am not going to naively say that it is never a memory leak, because some OSes don't free the
/// memory, so we'll include the destroy() function anyway. -CR
void CourseList::destroy()
{
   unsigned int sizeCourses = courses.size();
   
   /// Go through the CourseList and delete all Course*
   for (unsigned int i = 0; i < sizeCourses; ++i) {
      delete courses[i];
   }

   instance = NULL;
   instanceCreated = false;
}

CourseList* CourseList::getInstance()
{
   if(!instanceCreated) 
  {
     instance = new CourseList();
     instanceCreated = true;
     return instance;
  } else {
      return instance;
   }
}

void CourseList::read (std::istream& iStr) throw (CourseAlreadyExists, InvalidFile)
{
   while (iStr.peek () == 'C')
   {
      iStr.ignore ();
      iStr.ignore ();
      Course* course = new Course;
      iStr >> *course;
      
      // Check that the student has not taken the same course twice
      for (unsigned int i = 0; i < courses.size(); ++i) {
	if (course == courses[i]) {
	    throw CourseAlreadyExists("Duplicate Course detected");
        }
      }
      
      courses.push_back(course);
      iStr.ignore();
    }
}

void CourseList::write(std::ostream& os) const {
   os << "Available courses: ";

   for (unsigned int i = 0; i < courses.size () - 1; ++i)
      os << courses [i] -> getDepartment () << ' ' << courses [i] -> getNumber () << ", ";

   os << courses [courses.size () - 1] -> getDepartment () << ' ' << courses [courses.size () - 1] -> getNumber () << std::endl;
}

// The course number will be more unique in the vector than the department,
// so it is more useful to search for a matching number, then make sure it 
// matches the department.
Course* CourseList::find (const std::string& department, const int& number)
{
   for (unsigned int i = 0; i < courses.size(); i++)
   {
      if (courses[i]->getNumber() == number)
	 if (courses[i]->getDepartment() == department)
	    return courses[i];
   }
   return NULL;
}

std::istream& operator>> (std::istream& iStr, CourseList& cl) 
{
   cl.read(iStr);
   return iStr;
}

std::ostream& operator<< (std::ostream& os, const CourseList& cl)
{
   cl.write(os);
   return os;
}
