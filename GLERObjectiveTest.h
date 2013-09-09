/// \file
/// \brief 
/// \author Bradley Ellert 001133286 Christopher Rabl 001051542 Steven Henke 001141476
/// \date November 22, 2010

#ifndef SMBC_GLEROBJECTIVETEST_H_
#define SMBC_GLEROBJECTIVETEST_H_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include <iostream>
#include <sstream>
#include <vector>

#include "Course.h"
#include "GLERObjective.h"

/// class to test functionality of the GLERObjective class
class GLERObjectiveTest : public CppUnit::TestFixture {

      /// macros to create the test suite
      CPPUNIT_TEST_SUITE(GLERObjectiveTest);
      CPPUNIT_TEST(testStatus);
      CPPUNIT_TEST(testRead);
      CPPUNIT_TEST(testWrite);
      CPPUNIT_TEST_SUITE_END();

  public:
      void initCourseVectors(); ///< Creates test courses to use.
      void setUp();             ///< override \c setUp to create variable
      void tearDown();          ///< override \c tearDown to clean up
      void testStatus();        ///< Tests the status function for GLER
      void testRead();          ///< Tests read function
      void testWrite();         ///< Tests write function
 private:
      std::vector<Course*> courses1;
      std::vector<Course*> courses2;
      GLERObjective* scienceObjective;
      GLERObjective* fineArtsObjective;
      GLERObjective* invalidObjective;

};

#endif
