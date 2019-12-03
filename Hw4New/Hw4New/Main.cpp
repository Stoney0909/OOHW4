#include <iostream>
#include "Course.h"
#include "Map.h"
#include <fstream>
using namespace std;

int main()
{
	Map courseMap;
	bool keepGoing = true;
	bool fileLoaded = false;
	ifstream myfile;
	

	while (keepGoing)
	{
		
		
		char input;
		cout << "Choose a Command.  L for load, G for get info, D for delete course, and X for exit." << endl;
		cin >> input;
		input = toupper(input);
		try
		{
			if (input != 'L' && input != 'G' && input != 'D' && input != 'X')
			{
				throw "Not the Correct input";
				continue;
			}
		}//Check to see if Correct Command
		
		catch (const char* msg)
		{
			cout << msg << endl;
		}

		try
		{
			if ((input == 'G' || input == 'D') && fileLoaded == false)//Check to see if file is loaded
			{
				throw "File not Loaded";
			}
			if (input == 'L' && fileLoaded == true)//Check to see if file is already loaded
			{
				throw "File Already Loaded";
			}
		}
		catch (const char* msg)
		{
			cout << msg << endl;
			continue;
		}

		if (input == 'L' && fileLoaded == false)//Loading of the File
		{
			
			bool wrongLocation = true;
			cin.ignore();

			while (wrongLocation)
			{
				string location;
				cout << "Please Enter in you file location." << endl;
				
				getline(cin, location);
				myfile.open(location);
				try
				{
					if (!myfile.is_open())
					{
						throw "Incorrect file Location";
					}
				}
				catch (const char* msg)
				{
					cout << msg << endl;
					continue;
				}
					try
		{
			if ((input == 'G' || input == 'D') && fileLoaded == false )
			{
				throw "File not Loaded";
			}
			if (input == 'L' && fileLoaded == true)
			{
				throw "File Already Loaded";
			}
		}
		catch (const char* msg)
		{
			cout << msg << endl;
			continue;
		}
				if (myfile.is_open())
				{
					shared_ptr<Course> course;
					cout << "file Loaded" << endl;
					int lineNumber = 0;
					string line;
					while (getline(myfile, line))
					{
						
						if (lineNumber == 0)
						{
							course->courseNumber = line;
							
						}
						if (lineNumber == 1)
						{
							course->courseName = line;
						}
						if (lineNumber == 2)
						{
							course->instructorName = line;
						}
						if (lineNumber == 3)
						{
							course->enrolledStudents = stoi(line);
						}
						if (lineNumber == 4)
						{
							course->buildingName = line;
						}
						if (lineNumber == 5)
						{
							course->roomNumber = stoi(line);
						}
						lineNumber++;
						if (lineNumber == 6)
						{
							courseMap.addEntry(course);
							lineNumber = 0;
						}
						
						
					}
					
				}
					
					fileLoaded = true;
					wrongLocation = false;
			}
		}

		else if (input == 'G')//Get Course
		{
			string courseNumber;
			cout << "Please enter in a Course Number" << endl;
			cin >> courseNumber;
			shared_ptr<Course> course = courseMap.getEntry(courseNumber);
			if (course == nullptr)//Catch the Null
			{
				continue;
			}
			
			cout << "Course Number: " << course->courseNumber << endl;
			cout << "Course Name: " << course->courseName << endl;
			cout << "Instructor: " << course->instructorName << endl;
			cout << "Number of Enrolled Students: " << course->enrolledStudents << endl;
			cout << "Building name: " << course->buildingName << endl;
			cout << "Room Number: " << course->roomNumber << endl;
		}

		else if (input == 'D')//Delete Course
		{
				string courseNumber;
				cout << "Please enter in a Course Number" << endl;
				cin >> courseNumber;

				courseMap.deleteEntry(courseNumber);
		}	
		else if (input == 'X')
		{
			keepGoing = false;
		}
		else
		{
			continue;
		}

	}

	myfile.close();
	
}