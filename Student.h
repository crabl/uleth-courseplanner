/// \file
/// \brief A class to represent a student's course status
/// \author Bradley Ellert 001133286
/// \date November 6, 2010

#ifndef SMBC_STUDENT_H_
#define SMBC_STUDENT_H_

#include <iostream>
#include <sstream>
#include <vector>

#include "Exceptions.h"

#include "Course.h"
#include "Major.h"

/// \brief A class to represent a student's course status
class Student
{
  public:
   //Student() : studentMajor(NULL) {}
   Student (Major* m = NULL) : studentMajor(m) {}

   ~Student() {}
      
   /// \brief Returns a pointer to the student's major
   Major* getMajor () const;

   /// \brief Returns the vector of course pointers
   const std::vector <Course*> getCourses () const;

   /// \brief Prints the student's members
   void write (std::ostream& os) const;
   
   /// \brief Changes the student's major
   void changeMajor (Major* m);

   /// \brief Adds a pointer to a course in cl to coursesTaken
   void addCourse (Course* c) throw (CourseAlreadyExists);

   /// \brief Removes the pointer to c from coursesToTake
   void removeCourse(const Course* c) throw (CourseNotFound);

   /// \brief Calls major's status function with coursesTaken
   bool status (std::ostream& os) const;

   /// \brief Call's c's Objectives' statuses with coursesTaken
   bool canTake (const Course* c) const;

  private:
   /// The student's major
   Major* studentMajor;

   /// A vector of pointers to the courses completed
   std::vector <Course*> coursesTaken;
};

/// Overload the insertion operator
// This is a non-member function
std::ostream& operator<< (std::ostream& os, const Student& s);

#endif
