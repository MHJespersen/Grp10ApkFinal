#pragma once

#ifndef PlaneGenerator_H
#define PlaneGenerator_H
#endif
#include "Plane.h"
#include "ControlTower.h"

namespace Airplanes
{
	class PlaneGenerator
	{
	private:
		void StartPlane(Plane plane);
		Airspace::ControlTower* control;
	public:	
		PlaneGenerator();
		void GeneratePlane();
	};
}