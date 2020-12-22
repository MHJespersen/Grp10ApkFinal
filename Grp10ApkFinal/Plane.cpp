#include "Plane.h"
#include <thread>
#include <chrono>  
#include <ctime>

const int NORTH = 0;
const int SOUTH = 1;
const int EAST = 2;
const int WEST = 3;

const int Sleeptime = 1; // Sleeptime in seconds

bool Plane::operator==(const Plane* other)
{
	return nametag == other->nametag;
}

Plane& Plane::operator=(const Plane* other)
{
	if (this == other)
		return *this;

	this->nametag = other->nametag;
	this->xcoordinate = other->xcoordinate;
	this->ycoordinate = other->ycoordinate;
	this->speed = other->speed;
	return *this;
}

Plane::Plane(std::string name, float x, float y)
{
	nametag = name;
	xcoordinate = x;
	ycoordinate = y;
	speed = (float) rand() / RAND_MAX + 1; // speed as float between 1 and 2.
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
	connection.disconnect();
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
	//std::cout << "Plane : " + nametag + " LOCATION : " + std::to_string(xcoordinate) + ", " + std::to_string(ycoordinate) << std::endl;
}

Plane::~Plane()
{
	//std::cout << "Destroyed " << nametag << std::endl;
}

Plane* Plane::operator()()
{
	return this;
}




