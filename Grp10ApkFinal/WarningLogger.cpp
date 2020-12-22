#include "WarningLogger.h"

#include <algorithm>
#include <iostream>
#include <fstream>

void WarningLogger::WriteWarning(Plane* prevPlane, Plane* newPlane)
{
	std::ofstream ofs;
	ofs.open(LOGFILE, ofstream::out | std::ios::app);
	message = "WARNING - RISK OF COLLISION BETWEEN: " + prevPlane->nametag + " AND " + newPlane->nametag;
	ofs << message << std::endl;
	ofs.close();
}