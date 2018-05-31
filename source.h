#ifndef _SOURCE_H_
#define _SOURCE_H_
//光源的数量
#include"mesh.h"
extern const int nb_source;
class Source
{
public:
	//用于存储光源节点坐标的矩阵
	double *nodes = new double[nb_source*dimension];
};
#endif
