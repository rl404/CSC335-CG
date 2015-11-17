#ifndef MESH_H_
#define MESH_H_

#include "Vector3d.h"
#include "Point3d.h"
#include "Face.h"
#include "VertexID.h"

class Mesh
{
public:
	Mesh();
	virtual ~Mesh();

public:
	int numVerts;
	Point3d *pt;
	int numNormals;
	Vector3d *norm;
	int numFaces;
	Face *face;
};

#endif /*MESH_H_*/
