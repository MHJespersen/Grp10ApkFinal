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
		//kald #1
		if (previousSignals.empty()) 
			previousSignals = this->connections();

		//kald #2
		else 
		{
			if (currentSignals.empty())
				currentSignals = this->connections();

			//Alle kald efter #2  --- Brug noget copy fra apk?
			else 
			{
				previousSignals.assign(currentSignals.begin(), currentSignals.end());
				currentSignals = this->connections();

				list<Plane*>::iterator cu;
				list<Plane*>::iterator pre;
				//beregn hastighed og distancer
				for (auto c = currentSignals.cbegin(), p = previousSignals.cbegin();
					c != currentSignals.cend() && p != previousSignals.cend(); ++c, ++p)
				{
					if ((*c)->nametag == ((*p)->nametag))
					{
						cout << "Speed" << endl;
						//speed = calculate speed
					}
					else
					{
						//distance between different planes
					}
				}
			}
		}	
		this_thread::sleep_for(std::chrono::seconds(3));
	}
}

void ControlTower::WriteLog()
{
}