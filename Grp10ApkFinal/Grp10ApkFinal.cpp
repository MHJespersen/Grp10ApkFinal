#include <thread>
#include "PlaneGenerator.h"
#include "ControlTower.h"
#include <math.h>
//#include "Calculator.h"

using namespace std;

int main()
{
    thread t1(&PlaneGenerator::GeneratePlane, PlaneGenerator());
    thread t2(&ControlTower::CheckAirspace, ControlTower::getInstance());
    t1.join();
    t2.join();

    return 0;
}