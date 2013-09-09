 /// \file
/// \brief 
/// \author Bradley Ellert 001133286
/// \date November 22, 2010

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "PlanTest.h"

void PlanTest::initCourseVectors()
{
   std::stringstream cpsc1620;
   cpsc1620 << "CPSC 1620\n"
	    << "Fundamentals of Programming I\n"
	    << "Introduction to problem-solving and algorithms. Machine representation of data. Implementation of algorithms in a programming language.\n"
	    << "SCIENCE\n";

   std::stringstream math1410;
   math1410 << "MATH 1410" << std::endl
	    << "Linear Algebra" << std::endl
	    << "Linear systems and matrices. Matrix algebra. Determinants. Vector geometry. Complex numbers. Markov chains and other applications" << std::endl
	    << "SCIENCE" << std::endl;

   std::stringstream hist1000;
   hist1000 << "HIST 1000" << std::endl
	    << "Western Civilization" << std::endl
	    << "Survey of selected historical developments in the Western world." << std::endl
	    << "FINE_ARTS_HUMANITY" << std::endl;

   std::stringstream bask1000;
   bask1000 << "BASK 1000" << std::endl
	    << "Introduction to Basket Weaving" << std::endl
	    << "Basic weaving techniques involving various materials. History of baskets." << std::endl
	    << "FINE_ARTS_HUMANITY" << std::endl;

   std::stringstream bask2000;
   bask2000 << "BASK 2000" << std::endl
	    << "Underwater Basket Weaving" << std::endl
	    << "Advanced basket weaving techniques involving submersion in a large tank of water." << std::endl
	    << "FINE_ARTS_HUMANITY" << std::endl
	    << "P S BASK 1000" << std::endl;

   std::stringstream bask2666;
   bask2666 << "BASK 2666" << std::endl
	    << "Underwater Synchronized Basket Weaving" << std::endl
	    << "Techniques and applications of weaving baskets in an underwater group environment." << std::endl
	    << "FINE_ARTS_HUMANITY" << std::endl
	    << "P S BASK 2000" << std::endl;

   Course* sci1 = new Course;
   sci1 -> read (cpsc1620);

   Course* sci2 = new Course;
   sci2 -> read (math1410);

   Course* fah1 = new Course;
   fah1 -> read (hist1000);

   Course* fah2 = new Course;
   fah2 -> read (bask1000);

   Course* fah3 = new Course;
   fah3 -> read (bask2000);

   Course* fah4 = new Course;
   fah4 -> read (bask2666);


   courses1.push_back(sci1);
   courses1.push_back(sci2);
   courses1.push_back(fah1);
   courses1.push_back(fah2);
   
   courses2.push_back(sci2);
   courses2.push_back(fah1);
   courses2.push_back(fah2);
   courses2.push_back(fah3);
   courses2.push_back(fah4);

}

/// Create some variables to test with
void PlanTest::setUp() {
   std::ifstream csFile("TestData/CompSci.major");
   std::ifstream mathFile("TestData/Math.major");
   
   compSci = new Major;
   compSci -> read(csFile);

   math = new Major;
   math -> read(mathFile);

   moe = new Student(math);
   larry = new Student(compSci);
   curly = new Student(math);

   initCourseVectors();

   moePlan = new Plan(moe);
   larryPlan = new Plan(larry);
   curlyPlan = new Plan;
}

/// Free space used by allocated variables
void PlanTest::tearDown() {
   delete moe;
   delete larry;
   delete curly;
   
   delete math;
   delete compSci;

   delete moePlan;
   delete larryPlan;
   delete curlyPlan;
}

void PlanTest::testAddCourse()
{
   moePlan -> addCourse(courses2[0]); // Should add MATH 1410 to Moe
   CPPUNIT_ASSERT_THROW(moePlan -> addCourse(courses2[0]), CourseAlreadyExists); // Should say that Moe is not allowed to take that course again
   
}

void PlanTest::testCanTake()
{
   CPPUNIT_ASSERT(larryPlan -> canTake(courses2[2]) == true); // Larry can take Basket Weaving 1000 since it has no prerequisites
   CPPUNIT_ASSERT(larryPlan -> canTake(courses2[4]) == false); // Larry cannot take Basket Weaving 2666 since he has not taken Basket Weaving 2000
   
   larryPlan -> addCourse(courses2[2]);
   
   CPPUNIT_ASSERT(larryPlan -> canTake(courses2[3]) == true); // Larry can take Basket Weaving 2000 now
   CPPUNIT_ASSERT(larryPlan -> canTake(courses2[4]) == false); // He still can't take BASK 2666 though
   
   larryPlan -> addCourse(courses2[3]);
   
   CPPUNIT_ASSERT(larryPlan -> canTake(courses2[4]) == true); // Now he can take BASK 2666, Larry's dream is now a reality!
   CPPUNIT_ASSERT(larryPlan -> canTake(courses2[2]) == false); // Poor Larry can't find a job, so he wants to take BASK 1000 again, but he can't. He will just have to find something else to do with his useless degree...

   CPPUNIT_ASSERT_THROW(curlyPlan -> canTake(courses2[0]), InvalidPlan);
}

void PlanTest::testChangeMajor()
{

}

void PlanTest::testGetCourses()
{
   moePlan -> addCourse(courses1[0]);
   moePlan -> addCourse(courses1[1]);
   moePlan -> addCourse(courses1[2]);
   moePlan -> addCourse(courses1[3]);

   CPPUNIT_ASSERT(moePlan -> getCourses() == courses1);
   CPPUNIT_ASSERT(moePlan -> getCourses().size() == 4);
   CPPUNIT_ASSERT(curlyPlan -> getCourses().size() == 0);

   larryPlan -> addCourse(courses2[0]);
   CPPUNIT_ASSERT(larryPlan -> getCourses().size() == 1);

   larryPlan -> addCourse(courses2[1]);
   CPPUNIT_ASSERT(larryPlan -> getCourses().size() == 2);

   CPPUNIT_ASSERT(larryPlan -> getCourses() != courses2);
   
}


void PlanTest::testGetMajor()
{
   CPPUNIT_ASSERT(moePlan -> getMajor() == math);
   CPPUNIT_ASSERT(larryPlan -> getMajor() == compSci);
   CPPUNIT_ASSERT(curlyPlan -> getMajor() == NULL);
}


void PlanTest::testRemoveCourse()
{

}

void PlanTest::testStatus()
{

}

void PlanTest::testWrite()
{

}

void PlanTest::testCommitChanges()
{

}

void PlanTest::testCombineVectors()
{

}


