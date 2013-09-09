/// \file
/// \brief The main objective for completing a generic major
/// \author Bradley Ellert 001133286
/// \date November 6, 2010

#ifndef SMBC_FORTYCOURSESOBJECTIVE_H_
#define SMBC_FORTYCOURSESOBJECTIVE_H_

#include <iostream>
#include <vector>

#include "Exceptions.h"

#include "Course.h"
#include "Objective.h"

/// \brief An objective requiring 40 courses to be taken
//
/// No more than 10 of which are 1000 level
/// No more than 20 from one department
/// A subclass of Objective
class FortyCoursesObjective : public Objective
{
  public:
   FortyCoursesObjective() {}
   ~FortyCoursesObjective() {}

   /// \brief Return a pointer to a cpy of this object
   //
   /// \return a pointer to a copy of the current Objective
   FortyCoursesObjective* clone() const;

   /// \brief Counts to see if there are at least 40 courses in coursesTaken
   //
   /// Not counting courses that exceed the 10 1000 level limit or the 20 per department limit
   bool status (std::ostream& os, const std::vector <Course*>& coursesTaken) const;
   
      
   /// \brief Initializes the objective's members
   //
   /// Does nothing in this case
   void read (std::istream& iStr) { }
   
   /// \brief Writes the objective to the ostream
   void write (std::ostream& os) const;

};

#endif
