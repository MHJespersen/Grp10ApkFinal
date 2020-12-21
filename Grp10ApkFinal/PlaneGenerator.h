#pragma once

#ifndef PlaneGenerator_H
#define PlaneGenerator_H
#endif

#include "Plane.h"
#include "ControlTower.h"

class PlaneGenerator
{
private:
	void StartPlane(Plane plane);
	ControlTower* control;
public:	
	PlaneGenerator();
	void GeneratePlane();
};
