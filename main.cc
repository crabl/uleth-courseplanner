#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <sstream>

#include "CourseList.h"
#include "Major.h"
#include "MajorList.h"
#include "Plan.h"
#include "Student.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::map;
using std::string;
using std::istream;
using std::stringstream;

/// \brief Gets filenames from the user until a file is successfully opened
void openFile (ifstream& ifs);

/// \brief Gets the main menu choice and performs the corresponding action
//
/// \return false to quit
bool mainMenu (map <string, Student>& students, map <string, Plan>& plans);

/// \brief Gets the search menu choice and performs the corresponding action
//
/// \return false to cancel
bool searchMenu (map <string, Student>& students, map <string, Plan>& plans);

/// \brief Gets the student menu choice and performs the corresponding action
//
/// \return false to cancel
bool studentMenu (map <string, Student>& students, map <string, Plan>& plans);

/// \brief Gets the plan menu choice and performs the corresponding action
//
/// \return false to cancel
bool planMenu (map <string, Student>& students, map <string, Plan>& plans);

/// \brief Creates a Student and its corresponding Plan
void addStudentPlan (map <string, Student>& students, map <string, Plan>& plans);

/// \brief Adds a predefined Plan to a Student
void addPlanToStudent (map <string, Plan>& plans);

/// \brief Changes the major of a Student or a Plan
//
/// \pre Item must be either Student or Plan
template <typename Item>
void changeMajor (map <string, Item>& items);

/// \brief Adds a course to a Student of a Plan
//
/// \pre Item must be either Student or Plan
template <typename Item>
void addCourse (map <string, Item>& items);

/// \brief Shows the courses that a Student or Plan includes
template <typename Item>
void showCourses (map <string, Item>& items);

/// \brief Removes a course from a Student or a Plan
//
/// \pre Item must be either Student or Plan
template <typename Item>
void removeCourse(map <string, Item>& items);

/// \brief Outputs the objective completion status of a Student or a Plan
//
/// \pre Item must be either Student or Plan
template <typename Item>
void status (map <string, Item>& items);

/// \brief Determines the ability of a Student or a Plan to take a course
//
/// \pre Item must be either Student or Plan
template <typename Item>
void canTake (map <string, Item>& items);

/// \brief Finds a Student or Plan in a map of strings to Students or Plans
//
/// \pre Item must be either Student or Plan
template <typename Item>
Item* getStudentPlan (map <string, Item>& items);

/// \brief Finds a Course in the CourseList
Course* getCourse ();

/// \brief Finds a Major in the MajorList
Major* getMajor ();

/// \brief Clears all data from an input stream
void flushStream (istream& is);

int main ()
{
   cout << "Welcome to SMBC's University of Lethbridge course planning program!" << endl;
   
   // **************************************************
   // Initialize the CourseList with all the course data
   // **************************************************
   cout << "Please enter the name of the file containing the Course data: ";
   ifstream courseData;
   openFile (courseData);

   // Create a main CourseList
   CourseList* allCourses;
   allCourses = CourseList::getInstance();

   try {
      allCourses -> read (courseData);
   } catch (CourseAlreadyExists) {
     std::cout << "Error: Duplicate course detected in CourseList" << std::endl;
     return 0;
   } catch (InvalidFile) {
     std::cout << "Error: Invalid CourseList file" << std::endl;
     return 0;
   }

   courseData.close ();
   
   // *************************************************
   // Initialize the Major List with all the Major data
   // *************************************************
   cout << "Please enter the name of the file containing the Major data: ";
   ifstream majorData;
   openFile (majorData);

   // Create a main MajorList
   MajorList* allMajors;
   allMajors = MajorList::getInstance();
   allMajors -> read (majorData);
   
   majorData.close ();

   map <string, Student> students;
   map <string, Plan> plans;
   addStudentPlan (students, plans);
   do
   {
      cout << endl
	   << "1 Search Menu" << endl
	   << "2 Student Menu" << endl
	   << "3 Plan Menu" << endl
	   << "4 Quit" << endl
	   << endl;
   } while (mainMenu (students, plans));

   // Destroy the CourseList and MajorList when the program exits
   allCourses -> destroy ();
   allMajors -> destroy ();

   delete allCourses;
   delete allMajors;
   
   return 0;
}

