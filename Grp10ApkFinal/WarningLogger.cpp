#include <algorithm>
#include <iostream>
#include <fstream>
#include "WarningLogger.h"
#include "Plane.h"
#include <ostream>

using namespace Airplanes;

namespace Airspace
{
	void WarningLogger::WriteWarning(Plane* prevPlane, Plane* newPlane)
	{
		std::ofstream ofs;
		ofs.open(LOGFILE, std::ofstream::out | std::ios::app);
		message = "WARNING - RISK OF COLLISION BETWEEN: " + prevPlane->nametag + " AND " + newPlane->nametag;
		ofs << message << std::endl;
		ofs.close();
	}
}