#include <cstdlib>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <thread>
#include "PlaneGenerator.h"
#include "ControlTower.h"

using namespace std;
namespace Airplanes
{
    const int NORTH = 0;
    const int SOUTH = 1;
    const int EAST = 2;
    const int WEST = 3;

    PlaneGenerator::PlaneGenerator()
    {
        // Set random seed for random generator
        control = Airspace::ControlTower::getInstance();
        srand(time(NULL));
    }

    void PlaneGenerator::GeneratePlane()
    {
        while (true)
        {
            if (control->connections.num_slots() < 6)
            {
                // Determine which axis to start on
                bool axis = rand() % 2; // Random true or false. false = x, true = y
                // Determine which side to start
                bool startAtEnd = rand() % 2; // Random true or false. false = start, true = end

                float x;
                float y;

                // If start on y-axis
                if (axis)
                {
                    x = 0;
                    y = rand() % 100; // random number between 0 - 100;
                    if (startAtEnd)
                    {
                        x = 100;
                    }
                }
                else // else start on x-axis
                {
                    x = rand() % 100; // random number between 0 - 100;
                    y = 0;
                    if (startAtEnd)
                    {
                        y = 100;
                    }
                }
                // Generate unique name
                const std::string name = boost::uuids::to_string(boost::uuids::random_generator()());

                Plane plane(name, x, y);
                std::thread(&PlaneGenerator::StartPlane, this, plane).detach();
            }
            // Wait n seconds before running again
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }

    void PlaneGenerator::StartPlane(Plane plane)
    {
        bool ChooseRandomDirection = rand() % 2;
        boost::signals2::connection c = control->connections.connect(std::ref(plane));
        plane.setConnection(c);
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
}