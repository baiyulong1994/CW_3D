#ifndef _INSIDETETRAHEDRON
#define _INSIDETETRAHEDRON
#include "mesh.h"
#include<Eigen\Dense>
//�����������жϸ����ĵ��Ƿ���������Ϊid�����޵�Ԫ��
bool insideTetrahedron(double *p, double *p1,double *p2,double *p3,double *p4);
#endif