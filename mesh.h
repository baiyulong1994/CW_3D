#include <iostream>
using namespace std;
#ifndef _MESH_H_
#define _MESH_H_
//�ڵ�����
extern const int nb_nodes;
//���޵�Ԫ����
extern const int nb_elements;
//ά��
extern const int dimension;
//ÿ�����޵�Ԫ�����������εĸ���
extern const int nb_ever_ele;
//Ƶ��(��λMhz)
extern const double frequency;
extern const double pi;
extern const double omega;

class Mesh{
public:
	//���ڴ洢�ڵ�����ľ���
	double *nodes=new double[nb_nodes*dimension];
	//double(*nodes)[dimension] = new double[][dimension];

	//���ڴ洢�ڵ��־������
	double *bndvtx = new double[nb_nodes];
	//���ڴ洢����ϵ��������
	double *mua = new double[nb_nodes];
	//���ڴ洢ɢ��ϵ������
	double *mus = new double[nb_nodes];
	//���ڴ洢�����ʵ�����
	double *ksir = new double[nb_nodes];
	//���ڴ洢���ٵ�����
	double *c = new double[nb_nodes];
	//���ڴ洢��ɢϵ��������
	double *kappa = new double[nb_nodes];
	//���ڴ洢����Ԫ��ŵľ���
	double *elements= new double[nb_elements*nb_ever_ele];
	//���ڴ洢��Ԫ���������
	double *ele_area = new double[nb_elements];
	//���ڴ洢�ڵ������Ԫ�����������
	double *support = new double[nb_nodes];
	//�������캯����ʼ����Ա����
	Mesh()
	{
		memset(nodes, 0, sizeof(nodes));
		memset(mua, 0, sizeof(mua));
		memset(mus, 0, sizeof(mus));
		memset(ksir, 0, sizeof(ksir));
		memset(c, 0, sizeof(c));
		memset(kappa, 0, sizeof(kappa));
		memset(elements, 0, sizeof(elements));
		memset(ele_area, 0, sizeof(ele_area));
		memset(support, 0, sizeof(support));

	}

};
#endif