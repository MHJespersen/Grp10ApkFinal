#include <iostream>
#include <ostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include "Plane.h"
#include "ControlTower.h"
#include "Calculator.cpp"
#include <mutex>
#include <thread>

ControlTower* ControlTower::instance;

ControlTower::ControlTower() {
}

void ControlTower::isInAirspace(list<Plane*> currentPlanes)
{
	//Check if old signal is still valid
	for (auto pIt = previousSignals.begin(); pIt != previousSignals.end(); pIt++)
	{
		auto cIt = find_if(currentPlanes.begin(), currentPlanes.end(), [pIt](Plane* obj) {return obj->nametag == pIt->nametag; });
		if (cIt == currentPlanes.end()) 
		{
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

void ControlTower::checkAirspace()
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
					cout << "Plane: " << (*c)->nametag << " is flying with : " << calculator.speedCalculator((*c), &(*p)) << " km/h" << endl;
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
	float distance = calculator.distanceCalculator(cu, pre);
	cout << "Distance between " << cu->nametag << " and " << pre->nametag << " is : " << distance << endl;
	if (distance < 6)
	{
		logger.WriteWarning(cu, pre);
	}
}