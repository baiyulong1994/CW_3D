#include "insideTetrahedron.h"

bool insideTetrahedron(double *p, double *p1, double *p2, double *p3, double *p4)
{
	Eigen::Matrix4d j1;
	Eigen::Matrix4d j2;
	Eigen::Matrix4d j3;
	Eigen::Matrix4d j4;
	Eigen::Matrix4d j5;
	//矩阵初始化
	j1.setZero();
	j2.setZero();
	j3.setZero();
	j4.setZero();
	j5.setZero();
	//输入元素
	j1 << p1[0], p1[1], p1[2], 1, p2[0], p2[1], p2[2], 1, p3[0], p3[1], p3[2], 1,
		p4[0], p4[1], p4[2], 1;

	j2 << p[0], p[1], p[2], 1, p2[0], p2[1], p2[2], 1, p3[0], p3[1], p3[2], 1,
		p4[0], p4[1], p4[2], 1;

	j3 << p1[0], p1[1], p1[2], 1, p[0], p[1], p[2], 1, p3[0], p3[1], p3[2], 1,
		p4[0], p4[1], p4[2], 1;

	j4 << p1[0], p1[1], p1[2], 1, p2[0], p2[1], p2[2], 1, p[0], p[1], p[2], 1,
		p4[0], p4[1], p4[2], 1;

	j5 << p1[0], p1[1], p1[2], 1, p2[0], p2[1], p2[2], 1, p3[0], p3[1], p3[2], 1,
		p[0], p[1], p[2], 1;
	//fabs的作用是求取双精度浮点数的绝对值
	double v0 = 0.166666666666667*abs(j1.determinant());
	double tmp = 0.166666666666667* (abs(j2.determinant()) + abs(j3.determinant()) + abs(j4.determinant()) + abs(j5.determinant())) - v0;
	if (abs(tmp) / v0 < 0.000001)
	{
		return true;
		
	}
	else
		return false;
}
