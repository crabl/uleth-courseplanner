/// \file
/// \brief An objective requiring one, specific course to be completed
/// \author Bradley Ellert 001133286
/// \date November 6, 2010

#ifndef SMBC_SINGLEOBJECTIVE_H_
#define SMBC_SINGLEOBJECTIVE_H_

#include <iostream>
#include <vector>

#include "Exceptions.h"

#include "Course.h"
#include "Objective.h"

/// \brief An objective requiring one, specific course to be completed
//
/// A subclass of Objective
class SingleObjective : public Objective
{
  public:
   SingleObjective() {}
   SingleObjective(const SingleObjective& sObj);
   ~SingleObjective() {}

   /// Return a copy of the Objective
   SingleObjective* clone() const;

   /// \brief Searches for course in coursesTaken
   bool status (std::ostream& os, const std::vector <Course*>& coursesTaken) const;

   /// \brief equality test between two SingleObjectives
   const bool isEqual(SingleObjective* sObj) const;

   /// \brief Returns the department
   std::string getDept() const;

   /// \brief Returns the course number
   int getNumber() const;

   /// \brief Initializes the objective's members
   //
   /// Should be in the format: \n
   /// [department] [number]
   void read (std::istream& iStr);
   
   /// \brief Writes the objective to the ostream
   void write (std::ostream& os) const;

  private:
   /// The department and course number
   std::string singDepartment;
   int singNumber;
};



#endif
