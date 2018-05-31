#ifndef _INSIDETETRAHEDRON
#define _INSIDETETRAHEDRON
#include "mesh.h"
#include<Eigen\Dense>
//本函数用于判断给定的点是否在坐标编号为id的有限单元中
bool insideTetrahedron(double *p, double *p1,double *p2,double *p3,double *p4);
#endif