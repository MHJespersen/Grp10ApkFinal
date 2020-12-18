#include <iostream>
#include <ostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include "Plane.h"
#include "ControlTower.h"
#include <mutex>

ControlTower* ControlTower::instance;

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
	list<Plane*> current;	
	while (true)
	{
		if (previousSignals.empty())
			previousSignals = this->connections(); //føste kald

		else
		{
			if (!current.empty())
			{
				previousSignals = current; //Alle kald efter #2  --- Brug noget copy fra apk?
			}
			current = this->connections(); //andet kald
		}

		this_thread::sleep_for(std::chrono::seconds(3));
	}
}

void ControlTower::WriteLog()
{
}
