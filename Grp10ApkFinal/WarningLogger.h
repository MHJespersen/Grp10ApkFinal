#pragma once
#include <vector>
#include <fstream>
#include "Plane.h"

namespace Airspace
{
	class WarningLogger
	{
	private:
	#define LOGFILE "warningsfile.txt"
		std::string message;
	public:
		WarningLogger() {};
		void WriteWarning(Airplanes::Plane* prevPlane, Airplanes::Plane* newPlane);
	};
}