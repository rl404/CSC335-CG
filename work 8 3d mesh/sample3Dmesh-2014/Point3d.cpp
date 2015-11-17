#include "Point3d.h"

Point3d::Point3d()
{
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

Point3d::Point3d(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Point3d::~Point3d()
{
}
