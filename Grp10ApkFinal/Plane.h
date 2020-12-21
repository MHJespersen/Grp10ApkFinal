#pragma once
#ifndef PLANE_H
#define PLANE_H
#endif

#include <iostream>
#include <string>
#include <time.h> 
#include <boost/signals2.hpp>

class Plane
{
private:
	void FlyNorth();	
	void FlySouth();	
	void FlyEast();	
	void FlyWest();
	void PrintLocation();

public:
	boost::signals2::connection connection;
	Plane(std::string name, float x, float y);
	~Plane();
	std::string nametag;
	float xcoordinate;
	float ycoordinate;
	float speed;
	time_t timestamp;
	void setConnection(boost::signals2::connection c);
	void TakeOff(int Direction);
	void Land();
	Plane* operator()();
};
