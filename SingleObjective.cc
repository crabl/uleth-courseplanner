/// \file
/// \brief An objective requiring one, specific course to be completed
/// \author Bradley Ellert 001133286
/// \date November 22, 2010

#include "SingleObjective.h"

SingleObjective* SingleObjective::clone() const
{
  return new SingleObjective(*this);
}

SingleObjective::SingleObjective (const SingleObjective& sObj)
{
   singDepartment = sObj.getDept();
   singNumber = sObj.getNumber();
}

bool SingleObjective::status (std::ostream& os, const std::vector <Course*>& coursesTaken) const
{
   for (unsigned int i = 0; i < coursesTaken.size(); i++ )
   {
      if (coursesTaken[i]->getNumber() == singNumber)
	 if(coursesTaken[i]->getDepartment() == singDepartment)
	 {
	    os << singDepartment << " " << singNumber << " has been taken.";
	    return true;
	 }
   }
   os << singDepartment << " " << singNumber << " has not been taken yet.";
   return false;
}

const bool SingleObjective::isEqual(SingleObjective* sObj) const
{
  if (singDepartment == sObj->getDept())
    if (singNumber == sObj->getNumber())
      return true;
  return false;
}

std::string SingleObjective::getDept() const 
{
  return singDepartment;
}

int SingleObjective::getNumber() const
{
  return singNumber;
}

void SingleObjective::read (std::istream& iStr)
{
  iStr >> singDepartment >> singNumber;
}
   
void SingleObjective::write (std::ostream& os) const
{
  os << singDepartment << " " << singNumber;
}

