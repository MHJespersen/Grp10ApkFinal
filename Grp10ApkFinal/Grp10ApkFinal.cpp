#include <thread>
#include "PlaneGenerator.h"
#include "ControlTower.h"

using namespace std;
using namespace Airplanes;
using namespace Airspace;

int main()
{
    thread t1(&PlaneGenerator::GeneratePlane, PlaneGenerator());
    thread t2(&ControlTower::checkAirspace, ControlTower::getInstance());
    t1.join();
    t2.join();
    return 0;
}