#pragma once
#include <math.h>
#ifndef CALCULATORDISTANCE_H
#define CALCULATORDISTANCE_H
#endif 
#include "Plane.h"

namespace Calculations {
	class CalculatorDistance
	{
	public:
		int CalculateDistance(Plane prevPlane, Plane newPlane)
		{
			return round(sqrt(pow(prevPlane.xcoordinate - newPlane.xcoordinate, 2) + pow(prevPlane.ycoordinate - newPlane.ycoordinate, 2)));
		}
	};
}