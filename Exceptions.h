/// \file
/// \brief Exception library for the application
/// \author Christopher Rabl 001051542, Steven Henke 001141476
/// \date November 9, 2010

#ifndef SMBC_EXCEPTIONS_H_
#define SMBC_EXCEPTIONS_H_

#include <stdexcept>
#include <string>

using std::runtime_error;

/// Exception class to handle invalid file names
class InvalidFile : public runtime_error {
  public:
   ///Constructor
   //
   /// \param arg the message to be displayed
   InvalidFile(const std::string& arg) : runtime_error(arg) {}
};

/// Exception class to handle invalid student names
class StudentNotFound : public runtime_error {
  public:
   /// Constructor
   //
   /// \param arg the message to be displayed
   StudentNotFound(const std::string& arg) : runtime_error(arg) {}
};

/// Exception class to handle invalid course names
class CourseNotFound : public runtime_error {
  public:
   ///Constructor
   //
   /// \param arg the message to be displayed
   CourseNotFound(const std::string& arg) : runtime_error(arg) {}
};

/// Exception class to handle invalid Objectives
class InvalidObjective : public runtime_error {
 public:
  /// Constructor
  /// \param arg the message to be displayed
 InvalidObjective(const std::string& arg) : runtime_error(arg) {}
};

/// Exception thrown when a duplicate course is being read into a CourseList
class CourseAlreadyExists : public runtime_error {
 public:
  /// Constructor
  /// \param arg the message to be displayed
 CourseAlreadyExists(const std::string& arg) : runtime_error(arg) {}
};

/// Exception thrown when a duplicate major is being read into a MajorList
class MajorAlreadyExists : public runtime_error {
 public:
  /// Constructor
  /// \param arg the message to be displayed
 MajorAlreadyExists(const std::string& arg) : runtime_error(arg) {}
};

/// Exception thrown when an invalid GLER is encountered
class InvalidGLER : public runtime_error {
  public:
   /// Constructor
   /// \param arg the message to be displayed
   InvalidGLER(const std::string& arg) : runtime_error(arg) {}
};

/// Exception thrown when an invalid Plan is created or encountered
class InvalidPlan : public runtime_error {
  public:
   /// Constructor
   /// \param arg the message to be displayed
   InvalidPlan(const std::string& arg) : runtime_error(arg) {}
};

#endif
