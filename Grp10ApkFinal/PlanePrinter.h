#pragma once
#include "Plane.h"
#include <string>
#include <iostream>
using namespace std;

string operator"" _val(long double val)
{
	string res = "template version: " + to_string(val);
	return res;
};

class PlanePrinter
{
private:
	function<void()> sayHello = bind(&PlanePrinter::print, this, "Hello from variadic: ");
	void print(string text)
	{
		cout << text << endl;
	}
public:
	template <typename T>
	void printPlanes(T* plane)
	{
		if constexpr (std::is_same<Plane, T>::value)
		{
			sayHello();
			cout << 1.0_val << endl;
			cout << plane->nametag << endl;
		}
		else
		{
			sayHello();
			cout << 2.0_val << endl;
			cout << "Not a Plane" << endl;
		}	
	}

	template <typename T, typename... Args>
	void printPlanes(T* plane, Args... args)
	{
		if constexpr (std::is_same<Plane, T>::value)
		{
			sayHello();
			cout << 3.0_val << endl;
			cout << plane->nametag << endl;
			printPlanes(args...);
		}
		else
		{
			sayHello();
			cout << 4.0_val << endl;
			cout << "Not a Plane" << endl;
			printPlanes(args...);
		}
	}
};
