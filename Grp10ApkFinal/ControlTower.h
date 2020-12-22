#pragma once

#ifdef ControlTower_H
#define ControlTower_H
#endif 

#include "Plane.h"
#include <list>
#include <boost/signals2.hpp>
#include "Calculator.h"
#include "WarningLogger.h"

using namespace std;

template<typename T>
struct PlaneCombiner
{
	typedef T result_type;

	template<typename InputIterator>
	inline T operator()(InputIterator first, InputIterator last) const
	{
		list<Plane*> PlaneList(first, last);
		return T(PlaneList);
	};
};

class ControlTower
{
private:
	static ControlTower* instance;
	ControlTower();
	list<Plane> previousSignals;
	Calculator<Plane> Calculator;
	WarningLogger logger;

public:
	void isInAirspace(list<Plane*>);
	static ControlTower* getInstance();
	//signal med combiner
	boost::signals2::signal<Plane*(), PlaneCombiner<list<Plane*>>> connections; 
	void checkAirspace();
	void checkDistance(Plane*, Plane*);
};	