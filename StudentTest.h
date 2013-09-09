/// \file
/// \brief 
/// \author Bradley Ellert 001133286
/// \date November 22, 2010

#ifndef SMBC_STUDENTTEST_H_
#define SMBC_STUDENTTEST_H_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include <iostream>
#include <sstream>
#include <vector>

#include "Student.h"

/// class to test functionality of the Student class
class StudentTest : public CppUnit::TestFixture {

   /// macros to create the test suite
   CPPUNIT_TEST_SUITE(StudentTest);
   CPPUNIT_TEST(testGetMajor);
   CPPUNIT_TEST(testGetCourses);
   CPPUNIT_TEST(testWrite);
   CPPUNIT_TEST(testChangeMajor);
   CPPUNIT_TEST(testAddCourse);
   CPPUNIT_TEST(testRemoveCourse);
   CPPUNIT_TEST(testStatus);
   CPPUNIT_TEST(testCanTake);
   CPPUNIT_TEST_SUITE_END();

   public:
      void setUp();             ///< override \c setUp to create variable
      void tearDown();          ///< override \c tearDown to clean up

      /// \brief Adds some sample Course data to some vectors so that we can initialize a Student
      void initCourseVectors();

      /// \brief Tests that the Student::addCourse function throws the correct exceptions, if applicable
      void testAddCourse();

      /// \brief Tests that a Student either can or cannot take a given course
      void testCanTake();

      /// \brief Tests that it is possible for a Student to change his or her major
      void testChangeMajor();

      /// \brief Tests that the Courses that the Student has taken correspond exactly to the Courses that were added
      void testGetCourses();

      /// \brief Tests that the Student will return its correct Major
      void testGetMajor();

      /// \brief Tests that a Course can be removed from the Student
      void testRemoveCourse();

      /// \brief Tests that the status of the Student is correct after adding some Courses, or changing the Major, and so on
      void testStatus();

      /// \brief Tests that the correct information is written to the output stream when Student::write is called
      void testWrite();
     
   private :
      Student* moe;
      Student* larry;
      Student* curly;
      
      Major* compSci;
      Major* math;

      std::vector<Course*> courses1;
      std::vector<Course*> courses2;
};

#endif
