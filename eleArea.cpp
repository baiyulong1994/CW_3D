#include"eleArea.h"
double eleArea(Mesh &mesh,int id)
{
	if (nb_ever_ele == 3){
		int i, j, ele, index[3];
		double indextmp, tri_vtx[3][2];
		//�任ϵ������ L*����������þ��������ʽ��Ϊ2S
		static int L[2][3] = { { -1.0, 1.0, 0.0 }, { -1.0, 0.0, 1.0 } };
		//djt=2S
		double Jt[2][2], dJt;
		//��������Ԫ���ֱ�ÿ����Ԫ�Ľڵ��Ŵ���index�����У�index����ĳߴ�Ϊ3
			for (i = 0; i!=nb_ever_ele; ++i){
				indextmp = *(mesh.elements + (id-1 + (i*nb_elements)));
				index[i] = indextmp;
			}
			//���ڵ���������tri_vtx�����У��ľ���ĳߴ���3*2
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