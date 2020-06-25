#pragma once
#include "degree.h"
#include <string>

using namespace std;

class Student
{
	private:
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int age;
		int daysLeft[3];
		DegreeProgram degreeProgram;
	public:
		Student(string studentID, string firstName, string lastName, string email, int age, int daysLeft1, int daysLeft2, int daysLeft3, DegreeProgram degreeProgram);
		Student();

		string GetStudentID();
		string GetFirstName();
		string GetLastName();
		string GetEmail();
		int GetAge();
		int GetDaysRemaining(int index);
		DegreeProgram GetDegreeProgram();

		void SetStudentID(string studentID);
		void SetFirstName(string firstName);
		void SetLastName(string lastName);
		void SetEmail(string emailAddress);
		void SetAge(int age);
		void SetDaysRemaining(int daysLeft, int index);
		void SetDegreeProgram(DegreeProgram degreeProgram);

		void print();
};

