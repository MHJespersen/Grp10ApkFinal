#include <iostream>
#include <ostream>
#include <thread>
#include "PlaneGenerator.h"
#include <string>
#include <string.h>
#include <mutex>
#include <stdlib.h>
#include <vector>
#include <list>
#include "Plane.h"
#include "ControlTower.h"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/signals2.hpp>
#include <boost/bind.hpp>

using namespace std;


int main(int argc, const char* argv[])
{
    thread t1(&PlaneGenerator::GeneratePlane, PlaneGenerator());
    thread t2(&ControlTower::CheckAirspace, ControlTower::getInstance());
    t1.join();
    t2.join();
    return 0;
}
