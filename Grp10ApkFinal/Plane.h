#pragma once
#ifndef PLANE_H
#define PLANE_H
#endif

#include <iostream>
#include <string>
#include <time.h> 

class Plane
{
private:
	void FlyNorth();	
	void FlySouth();	
	void FlyEast();	
	void FlyWest();
	void PrintLocation();

public:
	Plane(std::string name, float x, float y);
	
	std::string nametag;
	float xcoordinate;
	float ycoordinate;
	float speed;
	time_t timestamp;

	void TakeOff(int Direction);
	void Land();
	Plane* operator()();
};
