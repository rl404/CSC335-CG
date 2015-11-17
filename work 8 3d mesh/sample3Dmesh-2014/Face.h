#ifndef FACE_H_
#define FACE_H_


#include "VertexID.h"

class Face
{
public:
	Face();
	virtual ~Face();

	int nVerts;
	VertexID *vert;
};


#endif /*FACE_H_*/
