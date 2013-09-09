/// \file
/// \brief An abstract base class to define the requirements of a major and track their completion status
/// \author Bradley Ellert 001133286
/// \date November 6, 2010

#ifndef SMBC_OBJECTIVE_H_
#define SMBC_OBJECTIVE_H_

#include <iostream>
#include <vector>

//#include "Course.h"
class Course;

/// \brief An abstract base class to define the requirements of a major and track their completion status
class Objective
{
  public:
   Objective() {}

   /// Return a pointer to a copy of this object
   //
   /// \return a pointer to a copy of the current Objective
   virtual Objective* clone() const = 0;

   virtual ~Objective() {}
   
   /// \brief Determines the objective's completion
   virtual bool status (std::ostream& os, const std::vector<Course*>& courseList) const = 0;

   virtual bool isEqual (Objective* o) {return false;}

   /// \brief Initializes the objective's members
   //
   /// Should be in the format: \n
   /// [type] [Objective] \n
   /// where [type] is: \n
   /// G for GLERObjective \n
   /// M for MinimumObjective \n
   /// O for OneOfObjective \n
   /// S for SingleObjective
   virtual void read (std::istream& iStr) = 0;
   
   /// \brief Writes the objective to the ostream
   virtual void write (std::ostream& os) const = 0;

   /// \brief Overloads the input stream operator for all Objectives
   virtual std::istream& operator>> (std::istream& is) {
      read(is);
      return is;
   }

   /// \brief Overloads the output stream operator for all Objectives
   virtual std::ostream& operator<< (std::ostream& os) const {
      write(os);
      return os;
   }
   
};

#endif
