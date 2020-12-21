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

bool ControlTower::isInAirspace(Plane* plane)
{
	return (plane->xcoordinate <= 100 && plane->ycoordinate <= 100);
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

				//beregn hastighed og distancer
				for (auto c = currentSignals.cbegin(), p = previousSignals.cbegin();
					c != currentSignals.cend() && p != previousSignals.cend(); ++c, ++p)
				{
					for (auto cu = currentSignals.cbegin(), pe = previousSignals.cbegin();
						cu != currentSignals.cend() && pe != previousSignals.cend(); ++cu, ++pe)
					{
						if (isInAirspace((*c)) && isInAirspace((*pe)))
						{
							cout << "Planes:" << endl;
							cout << (*cu)->nametag << " x: " << (*cu)->xcoordinate << " y: " << (*cu)->ycoordinate << " Current" << endl; 
							cout << (*pe)->nametag << " x: " << (*pe)->xcoordinate << " y: " << (*pe)->ycoordinate << " Previous" << endl;
						}
	
						//if ((*c)->nametag == ((*pe)->nametag))
						//{
						//	//der er nok brugt nogle forskellige timestamps, ser ikke ud til vi kan bruge den vi har nu til beregning. Ellers skal beregning ændres
						//	//hvad har mikkel burgt til at teste?
						//	//cout << "Planetag: " << (*c)->nametag << " flies with " <<  Calculator.speedCalculator((*c), (*p)) << " mp/h" << endl;
						//}
						//else
						//{
						//	//Hvis et fly disconnector sig her, vil vi crashe her. Sørg for at listen kun indeholder fly som er connected.
						//	//if(connections.)
						//	//cout << "Distance between " << (*c)->nametag << " and " << (*p)->nametag << ": " << Calculator.courseCalculator((*c), (*p)) << endl;
						//}
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