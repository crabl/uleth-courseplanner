/// \file
/// \brief Implementation of the unit tests for the CourseList class
/// \author Christopher Rabl
/// \date November 30, 2010

#include "CourseListTest.h"

/// Create some variables to test with
void CourseListTest::setUp() {
  allCourses = CourseList::getInstance();
}

/// Free space used by allocated variables
void CourseListTest::tearDown() {

}

void CourseListTest::testRead() {
  std::ifstream badFile("TestData/Bad.courses");

  CPPUNIT_ASSERT_THROW(allCourses->read(badFile), InvalidFile);

}

void CourseListTest::testFind() {

}

void CourseListTest::testSingleton() {
  CourseList* newList = CourseList::getInstance();
  CPPUNIT_ASSERT(newList == allCourses);
}
