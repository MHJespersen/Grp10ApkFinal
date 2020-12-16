#include "PlaneGenerator.h"
#include <cstdlib>
#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.

PlaneGenerator::PlaneGenerator()
{
    // Set random seed for random generator
    srand(time(NULL));
}

Plane PlaneGenerator::GeneratePlane()
{
    // Determine which axis to on
    int axis = rand() % 1; // Random number 0 or 1. 0 = x, 1 = y
    // Determine which side to start
    int startAtEnd = rand() % 1; // Random number 0 or 1. 0 = start, 1 = end

    int x;
    int y;

    // If y-axis
    if(axis)
    {
        x = 0;
        y = rand() % 10; // random number between 0 - 10;
        if(startAtEnd)
        {
            x = 9;
        }
    }    
    else // if x-axis
    {
        x = rand() % 10; // random number between 0 - 10;
        y = 0;
        if(startAtEnd)
        {
            y = 9;
        }
    }     

    // Generate unique name
    std::string name = "";

    Plane plane(name, x, y);

    UpdatePlaneCoordinates(plane);

    return plane;
}

// Reccursive?
void PlaneGenerator::UpdatePlaneCoordinates(Plane plane)
{
    // sleep 1-5 secs
    //Sleep(rand() % 5 + 1);

    if (plane.xcoordinate == 0)
    {
        if (true)
        {

        }
    }
    else if(plane.ycoordinate == 0)
    {
        if (true)
        {

        }
    }
}

