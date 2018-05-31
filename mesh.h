#include <iostream>
using namespace std;
#ifndef _MESH_H_
#define _MESH_H_
//节点数量
extern const int nb_nodes;
//有限单元数量
extern const int nb_elements;
//维数
extern const int dimension;
//每个有限单元所包含三角形的个数
extern const int nb_ever_ele;
//频率(单位Mhz)
extern const double frequency;
extern const double pi;
extern const double omega;

class Mesh{
public:
	//用于存储节点坐标的矩阵
	double *nodes=new double[nb_nodes*dimension];
	//double(*nodes)[dimension] = new double[][dimension];

	//用于存储节点标志的向量
	double *bndvtx = new double[nb_nodes];
	//用于存储吸收系数的向量
	double *mua = new double[nb_nodes];
	//用于存储散射系数向量
	double *mus = new double[nb_nodes];
	//用于存储折射率的向量
	double *ksir = new double[nb_nodes];
	//用于存储光速的向量
	double *c = new double[nb_nodes];
	//用于存储扩散系数的向量
	double *kappa = new double[nb_nodes];
	//用于存储有限元编号的矩阵
	double *elements= new double[nb_elements*nb_ever_ele];
	//用于存储单元面积的向量
	double *ele_area = new double[nb_elements];
	//用于存储节点关联单元的面积的向量
	double *support = new double[nb_nodes];
	//建立构造函数初始化成员数据
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