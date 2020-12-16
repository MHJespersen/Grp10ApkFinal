#include "PlaneGenerator.h"
#include <cstdlib>
#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.

const int NORTH = 0;
const int SOUTH = 1;
const int EAST = 2;
const int WEST = 3;

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
    const std::string name = boost::uuids::to_string(boost::uuids::random_generator()());

    Plane plane(name, x, y);

    StartPlane(plane);

    return plane; // Maybe return ptr to plan / PUB / SUB?
}

void PlaneGenerator::StartPlane(Plane plane)
{

    int ChooseRandomDirection = rand() % 1;

    // First check if plane is in corners
    if (plane.xcoordinate == 0 && plane.ycoordinate == 0)
    {
        // Fly North OR East
        if (ChooseRandomDirection)
            plane.TakeOff(NORTH);
        else 
            plane.TakeOff(EAST);
    }
    if (plane.xcoordinate == 0 && plane.ycoordinate == 9)
    {
        // Fly North OR West
        if (ChooseRandomDirection)
            plane.TakeOff(NORTH);
        else 
            plane.TakeOff(WEST);
        
    }
    if (plane.xcoordinate == 9 && plane.ycoordinate == 0)
    {
        // Fly Sout OR East
        if (ChooseRandomDirection)
            plane.TakeOff(SOUTH);
        else 
            plane.TakeOff(EAST);
    }
    if (plane.xcoordinate == 9 && plane.ycoordinate == 9)
    {
        // Fly South OR West
        if (ChooseRandomDirection)
            plane.TakeOff(SOUTH);
        else 
            plane.TakeOff(WEST);
    }

    // If plane doesnt start in corner just fly to opposite site.
    if (plane.xcoordinate == 0)
    {
        plane.TakeOff(NORTH);
    }
    if (plane.xcoordinate == 9)
    {
        plane.TakeOff(SOUTH);
    }
    if (plane.ycoordinate == 0)
    {
        plane.TakeOff(EAST);
    }
    if (plane.ycoordinate == 9)
    {
        plane.TakeOff(WEST);
    }
}

