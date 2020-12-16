#pragma once
#ifndef PLANE_H
#define PLANE_H
#endif

#include <iostream>
#include <string>

class Plane
{
private:

public:
	Plane(std::string name, int x, int y);
	
	std::string nametag;
	int xcoordinate;
	int ycoordinate;

	void TakeOff();
	void Land();
};
