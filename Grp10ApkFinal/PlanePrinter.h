#pragma once
#include "Plane.h"
#include <string>
#include <iostream>
using namespace std;

class PlanePrinter
{
private:
	function<void()> hello = bind(&PlanePrinter::print, this, "Hello from variadic: ");

public:
	void print(string text)
	{
		cout << text << endl;
	}
	template <typename T>
	void printPlanes(T* plane)
	{
		if constexpr (std::is_same<Plane, T>::value)
		{
			hello();
			cout << 1 << endl;
			cout << plane->nametag << endl;
		}
		else
		{
			hello();
			cout << 2 << endl;
			cout << "Not a Plane" << endl;
		}	
	}

	template <typename T, typename... Args>
	void printPlanes(T* plane, Args... args)
	{
		if constexpr (std::is_same<Plane, T>::value)
		{
			hello();
			cout << 3 << endl;
			cout << plane->nametag << endl;
			printPlanes(args...);
		}
		else
		{
			hello();
			cout << 4 << endl;
			cout << "Not a Plane" << endl;
			printPlanes(args...);
		}
	}
};
