#pragma once
using namespace std;
#include <vector>
#include <fstream>
#include "Plane.h"

class WarningLogger
{
private:
#define LOGFILE "warningsfile.txt"
	string message;

	//vector<string> tagList;
	//std::ofstream warningsFile("warningsFile.txt", std::ios_base::out | std::ios_base::app);

public:
	void WriteWarning(Plane* prevPlane, Plane* newPlane);

};