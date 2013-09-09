/// \file
/// \brief The main objective for completing a generic major
/// \author Bradley Ellert 001133286
/// \date November 22, 2010

#include "FortyCoursesObjective.h"

FortyCoursesObjective* FortyCoursesObjective::clone() const 
{
  return new FortyCoursesObjective (*this);
}

bool FortyCoursesObjective::status (std::ostream& os, const std::vector <Course*>& coursesTaken) const
{
  // Create an empty vector to put in unique occurences of department
  std::vector <std::string> uniqueDept;

  // Because the vector is empty, we can push back the first department
  if (!coursesTaken.empty ())
  uniqueDept.push_back(coursesTaken[0]->getDepartment());

  //Bool to keep track of department uniqueness
  bool isUnique;

  // For loop to add the rest of the unique departments into the vector
  for (unsigned int i = 1; i < coursesTaken.size(); i++)
    {
      isUnique = false;
      for (unsigned int j = 0; j < uniqueDept.size(); j++)
	if (uniqueDept[j] == coursesTaken[i]->getDepartment())
	  isUnique = true;
      if (!isUnique)
	uniqueDept.push_back(coursesTaken[i]->getDepartment());
    }

  // Initialize counters for the unique departments and for the 10 1000 courses
  std::vector<int> uniqueCounter; // Counters for the unique departments
  for (unsigned int i = 0; i < uniqueDept.size(); i++)
    uniqueCounter.push_back(0);
  int levelCounter = 0;           // Counter for 1000 level courses
  
  // Loop through the coursesTaken a second time to count
  for (unsigned int i = 0; i < coursesTaken.size(); i++ )
    {
      if (coursesTaken[i]->getNumber() < 2000)
	if (coursesTaken[i]->getNumber() >= 1000)
	  levelCounter++;
      for (unsigned int j = 0; j < uniqueDept.size(); j++)
	{
	  if (uniqueDept[j] == coursesTaken[i]->getDepartment())
	    {
	      uniqueCounter[j]++;
	      break;
	    }
	}
    }
  
  // Initialized the total count to be the total number of courses taken
  // and subtracted any amount of courses that exceeded the restrictions
  int totalCount = coursesTaken.size();
  if (levelCounter > 10)
    totalCount -= (levelCounter - 10);
  for (unsigned int i = 0; i < uniqueCounter.size(); i++)
    {
      if (uniqueCounter[i] > 20)
	totalCount -= (uniqueCounter[i] - 20);
    }

  // Check to see that totalCount is in fact 40 or more courses
  if (totalCount >= 40)
    {
      os << "Enough unique courses have been taken.";
      return true;
    }
  else {
    os << "Not enough unique courses have been taken.";
    return false;
  }
}

void FortyCoursesObjective::write (std::ostream& os) const
{
   os << "40 courses, no more than 10 of which are at the 1000 level and no more than 20 of which are from one department";
}
