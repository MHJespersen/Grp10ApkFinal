#pragma once
#ifndef PLANE_H
#define PLANE_H
#endif

#include <iostream>
#include <string>

class Plane
{
private:
	int xcoordinate;
	int ycoordinate;
	std::string nametag;

public:
	Plane(std::string name, int x, int y)
	{
		nametag = name;
		xcoordinate = x;
		ycoordinate = y;
	}
	void UpdateCoordinates(int x, int y)
	{
		xcoordinate = x;
		ycoordinate = y;
	}
	void TakeOff();
	void Land();
};
