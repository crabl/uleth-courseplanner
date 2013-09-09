/// \file
/// \brief A class to represent a University of Lethbridge course
/// \author Bradley Ellert 001133286
/// \date November 6, 2010

#ifndef SMBC_COURSE_H_
#define SMBC_COURSE_H_

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "Exceptions.h"

#include "Course.h"
#include "GLER.h"
#include "Objective.h"
#include "OneOfObjective.h"
#include "SingleObjective.h"

//class Objective; ///< Forward declaration of Objective to work around "cyclic inclusion" bug

/// \brief A class to represent a University of Lethbridge course
class Course
{
  public:

   /// \brief Constructor for the Course class
   Course () {}

   /// \brief Copy constructor for the Course class.
   Course(const Course& cObj);

   ~Course();
   
   /// \brief Clone function
   /// \return A copy of this course.
   Course* clone();
   
   /// \brief Accessor function for GLER category
   /// \return The course's GLER
   const GLER getGler () const;

   /// \brief Accessor function for std::string department
   /// \return The course's department
   const std::string getDepartment () const;

   /// \brief Accessor function for unsigned short number
   /// \return The course's number
   int getNumber () const;

   /// \brief Accessor functino for vector of prerequisites
   /// \return The vector of prerequisites
   const std::vector <Objective*> getPrerequisites() const;

   /// \brief Accessor function for title
   /// \return The title of the course
   const std::string getTitle() const;

   /// \brief Accessor function for descriptino
   /// \return The description of the course
   const std::string getDescription() const;

   /// \brief Checks if course is already in the vector.
   /// \return true if the course is in the vector, false otherwise.
   bool hasTaken (std::vector <Course*> courseVector) const;

   /// \brief Initializes the course's members
   //
   /// Should be in the format: \n
   /// [department] [number] \n
   /// [title] \n
   /// [description] \n
   /// [GLER category] \n
   /// P [tag of objective] [prerequisite1] \n
   /// P [tag of objective] [prerequisite2] \n
   /// ... \n
   void read (std::istream& iStr) throw (InvalidFile);

   /// \brief Prints the course's members
   void write (std::ostream& os) const;
   
  private:
   /// Must be completed before taking a course
   /// As for this being a vector of Objective pointers, cyclic dependency is "fixed"
   /// by simply providing a forward declaration of Objective instead of including the file.
   std::vector <Objective*> prerequisites;

   /// One of SCIENCE, SOCIAL_SCIENCE, or FINE_ARTS_HUMANITY
   GLER category;

   /// The course's name (e.g. Practical Software Design)
   std::string title;

   /// A short abstract about the course's material
   std::string description;

   /// The department the course in (e.g. CPSC)
   std::string department;

   /// The course's ID (e.g. 2720)
   unsigned short number;
};

/// Overload the extraction operator
// This is a non-member function
std::istream& operator>>(std::istream& iStr, Course& c);

/// Overload the insertion operator
// This is a non-member function
std::ostream& operator<<(std::ostream& os, const Course& c);

/// Overload the equality test operator
// This is a non-member function
const bool operator==(const Course& firstCourse, const Course& secondCourse);

#endif
