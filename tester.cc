/// \file
/// Main program to run test suites
#include <cppunit/TextTestRunner.h>

#include "CourseTest.h"
#include "CourseListTest.h"
#include "FortyCoursesObjectiveTest.h"
#include "GLERTest.h"
#include "GLERObjectiveTest.h"
#include "MajorTest.h"
#include "MajorListTest.h"
#include "MinimumObjectiveTest.h"
#include "OneOfObjectiveTest.h"
#include "PlanTest.h"
#include "SingleObjectiveTest.h"
#include "StudentTest.h"

/// The simple main function to run the test suites
int main()
{
   CppUnit::TextTestRunner runner;
   runner.addTest(CourseTest::suite());
   runner.addTest(CourseListTest::suite());
   runner.addTest(FortyCoursesObjectiveTest::suite());
   runner.addTest(GLERTest::suite());
   runner.addTest(GLERObjectiveTest::suite());
   runner.addTest(MajorTest::suite());
   runner.addTest(MajorListTest::suite());
   runner.addTest(MinimumObjectiveTest::suite());
   runner.addTest(OneOfObjectiveTest::suite());
   runner.addTest(PlanTest::suite());
   runner.addTest(SingleObjectiveTest::suite());
   runner.addTest(StudentTest::suite());
   runner.run();

   return 0;
}