void openFile (ifstream& ifs)
{
   string filename;
   flushStream (cin);
   getline (cin, filename);
   ifs.open (filename.c_str ());
   while (!ifs)
   {
      cout << "Invalid filename! Try again: ";
      cin >> filename;
      ifs.open (filename.c_str ());
   }
   return;
}

bool mainMenu (map <string, Student>& students, map <string, Plan>& plans)
{
   char choice;
   cin >> choice;
   switch (choice)
      {
	 case '1':
	    do
	    {
	       cout << endl
		    << "1 Course Query" << endl
		    << "2 Major Query" << endl
		    << "3 Student Query" << endl
		    << "4 Plan Query" <<endl
		    << "5 Cancel" << endl
		    << endl;
	    } while (searchMenu (students, plans));
	    break;
	 case '2':
	    do
	    {
	       cout << endl
		    << "1 Create New Student" << endl
		    << "2 Set a Student's Major" << endl
		    << "3 Add a Course to a Student" << endl
		    << "4 Remove a Course from a Student" << endl
		    << "5 Find out whether a Student can take a specific Course" << endl
		    << "6 Cancel" << endl
		    << endl;       
	    } while (studentMenu (students, plans));
	    break;
	 case '3':
	    do
	    {
	       cout << endl
		    << "1 Set a Plan's Major" << endl
		    << "2 Add a Course to a Plan" << endl
		    << "3 Remove a Course from a Plan" << endl
		    << "4 Find out whether a Plan can take a specific Course" << endl
		    << "5 Commit Plan to a Student" << endl
		    << "6 Cancel" << endl
		    << endl;
	    } while (planMenu (students, plans));
	    break;
	 case '4':
	    return false;
	    break;
	 default:
	 {
	    cout << "Invalid selection";
	    return false;
	    break;
	 }
      }
   return true;
}

bool searchMenu (map <string, Student>& students, map <string, Plan>& plans)
{
   char choice;
   cin >> choice;
   switch (choice)
   {
      case '1':
      {
	 cout << endl << *getCourse ();
	 break;
      }
      case '2':
      {
	 cout << endl << *getMajor ();
	 break;
      }
      case '3':
      {
	 cout << endl << *getStudentPlan (students);
	 break;
      }
      case '4':
      {
	 cout << endl << *getStudentPlan (plans);
	 break;
      }
      case '5':
      {
	 return false;
	 break;
      }
      default:
      {
	 cout << "Invalid selection";
	 return false;
	 break;
      }
   }
   
   return true;
}

bool studentMenu (map <string, Student>& students, map <string, Plan>& plans)
{
   char choice;
   cin >> choice;
   switch (choice)
   {
      case '1':
      {
	 cout << endl;
	 addStudentPlan (students, plans);
	 break;
      }
      case '2':
      {
	 cout << endl;
	 changeMajor (students);
	 break;
      }
      case '3':
      {
	 cout << endl;
	 addCourse (students);
	 break;
      }
      case '4':
      {
	 cout << endl;
	 removeCourse (students);
	 break;
      }
      case '5':
      {
	 cout << endl;
	 canTake (students);
	 break;
      }
      case '6':
      {
	 return false;
	 break;
      }
      default:
      {
	 cout << "Invalid selection";
	 return false;
	 break;
      }
   }
   return true;
}

bool planMenu (map <string, Student>& students, map <string, Plan>& plans)
{
   char choice;
   cin >> choice;
   switch (choice)
   {
      case '1':
      {
	 cout << endl;
	 changeMajor (plans);
	 break;
      }
      case '2':
      {
	 cout << endl;
	 addCourse (plans);
	 break;
      }
      case '3':
      {
	 cout << endl;
	 removeCourse (plans);
	 break;
      }
      case '4':
      {
	 cout << endl;
	 canTake (plans);
	 break;
      }
      case '5':
      {
	 cout << endl;
         addPlanToStudent(plans);
         break;
      }
      case '6':
      {
	 return false;
	 break;
      }
      default:
      {
	 cout << "Invalid selection";
	 return false;
	 break;
      }
   }
   return true;
}


