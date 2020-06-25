#pragma once
#include "degree.h"
#include "Student.h"
#include<string>

using namespace std;

class Roster
{
	public:
		void Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram, int rosterIndexer);
		void Remove(string studentID);
		void PrintAverageDaysInCourse(string studentID);
		void PrintAll();
		void PrintInvalidEmails();
		void PrintByDegreeProgram(DegreeProgram degreeProgram);
		Roster();
		~Roster();
		Student *classRosterArray[5];
};

