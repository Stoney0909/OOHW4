#include "Map.h"
#include <exception>


Map::Map()
{
}


Map::~Map()
{
}

void Map::addEntry(shared_ptr<Course> course)
{
	course->hashNumber = myhash(course->courseNumber);
	try
	{
		if (isInVector(course->hashNumber))
		{
			throw 20;
		}
	}
	catch (int e)
	{
		cout << course->courseNumber << " is already a Course you cannot add it to the Courses." << endl;
		return;
	}
	
	Course_List.push_back(course);
			
		}

shared_ptr<Course> Map::getEntry(string courseNumber)
{
	
	int courseHash = myhash(courseNumber);


	vector<shared_ptr<Course>>::iterator ptr;
	for (ptr = Course_List.begin(); ptr != Course_List.end(); ptr++)
	{
		if (courseHash == (*ptr)->hashNumber)
		{
				return (*ptr);
		}

	}	

		cout << "Error: " << courseNumber << " is not a valid course." << endl;
		return nullptr;
	
	
}

		

void Map::deleteEntry(string courseNumber)
{
	int courseHash = myhash(courseNumber);
	try
	{
		if (!isInVector(courseHash))
		{
			throw 20;
		}
	}
	catch (int e)
	{
		cout << "Error: " << courseNumber << " is not a valid course." << endl;
		return;
	}


	vector<shared_ptr<Course>>::iterator ptr;
	for (ptr = Course_List.begin(); ptr != Course_List.end(); ptr++)
	{
		if (courseHash == (*ptr)->hashNumber)
		{
			ptr = Course_List.erase(ptr);
			cout << "Successfully deleted the Entry" << endl;
			return;			
		}
		
	}


}

bool Map::isInVector(int hashNumber)
{
		vector<shared_ptr<Course>>::iterator ptr;
	
		for (ptr = Course_List.begin(); ptr != Course_List.end(); ptr++)
		{
			if (hashNumber == (*ptr)->hashNumber)
			{
				return true;
			}
		}
	return false;
}
