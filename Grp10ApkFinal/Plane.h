#pragma once
#ifndef PLANE_H
#define PLANE_H
#endif

#include <iostream>
#include <string>
#include <time.h> 
#include <boost/signals2.hpp>

namespace Airplanes
{
	class Plane
	{
	private:
		void FlyNorth();	
		void FlySouth();	
		void FlyEast();	
		void FlyWest();
		void PrintLocation();
		void Land();
		float speed;
		boost::signals2::connection connection;
	public:
		bool operator==(const Plane* other);
		Plane& operator=(const Plane* other);
		Plane(std::string name, float x, float y);
		~Plane();
		std::string nametag;
		float xcoordinate;
		float ycoordinate;
		time_t timestamp;
		void setConnection(boost::signals2::connection c);
		void TakeOff(int Direction);
		Plane* operator()();
	};
}