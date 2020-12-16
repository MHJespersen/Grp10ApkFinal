#pragma once

#ifndef PlaneGenerator_H
#define PlaneGenerator_H
#endif

#include "Plane.h"


class PlaneGenerator
{
private:
	void UpdatePlaneCoordinates(Plane plane);
public:
	PlaneGenerator();
	Plane GeneratePlane();
};
