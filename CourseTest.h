/// \file
/// \brief 
/// \author Christopher Rabl 001051542
/// \date November 30, 2010

#ifndef SMBC_COURSETEST_H_
#define SMBC_COURSETEST_H_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <fstream>
#include <iostream>
#include <sstream>

#include "Exceptions.h"

#include "Course.h"

/// class to test functionality of the Course class
class CourseTest : public CppUnit::TestFixture {

      /// macros to create the test suite
      CPPUNIT_TEST_SUITE(CourseTest);
      CPPUNIT_TEST(testCourseRead);
      CPPUNIT_TEST(testCourseWrite);
      CPPUNIT_TEST(testCourseAccessors);
      CPPUNIT_TEST_SUITE_END();

   public:
      void setUp();             ///< override \c setUp to create variable
      void tearDown();          ///< override \c tearDown to clean up
      
      /// Test the Course::read function to ensure that the correct exceptions are thrown
      /// when an invalid course is read
      void testCourseRead();

      /// \brief Test the Course::write function writes the correct data to the ostream
      void testCourseWrite();

      /// \brief Tests all the accessor functions in Course to ensure they return the correct information
      void testCourseAccessors();
   private :
      Course* validCourse;
      Course* invalidCourse;
      Course* tempCourse;
};

#endif
