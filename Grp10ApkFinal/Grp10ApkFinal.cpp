#include <thread>
#include "PlaneGenerator.h"
#include "ControlTower.h"
#include <math.h>
#include "Calculator.h"
#include "windows.h"
#include "WarningLogger.h"

using namespace std;

int main()
{
	/*
    thread t1(&PlaneGenerator::GeneratePlane, PlaneGenerator());
    thread t2(&ControlTower::CheckAirspace, ControlTower::getInstance());
    t1.join();
    t2.join();
	*/
//Testing Calculator and Logger

Plane p1 = Plane("p1", 1, 1);
Plane p2 = Plane("p2", 1, 3);

std::thread(&Plane::TakeOff, p1, 1).detach();

Sleep(10);

std::thread(&Plane::TakeOff, p2, 2).detach();

Calculator<Plane> dummy;

cout << "Distance is: " << dummy.distanceCalculator(p1, p2) << endl;

cout << "Course is: " << dummy.courseCalculator(p1, p2) << endl;


cout << "Speed is: " << dummy.speedCalculator(p1, p1) << endl;

cout << "Timestamps: " << endl;
cout << p1.timestamp << endl;
cout << p2.timestamp << endl;

Plane p3 = Plane("p3", 1, 1);
Plane p4 = Plane("p4", 1, 1);

WarningLogger log;
log.WriteWarning(p3, p4);

    return 0;
}