#ifndef _DETECTOR_H_
#define _DETECTOR_H_
#include"mesh.h"
extern const int nb_detector;
class Detector {
public:
//用于存储探测器节点坐标的矩阵
		double *nodes = new double[nb_detector*dimension];
};
#endif
