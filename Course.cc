/// \file
/// \brief A class to represent a University of Lethbridge course
/// \author Bradley Ellert 001133286
/// \date November 22, 2010

#include "Course.h"

Course::Course(const Course& cObj) {
   category = cObj.getGler();
   department = cObj.getDepartment();
   number = cObj.getNumber();
   title = cObj.getTitle();
   description = cObj.getDescription();

   for(unsigned int i = 0; i < cObj.getPrerequisites().size(); i++)
      prerequisites.push_back(cObj.getPrerequisites()[i]->clone());
}

Course* Course::clone() {
   return new Course (*this);
}

Course::~Course()
{
   for (unsigned int i = 0; i < prerequisites.size(); i++)
   {
      delete prerequisites[i];
      prerequisites[i] = NULL;
   }
}

const GLER Course::getGler () const
{
   if (category == SCIENCE)
      return SCIENCE;
   else if(category == SOCIAL_SCIENCE)
      return SOCIAL_SCIENCE;
   else return FINE_ARTS_HUMANITY;
}

const std::string Course::getDepartment() const {
   return department;
}

int Course::getNumber () const
{
   return number;
}

const std::vector<Objective*> Course::getPrerequisites() const {
   std::vector<Objective*> vector;

   for(unsigned int i = 0; i < prerequisites.size(); i++)
      vector.push_back(prerequisites[i]->clone());

   return vector;
}

const std::string Course::getTitle() const {
   return title;
}

const std::string Course::getDescription() const {
   return description;
}

bool Course::hasTaken(std::vector <Course*> courseVector) const
{
   for (unsigned int i = 0; i < courseVector.size(); i++)
      if (number == courseVector[i] -> getNumber())
	 if (department == courseVector[i] -> getDepartment())
	    return true;
   return false;
}

void Course::read(std::istream& iStr) throw(InvalidFile) {
   try {
      iStr >> department >> number;
      iStr.ignore();
      getline(iStr, title);
      getline(iStr, description);
      iStr >> category;
      iStr.ignore();
      while(iStr.peek () == 'P')
      {
	 iStr.ignore();
	 iStr.ignore();
	 Objective* prerequisite;
	 switch(iStr.peek()) {
	    case 'S': {
	       prerequisite = new SingleObjective;
	       break;
	    }
	    case 'O': {
	       prerequisite = new OneOfObjective;
	       break;
	    }
	    default: {
	       throw InvalidObjective("Reading objective from course file failed!");
	       break;
	    }
	 }
	 iStr.ignore();
	 prerequisite -> read(iStr);
	 prerequisites.push_back(prerequisite);
	 iStr.ignore();
      }
   } catch(std::exception& e) {
      throw InvalidFile("Reading course file failed!");
   }
}

void Course::write(std::ostream& os) const {
  os << "Course: " << department << " " << number << std::endl
     << "Title: " << title << std::endl
     << "Description: " << description << std::endl
     << "GLER: " << category << std::endl
     << "Prerequisite(s): ";

  if (prerequisites.size() == 0) {
    os << "None" << std::endl;
  } else {
     os << std::endl;
     for(unsigned int i = 0; i < prerequisites.size(); i++) {
	prerequisites [i] -> write (os);
	os << std:: endl;
     }
  }
}

std::istream& operator>>(std::istream& iStr, Course& c) {
  c.read(iStr);
  return iStr;
}

std::ostream& operator<<(std::ostream& os, const Course& c) {
  c.write(os);
  return os;
}

const bool operator==(const Course& firstCourse, const Course& secondCourse) {
  if ( firstCourse.getTitle() == secondCourse.getTitle() )
    if ( firstCourse.getDescription() == secondCourse.getDescription())
      if ( firstCourse.getNumber() == secondCourse.getNumber())
	if ( firstCourse.getGler() == secondCourse.getGler())
	  if ( firstCourse.getPrerequisites().size() 
	       == secondCourse.getPrerequisites().size())
	    {
	      for (unsigned int i = 0; 
		   i < firstCourse.getPrerequisites().size(); i++)
		if (!(firstCourse.getPrerequisites()[i]->
		      isEqual(secondCourse.getPrerequisites()[i])))
		  return false;
	      return true;
	    }
  return false;
}

