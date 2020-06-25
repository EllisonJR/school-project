#include <string>
#include <sstream>
#include <iostream>

#include "Roster.h"
#include "degree.h"

void ParseStudents(string studentTableString, int rosterIndexer);
DegreeProgram StringToDegree(string degree);

Roster* studentRoster = new Roster();

string studentID;
string firstName;
string lastName;
string email;
int age;
int daysLeft1;
int daysLeft2;
int daysLeft3;
DegreeProgram degreeProgram;

void main()
{
	cout << "Scripting and Programming Applications." << endl << "C++" << endl << "Student ID: 001224086" << endl << "Steven Ellison" << endl << endl;

	const string studentData[] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Steven,Ellison,steven.ellison.jr@gmail.com,29,10,30,30,SOFTWARE"};

	for (int i = 0; i < 5; i++)
	{
		ParseStudents(studentData[i], i);
	}

	studentRoster->PrintAll();
	studentRoster->PrintInvalidEmails();

	for (int i = 0; i < 5; i++)
	{
		studentRoster->PrintAverageDaysInCourse(studentRoster->classRosterArray[i]->GetStudentID());
	}
	cout << endl;

	studentRoster->PrintByDegreeProgram(SOFTWARE);

	studentRoster->Remove("A3");

	studentRoster->PrintAll();

	studentRoster->Remove("A3");
}
void ParseStudents(string studentTableString, int rosterIndexer)
{
	stringstream ss(studentTableString);

	for (int i = 0; i < 9; i++)
	{
		if (ss.good())
		{
			string subString;
			getline(ss, subString, ',');

			switch (i)
			{
			case 0:
				studentID = subString;
				break;
			case 1:
				firstName = subString;
				break;
			case 2:
				lastName = subString;
				break;
			case 3:
				email = subString;
				break;
			case 4:
				age = stoi(subString);
				break;
			case 5:
				daysLeft1 = stoi(subString);
				break;
			case 6:
				daysLeft2 = stoi(subString);
				break;
			case 7:
				daysLeft3 = stoi(subString);
				break;
			case 8:
				degreeProgram = StringToDegree(subString);
				break;
			}
		}
		studentRoster->Add(studentID, firstName, lastName, email, age, daysLeft1, daysLeft2, daysLeft3, degreeProgram, rosterIndexer);
	}
	return;
}
DegreeProgram StringToDegree(const string degree)
{
	if (degree == "NETWORK") return NETWORK;
	else if (degree == "SOFTWARE") return SOFTWARE;
	else if (degree == "SECURITY") return SECURITY;
}