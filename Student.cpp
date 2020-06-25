#include "Student.h"
#include <iostream>

Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = email;
	this->age = age;
	this->daysLeft[0] = daysInCourse1;
	this->daysLeft[1] = daysInCourse2;
	this->daysLeft[2] = daysInCourse3;
	this->degreeProgram = degreeProgram;
}
Student::Student()
{
}
string Student::GetStudentID()
{
	return studentID;
}
string Student::GetFirstName()
{
	return firstName;
}
string Student::GetLastName()
{
	return lastName;
}
string Student::GetEmail()
{
	return emailAddress;
}
int Student::GetAge()
{
	return age;
}
int Student::GetDaysRemaining(int index)
{
	return daysLeft[index];
}
DegreeProgram Student::GetDegreeProgram()
{
	return degreeProgram;
}
void Student::SetStudentID(string studentID)
{
	this->studentID = studentID;
	return;
}
void Student::SetFirstName(string firstName)
{
	this->firstName = firstName;
	return;
}
void Student::SetLastName(string lastName)
{
	this->lastName = lastName;
	return;
}
void Student::SetEmail(string emailAddress)
{
	this->emailAddress = emailAddress;
	return;
}
void Student::SetAge(int age)
{
	this->age = age;
	return;
}
void Student::SetDaysRemaining(int daysLeft, int index)
{
	this->daysLeft[index] = daysLeft;
	return;
}
void Student::SetDegreeProgram(DegreeProgram degreeProgram)
{
	this->degreeProgram = degreeProgram;
	return;
}
void Student::print()
{
	cout << this->GetStudentID() << "	";
	cout << "First Name: " << this->GetFirstName() << "	";
	cout << "Last Name: " << this->GetLastName() << "	";
	cout << "Age: " << this->GetAge() << "	";
	cout << "daysInCourse: {" << this->GetDaysRemaining(0) << ", " << this->GetDaysRemaining(1) << ", " << this->GetDaysRemaining(2) << "}	";
	if (this->GetDegreeProgram() == 0)
	{
		cout << "Degree Program: SECURITY" << endl;
	}
	else if (this->GetDegreeProgram() == 1)
	{
		cout << "Degree Program: NETWORK" << endl;
	}
	else if (this->GetDegreeProgram() == 2)
	{
		cout << "Degree Program: SOFTWARE" << endl;
	}
	return;
}