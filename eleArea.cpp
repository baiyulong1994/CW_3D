#include"eleArea.h"
double eleArea(Mesh &mesh,int id)
{
	if (nb_ever_ele == 3){
		int i, j, ele, index[3];
		double indextmp, tri_vtx[3][2];
		//变换系数矩阵 L*坐标矩阵所得矩阵的行列式即为2S
		static int L[2][3] = { { -1.0, 1.0, 0.0 }, { -1.0, 0.0, 1.0 } };
		//djt=2S
		double Jt[2][2], dJt;
		//遍历有限元，分别将每个单元的节点编号存入index数组中，index数组的尺寸为3
			for (i = 0; i!=nb_ever_ele; ++i){
				indextmp = *(mesh.elements + (id-1 + (i*nb_elements)));
				index[i] = indextmp;
			}
			//将节点的坐标读入tri_vtx矩阵中，改矩阵的尺寸是3*2
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

			return dJt*0.5;
		}
	}