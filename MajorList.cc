/// \file
/// \brief A master list of majors
/// \author Bradley Ellert 001133286 Christopher Rabl 001051542 Steven Henke 001141476
/// \date November 22, 2010

#include "MajorList.h"

// Initialize the static members
MajorList* MajorList::instance = NULL;
bool MajorList::instanceCreated = false;

/// This function removes all the Majors contained in the MajorList when the application exits.
/// It isn't even really necessary, because the only time that the MajorList should be deleted
/// is when the program terminates, and even then, without this function the operating system would
/// simply free the memory that was used by it anyway. So, *technically*, that is not a memory leak.
/// I am not going to naively say that it is never a memory leak, because some OSes don't free the
/// memory, so we'll include the destroy() function anyway. -CR
void MajorList::destroy() {
   unsigned int sizeMajors = majors.size();

   for(unsigned int i = 0; i < sizeMajors; ++i) {
      delete majors[i];
   }

   instance = NULL;
   instanceCreated = false;
}

/// \brief Gets the instance of the Major List
/// \return a pointer to the Major List Singleton
MajorList* MajorList::getInstance() {
  if(!instanceCreated)
    {
      instance = new MajorList();
      instanceCreated = true;
      return instance;
    }
  else
    {
      return instance;
    }
}

/// \brief Reads the data into the Major List
//
/// Each Major starts with the 'M' character, followed by the format
/// used for the Major class. 
void MajorList::read (std::istream& iStr) throw (MajorAlreadyExists, InvalidFile)
{
   try
   {
      while (iStr.peek () == 'M')
      {
	 iStr.ignore ();
	 iStr.ignore ();
	 Major* addingMajor = new Major;
	 iStr >> *addingMajor;
	 majors.push_back (addingMajor);
	 iStr.ignore ();
      }
   }
   catch (InvalidFile)
   {
      std::cout << "Error: Unable to read major list - an invalid major was detected" << std::endl;
   }

}

/// \brief Writes the major list to the ostream.
void MajorList::write (std::ostream& os) const
{
   os << "Available majors: ";
   for (unsigned int i = 0; i < majors.size () - 1; ++i)
      os << majors [i] -> getTitle () << ", ";
   os << majors [majors.size () - 1] -> getTitle () << std::endl;
}

/// \brief Finds the course in the major list matching title
Major* MajorList::find (const std::string& title)
{
   for (unsigned int i = 0; i < majors.size(); i++)
   {
     if (majors[i]->getTitle() == title)
       return majors[i];
   }
   return NULL;
}

/// \brief Overload of the >> operator for MajorList
std::istream& operator>> (std::istream& iStr, MajorList& ml) 
{
  ml.read(iStr);
  return iStr;
}

/// \brief Overload of the << operator for MajorList
std::ostream& operator<< (std::ostream& os, const MajorList& ml)
{
  ml.write(os);
  return os;
}

