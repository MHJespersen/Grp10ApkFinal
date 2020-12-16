#pragma once
#ifndef CALCULATORSPEED_H
#define CALCULATORSPEED_H
#endif
#include "Plane.h"
#include "CalculatorDistance.h"

namespace Calculator{
	class CalculatorSpeed
	{
	private:
		int distance;
		int speed;
		int timeStamps;
		CalculatorDistance distCalc;

	public:
		int CalculateSpeed(Plane prevPlane, Plane newPlane);

	};
}