/// \file
/// \brief 
/// \author Bradley Ellert 001133286
/// \date November 22, 2010

#ifndef SMBC_MAJORLISTTEST_H_
#define SMBC_MAJORLISTTEST_H_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "MajorList.h"

/// class to test functionality of the MajorList class
class MajorListTest : public CppUnit::TestFixture {

      /// macros to create the test suite
      CPPUNIT_TEST_SUITE(MajorListTest);
      CPPUNIT_TEST_SUITE_END();

   public:
      void setUp();             ///< override \c setUp to create variable
      void tearDown();          ///< override \c tearDown to clean up
            
   private :
      
};

#endif
