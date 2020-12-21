#pragma once

#ifdef ControlTower_H
#define ControlTower_H
#endif 

#include "Plane.h"
#include <list>
#include <boost/signals2.hpp>
#include "Calculator.h"

using namespace std;

template<typename T>
struct PlaneCombiner
{
	typedef T result_type;

	template<typename InputIterator>
	inline T operator()(InputIterator first, InputIterator last) const
	{
		list<Plane*> PlaneList(first, last);
		if (!PlaneList.empty())
		{
			//for (auto c = PlaneList.cbegin(), p = PlaneList.cbegin();
			//	c != PlaneList.cend() && p != PlaneList.cend(); ++c, ++p)
			//{
			//	cout << (*c)->nametag << " position x: " << (*c)->xcoordinate << " postion y: " << (*c)->ycoordinate << endl;
			//}
		}
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

public:
	bool isInAirspace(list<Plane*>);
	static ControlTower* getInstance();
	//signal med combiner
	boost::signals2::signal<Plane*(), PlaneCombiner<list<Plane*>>> connections; 
	void CheckAirspace();
	void WriteLog();
};	