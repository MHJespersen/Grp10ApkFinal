#pragma once
using namespace std;
#include <vector>

#include "Plane.h"


class WarningLogger
{
private:
	vector<string> tagList;
	ofstream warningsFile;

public:
	void WriteWarning(Plane prevPlane, Plane newPlane);

};