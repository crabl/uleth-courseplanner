/// \file
/// \brief An objective requiring 4 of a particular GLER category to be taken
/// \author Bradley Ellert 001133286
/// \date November 22, 2010

#include "GLERObjective.h"

GLERObjective* GLERObjective::clone () const
{
   return NULL;
}

bool GLERObjective::status (std::ostream& os, const std::vector <Course*>& coursesTaken) const
{
   int glerCounter = 0;  //counts the courses that match the required GLER
   for (unsigned int i = 0; i < coursesTaken.size(); i++)
   {
      if (coursesTaken[i]->getGler() == glerType)
	 glerCounter++;
      if (glerCounter >= 4)
      {
	 os << "Four or more " << glerType << " GLERs have been taken.";
	 return true;
      }
   }
   if (glerCounter == 0)
      os << "No " << glerType << " GLERs have been taken.";
   else if (glerCounter == 1)
      os << "Only 1 " << glerType << " GLER has been taken.";
   else
      os << "Only " << glerCounter << ' ' << glerType << " GLERs have been taken.";
   return false;
}

void GLERObjective::read (std::istream& iStr) throw (InvalidGLER)
{
   try {
      iStr >> glerType;
   } catch (std::exception& e) {
      throw InvalidGLER("Unable to create GLERObjective");
   }
}

void GLERObjective::write (std::ostream& os) const
{
   os << "4 " << glerType << " GLERs";
}
