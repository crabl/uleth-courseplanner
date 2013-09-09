/// \file
/// \brief Builds a potential future plan for a Student
/// \author Bradley Ellert 001133286
/// \date November 6, 2010

#include "Plan.h"

Major* Plan::getMajor () const
{
   if (planMajor != NULL)
      return planMajor;
   if (student != NULL)
      return (student -> getMajor ());
   return NULL;
}

std::vector <Course*> Plan::getCourses () const
{
   return coursesToTake;
}

void Plan::write (std::ostream& os) const throw(InvalidPlan)
{

   if(getMajor () == NULL) {
      throw InvalidPlan("Plan does not have a major");
   }
   
   os << "Major: " << getMajor () -> getTitle () << std::endl
      << "Courses To Take: ";

   if (coursesToTake.size () == 0)
   {
      os << "None" << std::endl;
   }
   else
   {
      for (unsigned int i = 0; i < coursesToTake.size () - 1; ++i)
	 os << coursesToTake [i] -> getDepartment () << ' ' << coursesToTake [i] -> getNumber () << ", ";
      os << coursesToTake [coursesToTake.size () - 1] -> getDepartment () << ' ' << coursesToTake [coursesToTake.size () - 1] -> getNumber () << std::endl;
   }
   if (status (os))
      os << "Graduated!";
}

void Plan::changeMajor (Major* newMajor)
{
   planMajor = newMajor;
}

void Plan::addCourse (Course* newCourse) throw (CourseAlreadyExists)
{
   for (unsigned int i = 0; i < coursesToTake.size(); ++i) {
      if(coursesToTake[i] == newCourse) {
	 throw CourseAlreadyExists("The specified course already exists in the plan");
      }
   }
   
   coursesToTake.push_back(newCourse);
}

void Plan::removeCourse(const Course* oldCourse)
{
   for (unsigned int i = 0; i < coursesToTake.size(); i++)
   {
      if (coursesToTake[i] == oldCourse)
      {
	 coursesToTake.erase(coursesToTake.begin () + i);
      }
   }
}

bool Plan::status (std::ostream& os) const throw (InvalidPlan)
{

   if (getMajor () == NULL) {
      throw InvalidPlan ("Plan does not have a major");
   }
   
   return getMajor () -> status (os, combineVectors ());
}
   
bool Plan::canTake (const Course* potentialCourse) const throw (InvalidPlan)
{
   try {
      if (potentialCourse->hasTaken(combineVectors()))
	 return false;
      std::ostringstream oss;
      for (unsigned int i = 0; i < potentialCourse->getPrerequisites().size();
	i++)
      {
	 if (!( potentialCourse->getPrerequisites()[i]->status(oss,combineVectors())))
	 {
	    return false;
	 }
      }
   } catch (std::exception& e) {
      throw InvalidPlan("Plan is not associated with a student");
   }
   
   return true;
}
   
void Plan::commitChanges() throw (InvalidPlan)
{
   if (student == NULL || getMajor () == NULL) {
      throw InvalidPlan("Plan Student or Plan Major is not defined");
   }
   
   student -> changeMajor (getMajor ());
   planMajor = NULL;
   
   for (unsigned int i = 0; i < coursesToTake.size(); i++)
   {
      student->addCourse(coursesToTake[i]);
   }
   coursesToTake.clear ();  
}

std::vector <Course*> Plan::combineVectors() const throw (InvalidPlan)
{

   if (student == NULL) {
      throw InvalidPlan("Plan is not associated with a student");
   }
   
   std::vector <Course*> tempVector;
   for (unsigned int i = 0; i < student->getCourses().size(); i++)
   {
      tempVector.push_back(student->getCourses()[i]);
   }
   for (unsigned int i = 0; i < coursesToTake.size(); i++)
   {
      tempVector.push_back(coursesToTake[i]);
   }
   return tempVector;
}

std::ostream& operator<< (std::ostream& os, const Plan& p)
{
   p.write(os);
  return os;
}
