#pragma once

#ifndef PlaneGenerator_H
#define PlaneGenerator_H
#endif

#include "Plane.h"


class PlaneGenerator
{
private:
	void StartPlane(Plane plane);
public:
	PlaneGenerator();
	Plane GeneratePlane();
};
