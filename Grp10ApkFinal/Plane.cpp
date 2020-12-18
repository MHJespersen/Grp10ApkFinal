#include "Plane.h"
#include <thread>
#include <chrono>  
#include <ctime>

const int NORTH = 0;
const int SOUTH = 1;
const int EAST = 2;
const int WEST = 3;

const int Sleeptime = 1; // Sleeptime in seconds

Plane::Plane(std::string name, float x, float y)
{
	// Set random seed for random generator
    srand(time(NULL));

	nametag = name;
	xcoordinate = x;
	ycoordinate = y;
	speed = (float) rand() / RAND_MAX + 1; // speed as float between 1 and 2.
}

Plane::~Plane()
{
	connection.disconnect();
}

void Plane::setConnection(boost::signals2::connection c)
{
	this->connection = c;
}

void Plane::TakeOff(int Direction)
{
	std::cout << "Plane : " + nametag + " has TAKEN OFF at : " + std::to_string(xcoordinate) + ", " + std::to_string(ycoordinate) << std::endl;
	timestamp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()); 

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
	std::cout << "Plane : " + nametag + " has LANDED at : " + std::to_string(xcoordinate) + ", " + std::to_string(ycoordinate) << std::endl;
}

void Plane::FlyNorth()
{
	// Fly north until out of airspace, then land.
	while(ycoordinate <= 100)
	{
		std::this_thread::sleep_for(std::chrono::seconds(Sleeptime));
		timestamp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()); 
		ycoordinate += speed;
		PrintLocation();
	}
	Land();
}

void Plane::FlySouth()
{
	// Fly south until out of airspace, then land.
	while(ycoordinate >= 0)
	{
		std::this_thread::sleep_for(std::chrono::seconds(Sleeptime));
		timestamp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		ycoordinate -= speed;
		PrintLocation();
	}
	Land();
}

void Plane::FlyEast()
{
	// Fly east until out of airspace, then land.
	while(xcoordinate <= 100)
	{
		std::this_thread::sleep_for(std::chrono::seconds(Sleeptime));
		timestamp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()); 
		xcoordinate += speed;
		PrintLocation();
	}
	Land();
}

void Plane::FlyWest()
{
	// Fly west until out of airspace, then land.
	while(xcoordinate >= 0)
	{
		std::this_thread::sleep_for(std::chrono::seconds(Sleeptime));
		timestamp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()); 
		xcoordinate -= speed;
		PrintLocation();
	}
	Land();
}

void Plane::PrintLocation()
{
	std::cout << "Plane : " + nametag + " LOCATION : " + std::to_string(xcoordinate) + ", " + std::to_string(ycoordinate) << std::endl;
}

Plane* Plane::operator()()
{
	return this;
}


