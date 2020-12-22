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
void ControlTower::isInAirspace(list<Plane*> currentPlanes)
{
	for (auto pIt = previousSignals.begin(); pIt != previousSignals.end(); pIt++)
	{
		//Check if old signal is still valid
		auto cIt = find_if(currentPlanes.begin(), currentPlanes.end(), [pIt](Plane* obj) {return obj->nametag == pIt->nametag; });
		if (cIt == currentPlanes.end()) {
			//Old signal is no longer valid, delete unused object
			previousSignals.erase(pIt++);
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
}

void ControlTower::checkAirspace() //std::vector<Plane> planes, mutex& m1, mutex& m2
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
			for (list<Plane*>::iterator c = currentSignals.begin(); c != currentSignals.end(); c++)
			{
				for (list<Plane>::iterator p = previousSignals.begin(); p != previousSignals.end(); p++)
				{
					if ((*c)->nametag == p->nametag)
						cout << "Plane: " << (*c)->nametag << " is flyting with : " << Calculator.speedCalculator((*c), &(*p)) << " mp/h" << endl;
					else
					{
						checkDistance((*c), &(*p));
					}
				}
			}
		}
	}
}
void ControlTower::checkDistance(Plane* cu, Plane* pre)
{
	float distance = Calculator.distanceCalculator(cu, pre);
	cout << "Distance between " << cu->nametag << " and " << pre->nametag << " is : " << distance << endl;
	if (distance < 6)
	{
		logger.WriteWarning(cu, pre);
	}
}