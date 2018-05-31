#ifndef _MYTSEARCHN3D_H_
#define _MYTSEARCHN3D_H_
#include<algorithm>
#include<functional>
#include"mesh.h"
#include"insideTetrahedron.h"
int mytSearchN3D(Mesh &mesh, double *volume_coord, double x, double y,double z);
#endif