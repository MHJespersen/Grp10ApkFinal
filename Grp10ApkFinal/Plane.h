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
	void TakeOff();
	void Land();
};
