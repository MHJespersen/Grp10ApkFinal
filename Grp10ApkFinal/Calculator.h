#pragma once
#include <math.h>
#include "Plane.h"

using namespace std;

template<class T>
class Calculator
{
private:
	int timeStamps;
	float speed;
	float pi = 2 * acos(0.0);
	double courseInRadians;
	double degrees;

public:
	float distanceCalculator(T* newPlane, T* prevPlane)
	{
		return sqrt(pow(prevPlane->xcoordinate - newPlane->xcoordinate, 2) + pow(prevPlane->ycoordinate - newPlane->ycoordinate, 2));
	}

	float speedCalculator(T* newPlane, T* prevPlane)
	{
		timeStamps = (prevPlane->timestamp - newPlane->timestamp);
		try {
			if(timeStamps == 0)
			{ 
				throw "Division by zero not possible!";
				speed = distanceCalculator(prevPlane, newPlane) / timeStamps;
			}
		}
		catch (char* ex)
		{
			cout << ex;
		}
		if constexpr(speed < 0)
		{
			speed *= -1;
			return speed;
		}
		else
		{
			return speed;
		}
	}

	int courseCalculator(T* newPlane, T* prevPlane)
	{
		courseInRadians = atan2(newPlane->xcoordinate - prevPlane->xcoordinate, newPlane->ycoordinate - prevPlane->ycoordinate);
		try
		{
			if ((pi * courseInRadians) == 0)
			{
				
				throw "Division by zero not possible!"
				degrees = 180 / pi * courseInRadians;
			}
		}
		catch (char* ex)
		{
			cout << ex;
		}
		if constexpr(degrees < 0)
		{
			degrees = degrees + 360;
		}
		else
		{
			return degrees;
		}
	}
};

//template <class T>
//class Calculator {
//private:
//	T prevPlane, newPlane;
//	int timeStamps;
//	float speed;
//	float pi = 2 * acos(0.0);
//
//public:
//	Calculator(T prevplane, T newplane)
//	{
//		prevPlane = prevplane;
//		newPlane = newplane;
//	}
//
//	T distanceCalculator()
//	{
//		return sqrt(pow(prevPlane.xcoordinate - newPlane.xcoordinate, 2) + pow(prevPlane.ycoordinate - newPlane.ycoordinate, 2));
//	}
//
//	T speedCalculator()
//	{
//		timeStamps = (prevPlane.timestamp - newPlane.timestamp);
//		speed = distanceCalculator(prevPlane, newPlane) / timeStamps;
//		if (speed < 0)
//		{
//			speed *= -1;
//		}
//		return speed;
//	}
//
//	T courseCalculator(T1 newPlane, T2 prevPlane)
//	{
//		courseInRadians = atan2(newPlane.xcoordinate - prevPlane.xcoordinate, newPlane.ycoordinate - prevPlane.ycoordinate);
//		degrees = 180 / pi * courseInRadians;
//		if (degrees < 0)
//		{
//			degrees = degrees + 360;
//		}
//		return degrees;
//	}
//};

