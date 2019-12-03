#pragma once
#include "Course.h"
#include<vector>
class Map
{
public:
	Map();
	~Map();
	void addEntry(shared_ptr<Course> course);
	shared_ptr<Course> getEntry(string courseNumber);
	void deleteEntry(string courseNumber);
	
private:
	vector<shared_ptr<Course>>Course_List;
	hash<string> myhash;
	bool isInVector(int hashNumber);
};



