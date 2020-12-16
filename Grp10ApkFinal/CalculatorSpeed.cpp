#include "CalculatorSpeed.h"

int Calculator::CalculatorSpeed::CalculateSpeed(Plane prevPlane, Plane newPlane)
{
	//first we need two different timestamps from the plane
	timeStamps = (prevPlane.timestamp - newPlane.timestamp);
	distance = distCalc.CalculateDistance(prevPlane, newPlane);
	speed = distance / timeStamps;

	if (speed < 0)
	{
		speed *= -1;
	}
	return round(speed);
}
