#include <thread>
#include "PlaneGenerator.h"
#include "ControlTower.h"
#include "PlanePrinter.h"

using namespace std;

int main()
{
    thread t1(&PlaneGenerator::GeneratePlane, PlaneGenerator());
    thread t2(&ControlTower::checkAirspace, ControlTower::getInstance());
    t1.join();
    t2.join();

    ////Test variadic print
    //Plane plane1("plane1", 1, 1);
    //Plane plane2("plane2", 1, 1);
    //Plane plane3("plane3", 1, 1);
    //Plane plane4("plane4", 1, 1);
    //string notaplane = "hej";
    //PlanePrinter printer = PlanePrinter();
    //
    //printer.printPlanes(&plane1, &plane2, &plane3, &plane4, &notaplane);

    return 0;
}