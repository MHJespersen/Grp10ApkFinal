#pragma once
#include <math.h>
#ifndef CALCULATORDISTANCE_H
#define CALCULATORDISTANCE_H
#endif 
#include <boost/signals2.hpp>

class CalculatorDistance
{
public:
	int CalculateDistance(Plane prevPlane, Plane newPlane)
	{
		return round(sqrt(pow(prevPlane.x - newPlane.x, 2) + pow(prevPlane.y - newPlane.y, 2));
	}
};
