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
	list<Plane*> currentSignals;	
	while (true)
	{
		if (previousSignals.empty()) //kald #1
			previousSignals = this->connections(); 

		else //kald #2
		{
			if (currentSignals.empty())
				currentSignals = this->connections(); 

			else //Alle kald efter #2  --- Brug noget copy fra apk?
			{
				previousSignals = currentSignals;
				currentSignals = this->connections(); //andet kald
				list<Plane*>::iterator cu;
				list<Plane*>::iterator pre;
				//beregn hastighed og distancer
				for (auto c = currentSignals.cbegin(), p = previousSignals.cbegin();
					c != currentSignals.cend() && p != previousSignals.cend(); ++c, ++p)
				{
					if (c._Ptr->_Myval->nametag._Equal(p._Ptr->_Myval->nametag))
					{
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