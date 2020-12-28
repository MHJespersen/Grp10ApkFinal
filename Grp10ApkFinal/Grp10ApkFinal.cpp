#include <thread>
#include "PlaneGenerator.h"
#include "ControlTower.h"
#include "PlanePrinter.h"
#include <variant>

using namespace std;
using namespace Airplanes;
using namespace Airspace;

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

    //std::variant example
    //variant<int, string> variant;
    //variant = "test";
    //variant = 2;
    //if (auto value = get_if<int>(&variant))
    //{
    //    cout << "Variant is type integer, using index " << variant.index()  << endl;
    //    cout << *value << endl;
    //}
    //else if(auto value = get_if<string>(&variant))
    //{
    //    cout << "Variant type is string, using index " << variant.index() << endl;
    //    cout << *value << endl;
    //}

    return 0;
}