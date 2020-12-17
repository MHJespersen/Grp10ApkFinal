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
	//Calculator calc;
	ControlTower();

public:
	template<typename T>
	struct PlaneCombiner
	{
		typedef T result_type;

		template<typename InputIterator>
		inline T operator()(InputIterator first, InputIterator last) const
		{
			vector<Plane*> vec(first, last);
			cout << vec.size() << endl;
			if (vec.size() > 0)
			{	
				cout << "Calling from controltower" << endl;
				//WORK
			}
		};
	};

	static ControlTower* getInstance();
	boost::signals2::signal<Plane*(), PlaneCombiner<void>> connections; //signal med combiner
	void CheckAirspace(); //std::vector<Plane>, mutex&, mutex&
	void WriteLog();
};	