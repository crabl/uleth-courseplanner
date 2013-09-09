/// \file
/// \brief An Objective requiring a given number of courses at a particular level to be completed
/// \author Bradley Ellert 001133286
/// \date November 22, 2010

#include "MinimumObjective.h"

bool MinimumObjective::status (std::ostream& os, const std::vector <Course*>& coursesTaken) const
{
  unsigned int numCourses = 0; // Number of courses that match the level.
  for (unsigned int i = 0; i < coursesTaken.size(); i++)
    {
      if ((coursesTaken[i]->getNumber() >= level)
	  && (coursesTaken[i]->getNumber() < (level + 1000)))
	if (coursesTaken[i]->getDepartment() == department)
	  numCourses++;
    }
  
  if (numCourses >= minCourses)
  {
     os << "Enough " << level << "-level " << department << " courses have been taken.";
     return true;
  }
  else
  {
     if (minCourses == 1)
     {
	os << "The required " << level << "-level " << department << " course has not been taken.";
     }
     else
     {
	os << numCourses << " out of " << minCourses << " required " << level << "-level " << department << " courses";
	if (numCourses == 1)
	{
	   os << " has ";
	}
	else
	{
	   os << " have ";
	}
	os << "been taken.";
     }
     return false;
  }
}

MinimumObjective* MinimumObjective::clone() const
{
  return new MinimumObjective(*this);
}

void MinimumObjective::read (std::istream& iStr)
{
  iStr >> minCourses >> department >> level;
}
   
void MinimumObjective::write (std::ostream& os) const
{
   os << "A minimum of " << minCourses << " "
      << level << "-level "
      << department << " courses";
}
