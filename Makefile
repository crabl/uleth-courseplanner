CC = g++
CCFLAGS = -Wall -g
OBJS = Course.o CourseList.o FortyCoursesObjective.o GLER.o GLERObjective.o Major.o MajorList.o MinimumObjective.o OneOfObjective.o Plan.o SingleObjective.o Student.o
TESTS = tester.o CourseListTest.o CourseTest.o FortyCoursesObjectiveTest.o GLERObjectiveTest.o GLERTest.o MajorTest.o MajorListTest.o MinimumObjectiveTest.o OneOfObjectiveTest.o PlanTest.o SingleObjectiveTest.o StudentTest.o
.PHONY : all
all : tester smbc
tester : $(OBJS) $(TESTS)
	$(CC) $(CCFLAGS) $^ -o $@ -lcppunit -ldl

smbc : $(OBJS) main.o
	$(CC) $(CCFLAGS) $^ -o $@

%.o : %.cc
	$(CC) $(CCFLAGS) -c $<

## generate the prerequistes and append to the desired file
.prereq : $(OBJS:.o=.cc) $(wildcard *.h) Makefile
	rm -f .prereq
	$(CC) $(CCFLAGS) -MM $(OBJS:.o=.cc) >> ./.prereq

## include the generated prerequisite file
include .prereq

.PHONY : clean
clean :
	rm -f *.o *~ #* .#*

.PHONY : clean-all
clean-all : clean
	rm -f tester smbc
