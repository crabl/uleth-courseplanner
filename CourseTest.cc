/// \file
/// \brief Tests the member functions of Course to ensure proper functionality
/// \author Christopher Rabl 001051542
/// \date November 22, 2010

#include "CourseTest.h"

/// Create some variables to test with
void CourseTest::setUp() {
  validCourse = new Course;
  invalidCourse = new Course;
  tempCourse = new Course;
}

/// Free space used by allocated variables
void CourseTest::tearDown() {
  delete validCourse;
  delete invalidCourse;
  delete tempCourse;
}

void CourseTest::testCourseRead() {

  std::ifstream validData("TestData/ValidNoPrereq.course");
  std::ifstream validDataPrereq("TestData/ValidPrereq.course");
  std::ifstream invalidData("TestData/Invalid.course");

  /// Checking courses without prerequisites are read properly
  validCourse->read(validData);
  delete validCourse;

  /// Checking courses with prerequisites are read properly; destroyed in tearDown
  validCourse = new Course;
  //validCourse->read(validDataPrereq);

  /// Checks that invlid data cannot be read into a course
  CPPUNIT_ASSERT_THROW(invalidCourse->read(invalidData), InvalidFile);
  
}

void CourseTest::testCourseWrite() {

   std::ifstream validData("TestData/ValidNoPrereq.course");
   validCourse->read(validData);
   
   std::stringstream output;
   output << validCourse;

  
}

void CourseTest::testCourseAccessors() {
   std::ifstream validData("TestData/ValidPrereq.course");
   validCourse->read(validData);
   
  CPPUNIT_ASSERT(validCourse->getDepartment() == "CPSC");
  CPPUNIT_ASSERT(validCourse->getNumber() == 2620);
  CPPUNIT_ASSERT(validCourse->getTitle() == "Fundamentals of Programming II");
  CPPUNIT_ASSERT(validCourse->getDescription() == "Introduction to object-oriented programming techniques: classes, objects, and methods. Generic programming. Recursion. Abstract data types: lists, stacks, queues, priority queues, binary trees. Algorithms for searching and sorting, and algorithm analysis.");
  CPPUNIT_ASSERT(validCourse->getGler() == SCIENCE);
}
