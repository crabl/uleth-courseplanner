/// \file
/// \brief An objective requiring a single Course out of a list of Courses to be completed
/// \author Bradley Ellert 001133286
/// \date November 6, 2010

#ifndef SMBC_ONEOFOBJECTIVE_H_
#define SMBC_ONEOFOBJECTIVE_H_

#include <iostream>
#include <vector>

#include "Exceptions.h"

#include "Course.h"
#include "Objective.h"

/// \brief An objective requiring a single Course out of a list of Courses to be completed
//
/// This is a subclass of Objective
class OneOfObjective : public Objective
{
  public:
   OneOfObjective () {}
   OneOfObjective (const OneOfObjective& oObj);
   ~OneOfObjective () {}

   /// Return of a copy of the Objective
   OneOfObjective* clone() const; 

   /// \brief Compares coursesTaken to oneOf until one match is found
   bool status (std::ostream& os, const std::vector <Course*>& coursesTaken) const;

   /// \brief equalilty test between two OneOfObjectives
   const bool isEqual(OneOfObjective* oObj) const;

   /// \brief Returns the vector of departments
   std::vector <std::string> getDeptVector() const;

   /// \brief Returns the vector of course numbers
   std::vector <int> getNumberVector() const;

   /// \brief Initializes the objective's members
   //
   /// Should be in the format: \n
   /// [dept1] [number1] [dept2] [number2] ... \n
   void read (std::istream& iStr);
   
   /// \brief Writes the objective to the ostream
   void write (std::ostream& os) const;

  private:
   /// A vector of departments and a vecor of course numbers
   std::vector <std::string> oneOfDept;
   std::vector <int> oneOfNum;
};

#endif
