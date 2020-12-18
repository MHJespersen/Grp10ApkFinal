#pragma once
#include <math.h>
#include "Plane.h"

using namespace std;

/*
template<class T1, class T2>
int distanceCalculator(T1 newPlane, T2 prevPlane)
{
	return sqrt(pow(prevPlane.xcoordinate - newPlane.xcoordinate, 2) + pow(prevPlane.ycoordinate - newPlane.ycoordinate, 2));
}

template<class T1, class T2>
int speedCalculator(T1 newPlane, T2 prevPlane)
{
	timeStamps = (prevPlane.now - newPlane.now);
	distance = distanceCalculator(prevPlane, newPlane);
	speed = distance / timeStamps;
	if (speed < 0)
	{
		speed *= -1;
	}
	return speed;
}

template<class T1, class T2>
int courseCalculator(T1 newPlane, T2 prevPlane)
{
	courseInRadians = atan2(newPlane.xcoordinate - prevPlane.xcoordinate, newPlane.ycoordinate - prevPlane.ycoordinate);
	pi = 2 * acos(0.0);
	degrees = 180 / pi * courseInRadians;
	if (degrees < 0)
	{
		degrees = degrees + 360;
	}
	return degrees;
}
*/

template <class T>
class Calculator {
private:
	T prevPlane, newPlane;
	int timeStamps;
	float speed;
	float pi = 2 * acos(0.0);

public:
	Calculator(T prevplane, T newplane)
	{
		prevPlane = prevplane;
		newPlane = newplane;
	}

	T distanceCalculator()
	{
		return sqrt(pow(prevPlane.xcoordinate - newPlane.xcoordinate, 2) + pow(prevPlane.ycoordinate - newPlane.ycoordinate, 2));
	}

	T speedCalculator()
	{
		timeStamps = (prevPlane.timestamp - newPlane.timestamp);
		speed = distanceCalculator(prevPlane, newPlane) / timeStamps;
		if (speed < 0)
		{
			speed *= -1;
		}
		return speed;
	}

	T courseCalculator(T1 newPlane, T2 prevPlane)
	{
		courseInRadians = atan2(newPlane.xcoordinate - prevPlane.xcoordinate, newPlane.ycoordinate - prevPlane.ycoordinate);
		degrees = 180 / pi * courseInRadians;
		if (degrees < 0)
		{
			degrees = degrees + 360;
		}
		return degrees;
	}
};

