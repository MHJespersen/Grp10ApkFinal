#include <iostream>
#include <ostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include "Plane.h"
#include "ControlTower.h"
#include <mutex>

ControlTower* ControlTower::getInstance()
{
	if (!instance)
		instance = new ControlTower;
	return instance;
}

ControlTower::ControlTower()
{
	//Instantiate calculators
}

void ControlTower::CheckAirspace() //std::vector<Plane> planes, mutex& m1, mutex& m2
{
	while (true)
	{
		this->connections();
		this_thread::sleep_for(std::chrono::seconds(3));

		//Calculate distance, make exception (in distance calculator) if planes are too close
		//if excepion is called, write logfile
	}
}

void ControlTower::WriteLog()
{
}
ControlTower* ControlTower::instance;
