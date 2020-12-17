#pragma once
#include <math.h>
#include "Plane.h"

using namespace std;

/*
template <typename T1, typename T2>
class Calculator {
public:
	Calculator(T1 Plane::newPlane, T2 Plane::prevPlane);
	Calculator(const Calculator<T1, T2>& otherCalculator);
	void setValue1(T1 Plane::newPlane);
	void setValue2(T2 Plane::prevPlane);
	T1 calculateDistance();
	T1 calculateSpeed();
	T1 calculateCourse();

private:
	T1 newplane;
	T2 prevplane;
	double pi = 2 * acos(0.0);
};

template <typename T1, typename T2>
Calculator<T1, T2>::Calculator(T1 newPlane, T2 prevPlane):newplane(newPlane), prevplane(prevPlane)
{}

template <typename T1, typename T2>
Calculator<T1, T2>::Calculator(const Calculator<T1, T2>& otherCalculator)
	:newplane(otherCalculator.newplane), prevplane(otherCalculator.prevplane)
{}

template <typename T1, typename T2>
void Calculator<T1, T2>::setValue1(T1 newPlane) {
	newplane = newPlane;
}

template <typename T1, typename T2>
void Calculator<T1, T2>::setValue2(T2 prevPlane) {
	prevplane = prevPlane;
}

template <typename T1, typename T2>
T1 Calculator<T1, T2>::calculateDistance() {
	T1 result = sqrt(pow(prevplane.xcoordinate - newplane.xcoordinate, 2) + pow(prevplane.ycoordinate - newplane.ycoordinate, 2));
	return result;
}

template <typename T1, typename T2>
T1 Calculator<T1, T2>::calculateSpeed() {
	int timeStamps = (prevplane.now - newplane.now);
	int distance = calculateDistance(newplane, prevplane);
	speed = distance / timeStamps;
	if (speed < 0)
	{
		speed *= -1;
	}
	T1 result = speed;
	return result;
}

template <typename T1, typename T2>
T1 Calculator<T1, T2>::calculateCourse() {
	double courseInRadians = atan2(newplane.xcoordinate - prevplane.xcoordinate, newplane.ycoordinate - prevplane.ycoordinate);
	T1 result = 180 / pi * courseInRadians;
	if (result < 0)
	{
		result = result + 360;
	}
	return result;
}

*/

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

template<class T>
void TagTester(T obj)
{
	std::cout << obj.nametag << std::endl;
}
template<class T>
void xTester(T obj)
{
	std::cout << obj.xcoordinate << std::endl;
}

