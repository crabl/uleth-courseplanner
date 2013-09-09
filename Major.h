/// \file
/// \brief A class to represent a University of Lethbridge major
/// \author Bradley Ellert 001133286
/// \date November 6, 2010

#ifndef SMBC_MAJOR_H_
#define SMBC_MAJOR_H_

#include <iostream>
#include <string>
#include <vector>

#include "Exceptions.h"

#include "Objective.h"
#include "FortyCoursesObjective.h"
#include "GLERObjective.h"
#include "SingleObjective.h"
#include "MinimumObjective.h"
#include "OneOfObjective.h"


/// \brief A class to represent a University of Lethbridge major
class Major
{
  public:

   /// Make a copy of the data in the Major
   void copy (const Major& orig);

   Major() : title("") {}
      Major(Major& m);
      ~Major();
   
   /// \brief Initializes the Major's members
   //
   /// Should be in the format: \n
   /// [title] \n
   /// [objective1] \n
   /// [objective2] \n
   /// ...
   void read (std::istream& iStr);

   /// \brief Prints the Major's members
   void write (std::ostream& os) const;

   /// \brief Calls each Objective's status
   bool status (std::ostream& os, const std::vector <Course*>& coursesTaken) const;

   /// Get the title of the Major
   const std::string& getTitle() const;

  private:
   /// The Major's name
   std::string title;

   /// The list of Objectives which must be fulfilled to complete the Major
   std::vector <Objective*> objectives;
};

/// Overload the extraction operator
// This is a non-member function
std::istream& operator>> (std::istream& iStr, Major& m);

/// Overload the insertion operator
// This is a non-member function
std::ostream& operator<< (std::ostream& os, const Major& m);

#endif
