/// \file
/// \brief A class to represent a University of Lethbridge major
/// \author Bradley Ellert 001133286
/// \date November 22, 2010

#include "Major.h"

// Make a copy of the data in the Major
//
/// \param orig imports the Major to make a copy of
void Major::copy(const Major& orig)
{
  title = orig.title;
  for (unsigned int i = 0; i < orig.objectives.size(); i++)
  {
    objectives.push_back(orig.objectives[i]->clone() );
  }
}

Major::Major (Major& m)
{
  copy(m);
}

Major::~Major()
{
   for (unsigned int i = 0; i < objectives.size(); i++)
   {
      delete objectives[i];
      objectives[i] = NULL;
   }
}

void Major::read (std::istream& iStr)
{
   try {
      getline (iStr, title);
      objectives.push_back (new FortyCoursesObjective);
      objectives.push_back (new GLERObjective (SCIENCE));
      objectives.push_back (new GLERObjective (SOCIAL_SCIENCE));
      objectives.push_back (new GLERObjective (FINE_ARTS_HUMANITY));
      while (iStr.peek () == 'P')
      {
	 iStr.ignore ();
	 iStr.ignore ();
	 Objective* objective;
	 switch (iStr.peek ())
	 {
	    case 'S':
	    {
	       objective = new SingleObjective;
	       break;
	    }
	    case 'O':
	    {
	       objective = new OneOfObjective;
	       break;
	    }
	    case 'L':
	    {
	       objective = new MinimumObjective;
	       break;
	    }
	    default:
	    {
	       throw InvalidObjective("Reading objective from course file failed!");
	       break;
	    }
	 }
	 iStr.ignore ();
	 objective -> read (iStr);
	 objectives.push_back (objective);
	 iStr.ignore ();
      }
   } catch (std::exception& e) {
      throw InvalidFile("Reading course file failed!");
   }
}

void Major::write (std::ostream& os) const
{
   os << "Major: " << title << std::endl;
   os << "Objectives: " << std::endl;
   for (unsigned int i = 0; i < objectives.size (); ++i)
   {
      objectives [i] -> write (os);
      os << std::endl;
   }
}

bool Major::status (std::ostream& os, const std::vector <Course*>& coursesTaken) const
{
   bool completed = true;
   for (unsigned int i = 0; i < objectives.size (); ++i)
   {
      if (!objectives [i] -> status (os, coursesTaken))
	 completed = false;
      os << std::endl;
   }
   return completed;
}

const std::string& Major::getTitle() const
{
  return title;
}

std::istream& operator>> (std::istream& iStr, Major& m)
{
  m.read(iStr);
  return iStr;
}

std::ostream& operator<< (std::ostream& os, const Major& m)
{
  m.write(os);
  return os;
}
