
#include <iostream>
#include "PlaneGenerator.h"
#include "Plane.h"

using namespace std;
int main()
{
    cout << "Hello World!\n" << endl;

    PlaneGenerator planeGenerator;
    Plane myPlane = planeGenerator.GeneratePlane();
}