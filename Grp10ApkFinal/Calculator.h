#pragma once
#ifndef CALCULATOR_H
#define CALCULATOR_H
#endif
#include <future>
#include <math.h>

using namespace Airplanes;

namespace Airspace
{
	template<class T>
	class Calculator
	{
	private:
		const float pi = 2 * acos(0.0);

	public:
		Calculator();
		void distanceCalculator(std::promise<float>&& floatPromise, T* newPlane, T* prevPlane);
		//float distanceCalculator(T* newPlane, T* prevPlane);
		float speedCalculator(T* newPlane, T* prevPlane);
		float courseCalculator(T* newPlane, T* prevPlane);
	};
	template<class T>
	inline Calculator<T>::Calculator()
	{
	}
	template<class T>
	inline void Calculator<T>::distanceCalculator(std::promise<float>&& floatPromise, T* newPlane, T* prevPlane)
	{
		if constexpr (std::is_pointer<Plane*>::value)
			floatPromise.set_value(sqrt(pow(prevPlane->xcoordinate - newPlane->xcoordinate, 2) + pow(prevPlane->ycoordinate - newPlane->ycoordinate, 2)));
	}

	template<class T>
	inline float Calculator<T>::speedCalculator(T* newPlane, T* prevPlane)
	{
		if constexpr (std::is_pointer<Plane*>::value)
		{
			float speed;
			//define the promise
			std::promise<float> distPromise;
			//get the future
			std::future<float> distResult = distPromise.get_future();
			int timeStamps = (prevPlane->timestamp - newPlane->timestamp);
			try
			{
				if (timeStamps == 0) throw(std::string("Divide by zero error!\n"));
				distanceCalculator(std::move(distPromise), prevPlane, newPlane);
				speed = distResult.get() / timeStamps;

			}
			catch (const std::string& e)
			{
				std::cout << "exception caught\n" << e << std::endl;
			}
			if (speed < 0)
				speed *= -1;
			return speed * 315;
		}
	}
	template<class T>
	inline float Calculator<T>::courseCalculator(T* newPlane, T* prevPlane)
	{
		if constexpr (std::is_pointer<Plane*>::value)
		{
			float degrees;
			float courseInRadians = atan2(newPlane->xcoordinate - prevPlane->xcoordinate, newPlane->ycoordinate - prevPlane->ycoordinate);
			try
			{
				if (((180 / pi) * courseInRadians) == 0) throw(std::string("Divide by zero error!\n"));
				degrees = (180 / pi) * courseInRadians;
			}
			catch (const std::string& e)
			{
				std::cout << "Exception caught\n" << e << std::endl;
			}
			if (degrees < 0)
				degrees = degrees + 360;
			return degrees;
		}
	}
}
