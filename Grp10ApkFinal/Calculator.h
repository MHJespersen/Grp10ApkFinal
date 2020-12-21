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
	float courseInRadians;
	float degrees;

public:
	auto distanceCalculator(T* newPlane, T* prevPlane)
	{
		if constexpr(std::is_pointer_v<T>)
			return *sqrt(pow(prevPlane->xcoordinate - newPlane->xcoordinate, 2) + pow(prevPlane->ycoordinate - newPlane->ycoordinate, 2));
		else
			return sqrt(pow(prevPlane->xcoordinate - newPlane->xcoordinate, 2) + pow(prevPlane->ycoordinate - newPlane->ycoordinate, 2));
	}

	float speedCalculator(T* newPlane, T* prevPlane)
	{
		timeStamps = (prevPlane->timestamp - newPlane->timestamp);
		try 
		{
			if (timeStamps == 0) throw(string("Divide by zero error!\n"));
			speed = distanceCalculator(prevPlane, newPlane) / timeStamps;
			
		}
		catch (const string &e)
		{
			cout << "exception caught\n" << e;
		}
		if (speed < 0)
		{
			speed *= -1;
			return speed;
		}
		else
		{
			return speed;
		}
	}

	float courseCalculator(T* newPlane, T* prevPlane)
	{
		courseInRadians = atan2(newPlane->xcoordinate - prevPlane->xcoordinate, newPlane->ycoordinate - prevPlane->ycoordinate);
		try
		{
			if (((180 / pi) * courseInRadians) == 0) throw(string("Divide by zero error!\n"));
			degrees = (180 / pi) * courseInRadians;
		}
		catch (const string &e)
		{
			cout << "Exception caught\n" << e;
		}
		if(degrees < 0)
		{
			degrees = degrees + 360;
			return degrees;
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

