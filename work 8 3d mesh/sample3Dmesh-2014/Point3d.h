#ifndef POINT3D_H_
#define POINT3D_H_

class Point3d
{
public:
	Point3d();
	Point3d(float x, float y, float z);
	virtual ~Point3d();
	
	float x;
	float y;
	float z;
};

#endif /*POINT3D_H_*/
