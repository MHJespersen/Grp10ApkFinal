#pragma once
#ifndef CALCULATORCOURSE_H
#define CALCULATORCOURSE_H
#endif

#include "Plane.h"
#include <math.h>


namespace Calculator{

	class CalculatorCourse{
	private:
		double pi = 2 * acos(0.0);

	public:
		double CalculateCourse(Plane prevPlane, Plane newPlane);

	};

}