#include "PlaneGenerator.h"
#include <cstdlib>


Plane PlaneGenerator::GeneratePlane()
{
    // Set random seed
    srand(time(NULL));

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
            x = 10;
        }
    }    
    else // if x-axis
    {
        x = rand() % 10; // random number between 0 - 10;
        y = 0;
        if(startAtEnd)
        {
            x = 10;
        }
    }     

    std::string name = "test";

    Plane plane(name, x, y);

    return plane;
}

