#ifndef _DETECTOR_H_
#define _DETECTOR_H_
#include"mesh.h"
extern const int nb_detector;
class Detector {
public:
//���ڴ洢̽�����ڵ�����ľ���
		double *nodes = new double[nb_detector*dimension];
};
#endif
