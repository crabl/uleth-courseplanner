/// \file
/// \brief 
/// \author Bradley Ellert 001133286
/// \date November 22, 2010

#ifndef SMBC_PLANTEST_H_
#define SMBC_PLANTEST_H_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "Plan.h"

/// class to test functionality of the Plan class
class PlanTest : public CppUnit::TestFixture {

   /// macros to create the test suite
   CPPUNIT_TEST_SUITE(PlanTest);
   CPPUNIT_TEST(testGetMajor);
   CPPUNIT_TEST(testGetCourses);
   CPPUNIT_TEST(testWrite);
   CPPUNIT_TEST(testChangeMajor);
   CPPUNIT_TEST(testAddCourse);
   CPPUNIT_TEST(testRemoveCourse);
   CPPUNIT_TEST(testStatus);
   CPPUNIT_TEST(testCanTake);
   CPPUNIT_TEST(testCommitChanges);
   CPPUNIT_TEST(testCombineVectors);
   CPPUNIT_TEST_SUITE_END();

  public:
      void setUp();             ///< override \c setUp to create variable
      void tearDown();          ///< override \c tearDown to clean up
      void initCourseVectors();
      void testAddCourse();
      void testCanTake();
      void testChangeMajor();
      void testCombineVectors();
      void testCommitChanges();
      void testGetCourses();
      void testGetMajor();
      void testRemoveCourse();
      void testStatus();
      void testWrite();
     
   private :
      Student* moe;
      Student* larry;
      Student* curly;
      
      Major* compSci;
      Major* math;

      Plan* moePlan;
      Plan* larryPlan;
      Plan* curlyPlan;
      
      std::vector<Course*> courses1;
      std::vector<Course*> courses2;      

};

#endif
