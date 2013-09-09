/// \file
/// \brief An enumerated data type, either SCIENCE, SOCIAL_SCIENCE, or FINE_ARTS_HUMANITY
/// \author Bradley Ellert 001133286
/// \date November 6, 2010


#ifndef SMBC_GLER_H_
#define SMBC_GLER_H_

#include "Exceptions.h"

#include <iostream>

/// \brief Defines the GLER categories; used in all Courses
enum GLER { SCIENCE, SOCIAL_SCIENCE, FINE_ARTS_HUMANITY };

/// Overload the extraction operator
std::istream& operator>> (std::istream& iStr, GLER& g) throw (InvalidGLER);

/// Overload the insertion operator
std::ostream& operator<< (std::ostream& os, const GLER& g);

#endif
