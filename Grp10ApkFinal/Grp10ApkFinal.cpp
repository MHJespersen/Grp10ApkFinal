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

void test(mutex& m1, mutex& m2)
{
    vector<Plane> PlaneVec;
    ControlTower* control = ControlTower::getInstance();

    while (true)
    {
        if (control->connections.num_slots() < 10)
        {
            int x = rand() % 10;
            boost::uuids::random_generator generator;
            boost::uuids::uuid uuid = generator();
            Plane newPlane = Plane(to_string(uuid), x, 0);

            PlaneVec.push_back(newPlane);
            control->connections.connect(newPlane);
            this_thread::sleep_for(std::chrono::seconds(3));
        }
    }
}

int main(int argc, const char* argv[])
{
    mutex m1, m2;
    ControlTower* control = control->getInstance();

    thread t1(test, ref(m1), ref(m2));
    thread t2(&ControlTower::CheckAirspace, ControlTower::getInstance());

    //testing signal
    //boost::signals2::signal<void()> Sig;
    //Plane2 newPlane2("TestTag", 0, 0);
    //Plane2 newPlane3("TestTag 2", 0, 0);
    //boost::signals2::connection c = tower.connections.connect(newPlane2);

    //join threads to stay alive
    t2.join();
    t1.join();
    return 0;
}

int main(int argc, const char* argv[])
{
    cout << "Plane Generator!\n" << endl;

    PlaneGenerator planeGenerator;
    Plane myPlane = planeGenerator.GeneratePlane();
}