/// \file
/// \brief A master list of courses
/// \author Bradley Ellert 001133286
/// \date November 6, 2010

#ifndef SMBC_COURSELIST_H_
#define SMBC_COURSELIST_H_

#include <fstream>
#include <vector>

#include "Exceptions.h"

#include "Course.h"

/// \brief A master list of courses
//
/// This class is a Singleton
class CourseList
{
  public:   
   /// \brief Creates an instance if there isn't one or returns the only one
   static CourseList* getInstance();

   /// \brief Destroys a CourseList when it is no longer needed
   void destroy();
   
   /// \brief Calls Course's read function for every Course in the file
   //
   /// Should be in the format: \n
   /// C \n
   /// [Course1] \n
   /// C \n
   /// [Course2] \n
   /// ...
  void read(std::istream& iStr) throw(CourseAlreadyExists, InvalidFile);

  /// \brief Prints only the departments and numbers of the coursess
  void write(std::ostream& os) const;
  
   /// \brief Searches for a specified Course in the vector of Courses
   /// \return A pointer to a Course
   Course* find(const std::string& department, const int& number);

  private:
   /// Private constructor, destructor, copy constructor, assignment operator
   std::vector<Course*> courses;

   /// Instance of the CourseList and a flag to indicate if an instance already exists
   static CourseList* instance;
   static bool instanceCreated;

   CourseList() {}
   CourseList(const CourseList& c) { c.getInstance(); }
   CourseList* operator=(const CourseList& c) { return c.getInstance(); }
};

/// Overload the extraction operator
// This is a non-member function
std::istream& operator>> (std::istream& iStr, CourseList& cl);

/// Overload the insertion operator
// This is a non-member function
std::ostream& operator<<(std::ostream& os, const CourseList& cl);

#endif
