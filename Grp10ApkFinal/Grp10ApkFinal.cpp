#include <thread>
#include "PlaneGenerator.h"
#include "ControlTower.h"

using namespace std;

void main()
{
    thread t1(&PlaneGenerator::GeneratePlane, PlaneGenerator());
    thread t2(&ControlTower::CheckAirspace, ControlTower::getInstance());
    t1.join();
    t2.join();
}
