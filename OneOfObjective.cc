/// \file
/// \brief An objective requiring a single Course out of a list of Courses to be completed
/// \author Bradley Ellert 001133286
/// \date November 22, 2010

#include "OneOfObjective.h"

OneOfObjective::OneOfObjective (const OneOfObjective& oObj)
{
   for (unsigned int i = 0; i < oObj.getDeptVector().size(); i++)
   {
      oneOfDept.push_back(oObj.getDeptVector()[i]);
      oneOfNum.push_back(oObj.getNumberVector()[i]);
   }

}

OneOfObjective* OneOfObjective::clone() const
{
  return new OneOfObjective(*this);
}

bool OneOfObjective::status (std::ostream& os, const std::vector <Course*>& coursesTaken) const
{
  for (unsigned int i = 0; i < coursesTaken.size(); i++)
    {
      for (unsigned int j = 0; j < oneOfDept.size(); j++)
	{
	  if (coursesTaken[i]->getNumber() == oneOfNum[j])
	    if (coursesTaken[i]->getDepartment() == oneOfDept[j])
	      {
		 os << oneOfDept[j] << ' ' << oneOfNum[j] << " has been taken from ";
		 write (os);
		 os << '.';
		return true;
	      }
	}
    }
  os << "None of the courses from ";
  write (os);
  os << " have been taken.";
  return false;
}

const bool OneOfObjective::isEqual(OneOfObjective* oObj) const
{
  const std::vector <std::string> oObjDept = oObj->getDeptVector();
  const std::vector <int> oObjNum = oObj->getNumberVector();
  for (unsigned int i = 0; i < oneOfNum.size(); i++)
    {
      if (oneOfNum[i] != oObjNum[i])
	return false;
      else if (oneOfDept[i] != oObjDept[i])
	return false;
    }
  return true;
}

std::vector <std::string> OneOfObjective::getDeptVector() const 
{
  return oneOfDept;
}

std::vector <int> OneOfObjective::getNumberVector() const
{
  return oneOfNum;
}

void OneOfObjective::read (std::istream& iStr)
{
  std::string deptStr;
  int number;
  while (iStr.peek() != '\n')
    {
      iStr >> deptStr >> number;
      oneOfDept.push_back(deptStr);
      oneOfNum.push_back(number);
    }
}
   
void OneOfObjective::write (std::ostream& os) const
{
  os << "One of: ";
  for (unsigned int i = 0; i < oneOfNum.size()-1; i++)
    {
       os << oneOfDept[i] << ' ' << oneOfNum[i] << ", ";
    }
  os << oneOfDept[oneOfNum.size()-1] << oneOfNum[oneOfNum.size()-1];
}
