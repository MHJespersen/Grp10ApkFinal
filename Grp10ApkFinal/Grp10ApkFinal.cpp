#include <thread>
#include "PlaneGenerator.h"
#include "ControlTower.h"
#include <math.h>
#include "Calculator.h"
#include <windows.h>

using namespace std;

int main()
{
	
    thread t1(&PlaneGenerator::GeneratePlane, PlaneGenerator());
    thread t2(&ControlTower::CheckAirspace, ControlTower::getInstance());
    t1.join();
    t2.join();
    return 0;
	

	//Testing calculator
	/*
	Plane p1 = Plane("p1", 1, 1);
	Plane p2 = Plane("p2", 1, 3);

	Calculator<Plane> calc;

	Sleep(10);
	
	cout << "distance is: " << calc.distanceCalculator(&p1, &p2) << endl;
	cout << "speed is: " << calc.speedCalculator(&p1, &p2) << endl;
	cout << "course is: " << calc.courseCalculator(&p1, &p2) << endl;
	*/
}