#include "Face.h"

Face::Face()
{
	nVerts = 3;
	vert = new VertexID[nVerts];
}

Face::~Face()
{
}
