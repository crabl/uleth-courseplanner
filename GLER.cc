#include "GLER.h"

std::istream& operator>> (std::istream& iStr, GLER& g) throw (InvalidGLER)
{
   std::string s;
   iStr >> s;
   if (s == "SCIENCE")
      g = SCIENCE;
   else if (s == "SOCIAL_SCIENCE")
      g = SOCIAL_SCIENCE;
   else if (s == "FINE_ARTS_HUMANITY")
      g = FINE_ARTS_HUMANITY;
   else
      throw InvalidGLER("Invalid GLER");
   return iStr;
}

std::ostream& operator<< (std::ostream& os, const GLER& g)
{
   switch (g)
   {
      case SCIENCE:
	 os << "science";
	 break;
      case SOCIAL_SCIENCE:
	 os << "social science";
	 break;
      case FINE_ARTS_HUMANITY:
	 os << "fine art and humanity";
	 break;
   }
   return os;
}

