#ifndef _SOURCE_H_
#define _SOURCE_H_
//��Դ������
#include"mesh.h"
extern const int nb_source;
class Source
{
public:
	//���ڴ洢��Դ�ڵ�����ľ���
	double *nodes = new double[nb_source*dimension];
};
#endif
