#pragma once
#include <iostream>
#include <string>
using namespace std;

class Course
{
public:
	Course();
	~Course();
	string courseName, courseNumber, instructorName, buildingName;
	int roomNumber, enrolledStudents, hashNumber;
};

