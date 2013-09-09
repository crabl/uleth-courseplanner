/// \file
/// \brief 
/// \author Christopher Rabl 001051542
/// \date November 22, 2010

#include "GLERObjectiveTest.h"

void GLERObjectiveTest::initCourseVectors()
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
void GLERObjectiveTest::setUp()
{
  GLER science = SCIENCE;
  GLER fineArts = FINE_ARTS_HUMANITY;

  scienceObjective = new GLERObjective(science);
  fineArtsObjective = new GLERObjective(fineArts);
  invalidObjective = new GLERObjective;

  initCourseVectors();
}

/// Free space used by allocated variables
void GLERObjectiveTest::tearDown()
{
   delete scienceObjective;
   delete fineArtsObjective;
   delete invalidObjective;
}

void GLERObjectiveTest::testStatus()
{
   
}

void GLERObjectiveTest::testRead()
{
   std::stringstream inputStream;
   inputStream << "InvalidGLER";
   
   CPPUNIT_ASSERT_THROW(invalidObjective -> read(inputStream), InvalidGLER);
}

void GLERObjectiveTest::testWrite()
{
   std::stringstream output;
   scienceObjective -> write(output);

   CPPUNIT_ASSERT(output.str() == "4 science GLERs");
}
