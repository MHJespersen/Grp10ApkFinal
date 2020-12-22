#pragma once
#include "Plane.h"
#include <string>
#include <iostream>
using namespace std;

class PlanePrinter
{
private:

public:
	template <typename T>
	void printPlanes(T* plane)
	{
		if constexpr (std::is_same<Plane, T>::value)
		{
			cout << "Hello from variadic 1" << endl;
			cout << plane->nametag << endl;

		}
		else
		{
			cout << "Hello from variadic 2" << endl;
			cout << "Not a Plane" << endl;
		}	
	}

	template <typename T, typename... Args>
	void printPlanes(T* plane, Args... args)
	{
		if constexpr (std::is_same<Plane, T>::value)
		{
			cout << "Hello from variadic 3" << endl;
			cout << plane->nametag << endl;
			printPlanes(args...);
		}
		else
		{
			cout << "Hello from variadic 4" << endl;
			cout << "Not a Plane" << endl;
			printPlanes(args...);
		}
	}
};
