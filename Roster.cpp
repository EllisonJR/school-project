#include "Roster.h"
#include "degree.h"
#include "Student.h"
#include <iostream>

void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram, int rosterIndexer)
{
	classRosterArray[rosterIndexer] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);
}
Roster::Roster()
{
}
Roster::~Roster()
{
	delete classRosterArray;
}
void Roster::Remove(string studentID)
{
	for (int i = 0; i < 5; i++)
	{
		try
		{
			if (classRosterArray[i]->GetStudentID() == studentID)
			{
				cout << "Deleting " << classRosterArray[i]->GetStudentID() << "..." << endl;
				delete classRosterArray[i];
			}
		}
		catch (bad_alloc)
		{
			cout << "Student does not exist." << endl << endl;
		}
	}
	return;
}
void Roster::PrintAverageDaysInCourse(string studentID)
{
	int sumOfDays = 0;
	for (int index = 0; index < 5; index++)
	{
		if (classRosterArray[index]->GetStudentID() == studentID)
		{
			for (int dayIndex = 0; dayIndex < 3; dayIndex++)
			{
				sumOfDays += classRosterArray[index]->GetDaysRemaining(dayIndex);
			}
			break;
		}
	}
	cout << (sumOfDays / 3) << endl;
	return;
}
void Roster::PrintAll()
{
	for (int i = 0; i < 5; i++)
	{
		try
		{
			classRosterArray[i]->print();
		}
		catch (bad_alloc)
		{
			continue;
		}
	}
	cout << endl;
	return;
}
void Roster::PrintInvalidEmails()
{
	for (int i = 0; i < 5; i++)
	{
		string email = classRosterArray[i]->GetEmail();
		if (email.find('@') == string::npos || email.find(' ') != string::npos || email.find('.com') == string::npos || email.find('.net') == string::npos || email.find('.org') == string::npos)
		{
			cout << classRosterArray[i]->GetEmail() << endl;
		}
	}
	cout << endl;
	return;
}
void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram)
{
	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i]->GetDegreeProgram() == degreeProgram)
		{
			classRosterArray[i]->print();
		}
	}
	cout << endl;
	return;
}