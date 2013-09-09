/// \file
/// \brief 
/// \author Bradley Ellert 001133286
/// \date November 22, 2010

#ifndef SMBC_GLERTEST_H_
#define SMBC_GLERTEST_H_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "GLER.h"

/// class to test functionality of the GLER class
class GLERTest : public CppUnit::TestFixture {

      /// macros to create the test suite
      CPPUNIT_TEST_SUITE(GLERTest);
      CPPUNIT_TEST_SUITE_END();

   public:
      void setUp();             ///< override \c setUp to create variable
      void tearDown();          ///< override \c tearDown to clean up
            
   private :
      
};

#endif
