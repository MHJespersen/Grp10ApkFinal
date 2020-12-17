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

/*oid test(mutex& m1, mutex& m2)
{
    vector<Plane> PlaneVec;
    ControlTower* control = ControlTower::getInstance();

    while (true)
    {
        if (control->connections.num_slots() < 10)
        {
            PlaneGenerator planeGenerator;
            Plane myPlane = planeGenerator.GeneratePlane();
            control->connections.connect(myPlane);
            this_thread::sleep_for(std::chrono::seconds(3));
        }
    }
}*/

int main(int argc, const char* argv[])
{
    thread t1(&PlaneGenerator::GeneratePlane, PlaneGenerator());
    thread t2(&ControlTower::CheckAirspace, ControlTower::getInstance());
    t1.join();
    t2.join();
    return 0;
}
