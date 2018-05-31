#ifndef _MYTSEARCHN
#define _MYTSEARCHN
#include"mesh.h"
//判断三维的点在哪个有限单元中，返回该单元的坐标和该点的节点坐标
int mytSearchN(Mesh &mesh, double *area_coord, double x, double y);
#endif