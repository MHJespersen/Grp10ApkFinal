#include "PlaneGenerator.h"
#include <cstdlib>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <thread>
#include "ControlTower.h"
const int NORTH = 0;
const int SOUTH = 1;
const int EAST = 2;
const int WEST = 3;

PlaneGenerator::PlaneGenerator()
{
    // Set random seed for random generator
    srand(time(NULL));
}

void PlaneGenerator::GeneratePlane()
{
    ControlTower* control = ControlTower::getInstance();
    // Determine which axis to on
    bool axis = rand() % 1; // Random true or false. false = x, true = y
    // Determine which side to start
    bool startAtEnd = rand() % 1; // Random true or false. false = start, true = end

    int x;
    int y;

    // If start on y-axis
    if(axis)
    {
        x = 0;
        y = rand() % 100; // random number between 0 - 100;
        if(startAtEnd)
        {
            x = 100;
        }
    }    
    else // else start on x-axis
    {
        x = rand() % 100; // random number between 0 - 100;
        y = 0;
        if(startAtEnd)
        {
            y = 100;
        }
    }     

    // Generate unique name
    const std::string name = boost::uuids::to_string(boost::uuids::random_generator()());

    Plane plane(name, x, y);
    control->connections.connect(plane);
    StartPlane(plane);
}

void PlaneGenerator::StartPlane(Plane plane)
{

    bool ChooseRandomDirection = rand() % 1;

    // First check if plane is in corners
    if (plane.xcoordinate == 0 && plane.ycoordinate == 0)
    {
        // Fly North OR East
        if (ChooseRandomDirection)
            plane.TakeOff(NORTH);
        else 
            plane.TakeOff(EAST);
    }
    if (plane.xcoordinate == 0 && plane.ycoordinate == 100)
    {
        // Fly North OR West
        if (ChooseRandomDirection)
            plane.TakeOff(NORTH);
        else 
            plane.TakeOff(WEST);
        
    }
    if (plane.xcoordinate == 100 && plane.ycoordinate == 0)
    {
        // Fly Sout OR East
        if (ChooseRandomDirection)
            plane.TakeOff(SOUTH);
        else 
            plane.TakeOff(EAST);
    }
    if (plane.xcoordinate == 100 && plane.ycoordinate == 100)
    {
        // Fly South OR West
        if (ChooseRandomDirection)
            plane.TakeOff(SOUTH);
        else 
            plane.TakeOff(WEST);
    }

    // If plane doesnt start in corner just fly to opposite site.
    if (plane.ycoordinate == 0)
    {
        plane.TakeOff(NORTH);
    }
    if (plane.ycoordinate == 100)
    {
        plane.TakeOff(SOUTH);
    }
    if (plane.xcoordinate == 0)
    {
        plane.TakeOff(EAST);
    }
    if (plane.xcoordinate == 100)
    {
        plane.TakeOff(WEST);
    }
}

