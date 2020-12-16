#pragma once

#include "Plane.h"

#ifndef CALCULATORDISTANCE_H
#define CALCULATORDISTANCE_H
#endif 

namespace Calculator{
	class CalculatorDistance
	{
	public:
		int CalculateDistance(Plane prevPlane, Plane newPlane);
	};
}