void addStudentPlan (map <string, Student>& students, map <string, Plan>& plans)
{
   cout << "Please enter the name of the student: ";
   string name;
   flushStream (cin);
   getline(cin, name);

   Student student (getMajor ());
   students [name] = student;
   
   plans [name + "'s Plan"] = Plan (&students [name]);
   
   return;
}

void addPlanToStudent (map <string, Plan>& plans) {
   getStudentPlan (plans) -> commitChanges ();
   cout << "Changes committed!" << endl;
   return;
}

template <typename Item>
void changeMajor (map <string, Item>& items)
{
   Item* item = getStudentPlan (items);
   item -> changeMajor (getMajor ());
   cout << "Major changed!" << endl;
   return;
}

template <typename Item>
void addCourse (map <string, Item>& items)
{
   Item* item = getStudentPlan (items);
   Course* courseToTake = getCourse ();

   if (item -> canTake (courseToTake))
   {
      item -> addCourse (courseToTake);
      cout << "Course added!" << endl;
   }
   else
      cout << "Prerequisites not met!" << endl;
   
   return;
}

template <typename Item>
void removeCourse(map <string, Item>& items)
{
   Item* item = getStudentPlan (items);

   try
   {
      item -> removeCourse (getCourse ());
   }
   catch (CourseNotFound)
   {
      cout << "Course does not exist in student!" << endl;
      return;
   }
   cout << "Course removed!" << endl;
   return;
}

template <typename Item>
void status (map <string, Item>& items)
{
   Item* item = getStudentPlan (items);
   item -> status (cout);
   return;
}

template <typename Item>
void showCourses (map <string, Item>& items)
{
   Item*  item = getStudentPlan (items);

   std::vector<Course*> itemCourses = item -> getCourses();
   for(unsigned int i = 0; i < itemCourses.size(); ++i) {
      cout << *itemCourses[i] << endl;
   }
   return;
}

template <typename Item>
void canTake (map <string, Item>& items)
{
   Item* item = getStudentPlan (items);
   
   if (item -> canTake (getCourse ()))
      cout << endl << "Yes, you may take this course." << endl;
   else
      cout << endl << "No, you have either taken this course already, or have not satisfied the course's prerequisites." << endl;
   
   return;
}

template <typename Item>
Item* getStudentPlan (map <string, Item>& items)
{
   cout << "Please enter the name of the student:" << endl
	<< "Available students: ";
   for (typename map <string, Item>::iterator it = items.begin (); it != --items.end (); ++it)
      cout << it -> first << ", ";
   cout << (--items.end ()) -> first << endl;
   
   string name;
   flushStream (cin);
   getline (cin, name);
   typename map <string, Item>::iterator result = items.find (name);
      
   while (result == items.end ())
   {
      cout << "Student not found! Try again: ";
      getline (cin, name);
      result = items.find (name);
   }

   return &(result -> second);
}

Course* getCourse ()
{
   cout << "Please enter the course [DEPT ####]:" << endl;
   CourseList* allCourses = CourseList::getInstance ();
   cout << *allCourses;

   flushStream (cin);
   string streamContents;
   getline (cin, streamContents);
   stringstream ss (streamContents);
   
   string courseDepartment;
   int courseNumber;
   ss >> courseDepartment >> courseNumber;
   
   Course* course = NULL;
   if (ss || ss.eof ())
   {
      course = allCourses -> find (courseDepartment, courseNumber);
   }
   while (course == NULL)
   {
      cout << "Course not found! Try again: ";
      flushStream (cin);
      getline (cin, streamContents);
      stringstream ss (streamContents);
      ss >> courseDepartment >> courseNumber;
      if (ss || ss.eof ())
      {
	 course = allCourses -> find (courseDepartment, courseNumber);
      }
   }
   
   return course;
}

Major* getMajor ()
{
   cout << "Please enter the major:" << endl;
   MajorList* allMajors = MajorList::getInstance ();
   cout << *allMajors;
   
   string majorName;
   flushStream (cin);
   getline (cin, majorName);
   
   Major* newMajor = allMajors -> find (majorName);
   while (newMajor == NULL)
   {
      cout << "Major not found! Try again: ";
      getline (cin, majorName);
      newMajor = allMajors -> find (majorName);
   }
   
   return newMajor;
}

void flushStream (istream& is)
{
   if (is.peek () == '\n')
      is.ignore ();
   return;
}
