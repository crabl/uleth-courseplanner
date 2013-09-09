/// \file
/// \brief An objective requiring 4 of a particular GLER category to be taken
/// \author Bradley Ellert 001133286
/// \date November 6, 2010

#ifndef SMBC_GLEROBJECTIVE_H_
#define SMBC_GLEROBJECTIVE_H_

#include <vector>

#include "Exceptions.h"

#include "Course.h"
#include "GLER.h"
#include "Objective.h"

/// \brief An objective requiring 4 of a particular GLER category to be taken
//
/// A subclass of Objective
class GLERObjective : public Objective
{
  public:
   GLERObjective (GLER gler = SCIENCE) : glerType (gler) {}
      //~GLERObjective ();

   /// \brief Return a pointer to a cpy of this object
   //
   /// \return a pointer to a copy of the current Objective
   GLERObjective* clone () const;
   
   /// \brief Compares gler in coursesTaken to see if 4 match gler
   bool status (std::ostream& os, const std::vector <Course*>& coursesTaken) const;

    /// \brief Initializes the objective's members
   //
   /// Should be in the format: \n
   /// [glerType]
   void read (std::istream& iStr) throw (InvalidGLER);
   
   /// \brief Writes the objective to the ostream
   void write (std::ostream& os) const;
   
  private:
   /// One of SCIENCE, SOCIAL_SCIENCE, or FINE_ARTS_HUMANITY
   GLER glerType;
};

#endif
