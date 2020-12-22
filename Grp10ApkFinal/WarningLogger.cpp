#include "WarningLogger.h"

#include <algorithm>
#include <iostream>
#include <fstream>

/*
void WarningLogger::WriteWarning(Plane prevPlane, Plane newPlane)
{
	//Check taglist for the two tags, if they aren't already in taglist we may issue a warning
	if (!(find(tagList.begin(), tagList.end(), prevPlane.nametag) != tagList.end()
		&& find(tagList.begin(), tagList.end(), newPlane.nametag) != tagList.end()))
	{
		warningsFile.open("Warnings.txt");
		warningsFile << "WARNING - RISK OF COLLISION BETWEEN: " << prevPlane.nametag << " AND " << newPlane.nametag << endl;
		warningsFile.close();
	}
}
*/

void WarningLogger::WriteWarning(Plane* prevPlane, Plane* newPlane)
{
	std::ofstream ofs;
	ofs.open(LOGFILE, ofstream::out | std::ios::app);
	message = "WARNING - RISK OF COLLISION BETWEEN: " + prevPlane->nametag + " AND " + newPlane->nametag;
	ofs << message << std::endl;
	ofs.close();
}