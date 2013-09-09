/// \file
/// \brief A master list of majors
/// \author Bradley Ellert 001133286
/// \date November 6, 2010

#ifndef SMBC_MAJORLIST_H_
#define SMBC_MAJORLIST_H_

#include <fstream>
#include <string>
#include <vector>

#include "Exceptions.h"

#include "Major.h"

/// \brief A master list of majors
//
/// This class is a Singleton
class MajorList
{
  public:
   /// \brief Creates an instance if there isn't one or returns the only one
  static MajorList* getInstance ();

  /// \brief Destroys the singleton MajorList in memory
  void destroy();
  
   /// \brief Calls Major's read function for every major in the file
   //
   /// Should be in the format: \n
   /// M \n
   /// [major1] \n
   /// M \n
   /// [major2] \n
   /// ...
  void read (std::istream& iStr) throw(MajorAlreadyExists, InvalidFile);

  /// \brief Prints only the names of the majors
  void write (std::ostream& os) const;
  
   /// \brief Returns a pointer to a specified Major in majors
   Major* find (const std::string& title);

  private:
   /// A vector of majors pointers
   std::vector <Major*> majors;

   /// Instance of the MajorList and a flag to indicate whether an instance exists
   static MajorList* instance;
   static bool instanceCreated;

   // Private constructor, destructor, copy constructor, assignment operator
   MajorList () {}
   MajorList (const MajorList& m) { m.getInstance(); }
   MajorList* operator= (const MajorList& m) {return m.getInstance(); }
};

/// Overload the extraction operator
// This is a non-member function
std::istream& operator>> (std::istream& iStr, MajorList& ml);

/// Overload the insertion operator
// This is a non-member function
std::ostream& operator<< (std::ostream& os, const MajorList& ml);

#endif
