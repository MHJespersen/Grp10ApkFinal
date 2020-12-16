#pragma once
#ifndef CALCULATORSPEED_H
#define CALCULATORSPEED_H
#endif

#include "CalculatorDistance.h"
#include "Plane.h"

namespace Calculations{
	class CalculatorSpeed
	{
	private:
		int distance;
		int speed;
		int timeStamps;
		CalculatorDistance distCalc;

	public:
		int CalculateSpeed(Plane prevPlane, Plane newPlane)
		{
			//first we need two different timestamps from the plane
			timeStamps = (prevPlane.now - newPlane.now);
			distance = distCalc.CalculateDistance(prevPlane, newPlane);
			speed = distance / timeStamps;

			if (speed < 0)
			{
				speed *= -1;
			}
			return round(speed);
		}

	};
}