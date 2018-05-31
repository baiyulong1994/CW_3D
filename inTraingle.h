#ifndef _INTRAINGLE_H_
#define _INTRAINGLE_H_
#include "mesh.h"
//本函数用于判断给定的点是否在坐标编号为id的有限单元中
bool inTraingle(Mesh &mesh,int id, double x, double y,double *area_coord);
#endif