#include "CalculatorDistance.h"
#include "Plane.h"

using namespace Calculator;
using namespace std;

int CalculatorDistance::CalculateDistance(Plane newPlane, Plane prevPlane)
{
	return round(sqrt(pow(prevPlane.xcoordinate - newPlane.xcoordinate, 2) + pow(prevPlane.ycoordinate - newPlane.ycoordinate, 2)));
}
