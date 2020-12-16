#pragma once
#ifndef PLANE_H
#define PLANE_H
#endif

#include <iostream>
#include <string>
#include <ctime>

class Plane
{
private:

public:
	Plane(std::string name, int x, int y);
	
	std::string nametag;
	int xcoordinate;
	int ycoordinate;
	time_t now = time(0);

	void TakeOff();
	void Land();
	void operator()();
};
