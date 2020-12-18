#pragma once

#ifdef ControlTower_H
#define ControlTower_H
#endif 

#include "Plane.h"
#include <list>
#include <boost/signals2.hpp>

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
			for (const Plane* plane : PlaneList)
			{
				std::cout << plane->nametag << " :: " << plane->xcoordinate << std::endl;
			}
		}
		return T(PlaneList);
	};
};

class ControlTower
{
private:
	static ControlTower* instance;
	ControlTower();
	list<Plane*> previousSignals;

public:
	static ControlTower* getInstance();
	//signal med combiner
	boost::signals2::signal<Plane*(), PlaneCombiner<list<Plane*>>> connections; 
	void CheckAirspace(); //mutex&, mutex&
	void WriteLog();
};	