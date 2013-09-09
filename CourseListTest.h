/// \file
/// \brief Unit tests for the CourseList class
/// \author Christopher Rabl 001051542
/// \date November 30, 2010

#ifndef SMBC_COURSELISTTEST_H_
#define SMBC_COURSELISTTEST_H_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <fstream>

#include "Exceptions.h"

#include "CourseList.h"

/// class to test functionality of the CourseList class
class CourseListTest : public CppUnit::TestFixture {

      /// macros to create the test suite
      CPPUNIT_TEST_SUITE(CourseListTest);
      CPPUNIT_TEST(testRead);
      CPPUNIT_TEST(testFind);
      CPPUNIT_TEST(testSingleton);
      CPPUNIT_TEST_SUITE_END();

   public:
      void setUp();             ///< override \c setUp to create variable
      void tearDown();          ///< override \c tearDown to clean up
            
      void testRead();
      void testFind();
      void testSingleton();
   private :
      CourseList* allCourses;
};

#endif
