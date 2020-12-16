#include "CalculatorCourse.h"

double Calculator::CalculatorCourse::CalculateCourse(Plane prevPlane, Plane newPlane)
{
	double courseInRadians = atan2(newPlane.xcoordinate - prevPlane.xcoordinate, newPlane.ycoordinate - prevPlane.ycoordinate);
	double degrees = 180 / pi * courseInRadians;
	if (degrees < 0)
	{
		degrees = degrees + 360;
	}
	return degrees;
}
