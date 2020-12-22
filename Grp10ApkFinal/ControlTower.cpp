#include <iostream>
#include <ostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include "Plane.h"
#include "ControlTower.h"
#include <mutex>
#include <thread>

ControlTower* ControlTower::instance;
//auto delIt = find_if(previousSignals.begin(), previousSignals.end(), [&Nametag](Plane obj) {return obj.nametag == Nametag; });
void ControlTower::isInAirspace(list<Plane*> currentPlanes)
{

	for (auto p = previousSignals.begin(); p != previousSignals.end(); p++)
	{
		//Check if old signal is still valid
		auto it = find_if(currentPlanes.begin(), currentPlanes.end(), [p](Plane* obj) {return obj->nametag == p->nametag; });
		if (it == currentPlanes.end()) {
			//Old signal is no longer valid, delete unused object
			previousSignals.erase(p++);
			cout << "Deleted" << endl;
			cout << previousSignals.size() << endl;
			cout << currentPlanes.size() << endl;
		}
	};
}

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
	list<Plane*> currentSignals;
	while (true)
	{
		if (previousSignals.empty())
		{
			currentSignals = connections();
			if (!currentSignals.empty())
			{
				std::transform(currentSignals.begin(), currentSignals.end(),std::back_inserter(previousSignals),[](Plane* p) { return *p; });
				currentSignals = connections();
			}
		}
		else
		{
			previousSignals.clear();
			std::transform(currentSignals.begin(), currentSignals.end(), std::back_inserter(previousSignals), [](Plane* p) { return *p; });
			std::this_thread::sleep_for(std::chrono::seconds(3));
			currentSignals = connections();
			isInAirspace(currentSignals);
			for (auto c = currentSignals.begin(); c != currentSignals.end(); c++)
			{
				for (auto p = previousSignals.begin(); p != previousSignals.end(); p++)
				{
					if ((*c)->nametag == p->nametag)
						cout << "Plane: " << (*c)->nametag << " is flyting with : " << Calculator.speedCalculator((*c), &(*p)) << " mp/h" << endl;
					else
					{
						float distance = Calculator.distanceCalculator((*c), &(*p));
						cout << "Distance between " << (*c)->nametag << " and " << p->nametag << " is : " << distance << endl;
						if (distance < 5)
						{
							cout << "WARNING" << endl; //write log
						}
					}
				}
			}

		}
	}
}

void ControlTower::WriteLog()
{
}