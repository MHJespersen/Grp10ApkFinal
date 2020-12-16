#pragma once

#ifdef ControlTower_H
#define ControlTower_H
#endif 

#include "Plane.h"
#include <list>
#include <vector>
#include <mutex>
#include <boost/signals2.hpp>
#include "CalculatorCourse.h"
#include "CalculatorSpeed.h"
#include "CalculatorDistance.h"

using namespace std;

class ControlTower
{
private:
	static ControlTower* instance;
	std::vector<Plane> Planes;
	//	CalculatorDistance distanceCalc;
	//	CalculatorSpeed speedCalc;
	ControlTower();

public:
	static ControlTower* getInstance();
	boost::signals2::signal<void()> connections;
	void CheckAirspace(); //std::vector<Plane>, mutex&, mutex&
	void WriteLog();
};