/// \file
/// \brief An Objective requiring a given number of courses at a particular level to be completed
/// \author Bradley Ellert 001133286
/// \date November 6, 2010

#ifndef SMBC_MINIMUMOBJECTIVE_H_
#define SMBC_MINIMUMOBJECTIVE_H_

#include <iostream>
#include <string>
#include <vector>

#include "Exceptions.h"

#include "Course.h"
#include "Objective.h"

/// \brief An Objective requiring a given number of courses at a particular level to be completed
//
/// This is a subclass of Objective
class MinimumObjective : public Objective
{
  public:
   MinimumObjective() {}
   ~MinimumObjective() {}
   /// \brief Compares coursesTaken until n match the level of the objective
   bool status (std::ostream& os, const std::vector <Course*>& coursesTaken) const;

   /// \brief Initializes the objective's members
   //
   /// Should be in the format: \n
   /// [minCourses] [department] [level]
   void read (std::istream& iStr);
   
   /// \brief Writes the Objective to the ostream
   void write (std::ostream& os) const;

   MinimumObjective* clone() const;
   
  private:
   /// Minimum number of courses that must be taken
   unsigned int minCourses;
   
   /// Minimum level of courses to be taken
   /// \pre level must be a multiple of 1000.
   unsigned short level;
   
   /// Department of courses to be taken
   std::string department;
};

#endif
