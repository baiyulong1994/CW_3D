#include"inTraingle.h"
bool inTraingle(Mesh &mesh, int id, double x, double y,double *area_coord)
{
	if (nb_ever_ele == 3)
	{
		int i, j, ele, index[3];
		double indextmp, tri_vtx[3][2];
		//变换系数矩阵 L*坐标矩阵所得矩阵的行列式即为2S
		static int L[2][3] = { { -1.0, 1.0, 0.0 }, { -1.0, 0.0, 1.0 } };
		//djt=2S
		double Jt[2][2],J1t[2][2], J2t[2][2], J3t[2][2], dJt,dJ1t, dJ2t, dJ3t;
		//遍历有限元，分别将每个单元的节点编号存入index数组中，index数组的尺寸为3
		for (i = 0; i != nb_ever_ele; ++i){
			indextmp = *(mesh.elements + (id - 1 + (i*nb_elements)));
			index[i] = indextmp;
		}
		//将节点的坐标读入tri_vtx矩阵中，改矩阵的尺寸是3*2
		//计算三角形S的面积
		for (i = 0; i<nb_ever_ele; ++i){
			for (j = 0; j<dimension; ++j){
				tri_vtx[i][j] = *(mesh.nodes + (index[i] - 1 + (j*nb_nodes)));
			}
		}
		Jt[0][0] = L[0][0] * tri_vtx[0][0] + L[0][1] * tri_vtx[1][0] + L[0][2] * tri_vtx[2][0];
		Jt[0][1] = L[0][0] * tri_vtx[0][1] + L[0][1] * tri_vtx[1][1] + L[0][2] * tri_vtx[2][1];
		Jt[1][0] = L[1][0] * tri_vtx[0][0] + L[1][1] * tri_vtx[1][0] + L[1][2] * tri_vtx[2][0];
		Jt[1][1] = L[1][0] * tri_vtx[0][1] + L[1][1] * tri_vtx[1][1] + L[1][2] * tri_vtx[2][1];

		dJt = Jt[0][0] * Jt[1][1] - Jt[0][1] * Jt[1][0];

		dJt = sqrt(dJt*dJt);
		//计算三角形S1的面积
		for (i = 0; i<nb_ever_ele; ++i){
			for (j = 0; j<dimension; ++j){
				tri_vtx[i][j] = *(mesh.nodes + (index[i] - 1 + (j*nb_nodes)));
			}
		}
		tri_vtx[0][0] = x;
		tri_vtx[0][1] = y;
		J1t[0][0] = L[0][0] * tri_vtx[0][0] + L[0][1] * tri_vtx[1][0] + L[0][2] * tri_vtx[2][0];
		J1t[0][1] = L[0][0] * tri_vtx[0][1] + L[0][1] * tri_vtx[1][1] + L[0][2] * tri_vtx[2][1];
		J1t[1][0] = L[1][0] * tri_vtx[0][0] + L[1][1] * tri_vtx[1][0] + L[1][2] * tri_vtx[2][0];
		J1t[1][1] = L[1][0] * tri_vtx[0][1] + L[1][1] * tri_vtx[1][1] + L[1][2] * tri_vtx[2][1];

		dJ1t = J1t[0][0] * J1t[1][1] - J1t[0][1] * J1t[1][0];

		dJ1t = sqrt(dJ1t*dJ1t);
		//计算三角形S2的面积
		for (i = 0; i<nb_ever_ele; ++i){
			for (j = 0; j<dimension; ++j){
				tri_vtx[i][j] = *(mesh.nodes + (index[i] - 1 + (j*nb_nodes)));
			}
		}
		tri_vtx[1][0] = x;
		tri_vtx[1][1] = y;
		J2t[0][0] = L[0][0] * tri_vtx[0][0] + L[0][1] * tri_vtx[1][0] + L[0][2] * tri_vtx[2][0];
		J2t[0][1] = L[0][0] * tri_vtx[0][1] + L[0][1] * tri_vtx[1][1] + L[0][2] * tri_vtx[2][1];
		J2t[1][0] = L[1][0] * tri_vtx[0][0] + L[1][1] * tri_vtx[1][0] + L[1][2] * tri_vtx[2][0];
		J2t[1][1] = L[1][0] * tri_vtx[0][1] + L[1][1] * tri_vtx[1][1] + L[1][2] * tri_vtx[2][1];

		dJ2t = J2t[0][0] * J2t[1][1] - J2t[0][1] * J2t[1][0];

		dJ2t = sqrt(dJ2t*dJ2t);
		//计算三角形S3的面积
		for (i = 0; i<nb_ever_ele; ++i){
			for (j = 0; j<dimension; ++j){
				tri_vtx[i][j] = *(mesh.nodes + (index[i] - 1 + (j*nb_nodes)));
			}
		}
		tri_vtx[2][0] = x;
		tri_vtx[2][1] = y;
		J3t[0][0] = L[0][0] * tri_vtx[0][0] + L[0][1] * tri_vtx[1][0] + L[0][2] * tri_vtx[2][0];
		J3t[0][1] = L[0][0] * tri_vtx[0][1] + L[0][1] * tri_vtx[1][1] + L[0][2] * tri_vtx[2][1];
		J3t[1][0] = L[1][0] * tri_vtx[0][0] + L[1][1] * tri_vtx[1][0] + L[1][2] * tri_vtx[2][0];
		J3t[1][1] = L[1][0] * tri_vtx[0][1] + L[1][1] * tri_vtx[1][1] + L[1][2] * tri_vtx[2][1];

		dJ3t = J3t[0][0] * J3t[1][1] - J3t[0][1] * J3t[1][0];

		dJ3t = sqrt(dJ3t*dJ3t);
		if (((dJ1t + dJ2t + dJ3t-dJt)/dJt)<10e-6)
		{
			area_coord[0] = dJ1t / dJt;
			area_coord[1] = dJ2t / dJt;
			area_coord[2] = dJ3t / dJt;
			return true;
		}
		else
		{
			return false;
		}
	}
}