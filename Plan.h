/// \file
/// \brief Builds a potential future plan for a Student
/// \author Bradley Ellert 001133286
/// \date November 22, 2010

#ifndef SMBC_PLAN_H_
#define SMBC_PLAN_H_

#include <iostream>
#include <sstream>
#include <vector>

#include "Exceptions.h"

#include "Course.h"
#include "Major.h"
#include "Student.h"

/// \brief Builds a potential future plan for a Student
class Plan
{
  public:
   Plan (Student* s = NULL) : student (s), planMajor (NULL) {}
   
   ~Plan() {}

   /// \brief Returns a pointer to the plan's major
   Major* getMajor () const;

   /// \brief Returns the vector of course pointers
   std::vector <Course*> getCourses () const;

   /// \brief Prints the plan's members
   void write (std::ostream& os) const throw (InvalidPlan);
   
   /// \brief Changes the plan's major
   void changeMajor (Major* newMajor);

   /// \brief Adds a pointer to a course in cl to coursesToTake
   void addCourse (Course* newCourse) throw (CourseAlreadyExists);

   /// \brief Removes the pointer to c from coursesToTake
   void removeCourse(const Course* oldCourse);

   /// \brief Calls major's status function with coursesToTake and coursesTaken
   //
   /// Uses student's major if one is not defined
   bool status (std::ostream& os) const throw (InvalidPlan);

   /// \brief Calls c's Objectives' statuses with coursesToTake and coursesTaken
   //
   /// Uses student's major if one is not defined
   bool canTake (const Course* potentialCourse) const throw (InvalidPlan);

   /// \brief Updates the student's coursesTaken with the plan's coursesToTake
   void commitChanges() throw (InvalidPlan);

   /// \brief Combine the coursesTaken vector from student and coursesToTake
   std::vector <Course*> combineVectors() const throw (InvalidPlan);

  private:
   /// The student the plan is for
   Student* student;

   /// The plan's major
   Major* planMajor;

   /// A vector of pointers to the courses completed
   std::vector <Course*> coursesToTake;
};

/// Overload the insertion operator
// This is a non-member function
std::ostream& operator<< (std::ostream& os, const Plan& p);

#endif
