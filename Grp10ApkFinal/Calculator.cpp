#include "Calculator.h"
#include "Plane.h"
#include <math.h>

using namespace std;

template<class T>
Calculator<T>::Calculator()
{
}

template<class T>
float Calculator<T>::distanceCalculator(T* newPlane, T* prevPlane)
{
	if constexpr (std::is_pointer_v<Plane*>)
		return sqrt(pow(prevPlane->xcoordinate - newPlane->xcoordinate, 2) + pow(prevPlane->ycoordinate - newPlane->ycoordinate, 2));
	else
		throw(string("Not implemented for this type!\n"));
}

template<class T>
float Calculator<T>::speedCalculator(T* newPlane, T* prevPlane)
{
	timeStamps = (prevPlane->timestamp - newPlane->timestamp);
	try
	{
		if (timeStamps == 0) throw(string("Divide by zero error!\n"));
		speed = distanceCalculator(prevPlane, newPlane) / timeStamps;

	}
	catch (const string& e)
	{
		cout << "exception caught\n" << e;
	}
	if (speed < 0)
	{
		speed *= -1;
		return speed * 315;
	}
	else
	{
		return speed * 315;
	}
}

template<class T>
float Calculator<T>::courseCalculator(T* newPlane, T* prevPlane)
{
	courseInRadians = atan2(newPlane->xcoordinate - prevPlane->xcoordinate, newPlane->ycoordinate - prevPlane->ycoordinate);
	try
	{
		if (((180 / pi) * courseInRadians) == 0) throw(string("Divide by zero error!\n"));
		degrees = (180 / pi) * courseInRadians;
	}
	catch (const string& e)
	{
		cout << "Exception caught\n" << e;
	}
	if (degrees < 0)
	{
		degrees = degrees + 360;
		return degrees;
	}
	else
	{
		return degrees;
	}
}