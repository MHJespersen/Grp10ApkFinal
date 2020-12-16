#include "Plane.h"
#include <boost/chrono.hpp>
#include <boost/thread/thread.hpp>


const int NORTH = 0;
const int SOUTH = 1;
const int EAST = 2;
const int WEST = 3;

Plane::Plane(std::string name, int x, int y)
{
	nametag = name;
	xcoordinate = x;
	ycoordinate = y;

	timestamp = boost::posix_time::second_clock::local_time().time_of_day().seconds();

	// Set random seed for random generator
    srand(time(NULL));
}

void Plane::TakeOff(int Direction)
{
	std::cout << "Plane: " + nametag + " has taken off." << std::endl;

	switch (Direction)
	{
	case NORTH : FlyNorth();
		break;
	case SOUTH : FlySouth();
		break;
	case EAST : FlyEast();
		break;
	case WEST : FlyWest();
		break;
	default:
		break;
	}
}

void Plane::Land()
{
	// Delete plane or give msg to subscriber that fly has landed etc
	std::cout << "Plane: " + nametag + " has landed." << std::endl;
}

void Plane::FlyNorth()
{
	// Fly north until out of airspace, then land.
	while(ycoordinate <= 9)
	{
		boost::this_thread::sleep(boost::posix_time::seconds(rand() % 5 + 1));
		ycoordinate++;
		PrintLocation();
	}
	Land();
}

void Plane::FlySouth()
{
	// Fly south until out of airspace, then land.
	while(ycoordinate >= 0)
	{
		boost::this_thread::sleep(boost::posix_time::seconds(rand() % 5 + 1));
		ycoordinate++;
		PrintLocation();
	}
	Land();
}

void Plane::FlyEast()
{
	// Fly east until out of airspace, then land.
	while(xcoordinate <= 9)
	{
		boost::this_thread::sleep(boost::posix_time::seconds(rand() % 5 + 1));
		xcoordinate++;
		PrintLocation();
	}
	Land();
}

void Plane::FlyWest()
{
	// Fly west until out of airspace, then land.
	while(xcoordinate >= 0)
	{
		boost::this_thread::sleep(boost::posix_time::seconds(rand() % 5 + 1));
		xcoordinate++;
		PrintLocation();
	}
	Land();
}

void Plane::PrintLocation()
{
	std::cout << "Plane: " + nametag << std::endl;
	std::cout << "Location: " + std::to_string(xcoordinate) + ", " + std::to_string(ycoordinate) << std::endl;
}

