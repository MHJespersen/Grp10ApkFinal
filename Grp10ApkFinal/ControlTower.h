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
		//if (ControlTower::previousSignals.empty())
		//{
		//	cout << "test signal" << endl;
		//}
		return T(PlaneList);
	};
};

class ControlTower
{
private:
	static ControlTower* instance;
	ControlTower();
	//Liste af fly fra sidste signal. Gem kun de sidst observerede informationer
	list<Plane*> previousSignals;
	//giv adgang til private attributter

public:
	//template<typename T> friend struct PlaneCombiner;
	static ControlTower* getInstance();
	//signal med combiner
	boost::signals2::signal<Plane*(), PlaneCombiner<list<Plane*>>> connections; 
	void CheckAirspace(); //std::vector<Plane>, mutex&, mutex&
	void WriteLog();
};	