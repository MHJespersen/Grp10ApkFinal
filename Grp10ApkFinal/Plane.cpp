#include "Plane.h"


Plane::Plane(std::string name, int x, int y)
{
	nametag = name;
	xcoordinate = x;
	ycoordinate = y;
}

void Plane::TakeOff()
{
}

void Plane::Land()
{
}

void Plane::operator()()
{
	std::cout << "Calling from : " << nametag << std::endl;
}

