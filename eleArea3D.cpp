#include"eleArea3D.h"
void eleArea3D(Mesh &mesh)
{
	int nodem = nb_nodes;
	int noden = dimension;
	int elemm = nb_elements;
	int elemn = nb_ever_ele;
	int i, j, k, ele, index[4];
	double indextmp, tri_vtx[4][3];
	static int L[3][4] = { { -1.0, 1.0, 0.0, 0.0 }, { -1.0, 0.0, 1.0, 0.0 }, { -1.0, 0.0, 0.0, 1.0 } };
	double Jt[3][3], dJt;
	k = 0;
	for (ele = 0; ele < elemm; ++ele)
	{
		for (i = 0; i < elemn; ++i)
		{
			indextmp = *(mesh.elements + (ele + (i*elemm)));
			index[i] = indextmp;
		}
		for (i = 0; i < elemn; ++i)
		{
			for (j = 0; j < noden; ++j)
			{
				tri_vtx[i][j] = *(mesh.nodes + (index[i] - 1 + (j*nodem)));
			}
		}

		Jt[0][0] = L[0][0] * tri_vtx[0][0] + L[0][1] * tri_vtx[1][0] + L[0][2] * tri_vtx[2][0] + L[0][3] * tri_vtx[3][0];
		Jt[0][1] = L[0][0] * tri_vtx[0][1] + L[0][1] * tri_vtx[1][1] + L[0][2] * tri_vtx[2][1] + L[0][3] * tri_vtx[3][1];
		Jt[0][2] = L[0][0] * tri_vtx[0][2] + L[0][1] * tri_vtx[1][2] + L[0][2] * tri_vtx[2][2] + L[0][3] * tri_vtx[3][2];
		Jt[1][0] = L[1][0] * tri_vtx[0][0] + L[1][1] * tri_vtx[1][0] + L[1][2] * tri_vtx[2][0] + L[1][3] * tri_vtx[3][0];
		Jt[1][1] = L[1][0] * tri_vtx[0][1] + L[1][1] * tri_vtx[1][1] + L[1][2] * tri_vtx[2][1] + L[1][3] * tri_vtx[3][1];
		Jt[1][2] = L[1][0] * tri_vtx[0][2] + L[1][1] * tri_vtx[1][2] + L[1][2] * tri_vtx[2][2] + L[1][3] * tri_vtx[3][2];
		Jt[2][0] = L[2][0] * tri_vtx[0][0] + L[2][1] * tri_vtx[1][0] + L[2][2] * tri_vtx[2][0] + L[2][3] * tri_vtx[3][0];
		Jt[2][1] = L[2][0] * tri_vtx[0][1] + L[2][1] * tri_vtx[1][1] + L[2][2] * tri_vtx[2][1] + L[2][3] * tri_vtx[3][1];
		Jt[2][2] = L[2][0] * tri_vtx[0][2] + L[2][1] * tri_vtx[1][2] + L[2][2] * tri_vtx[2][2] + L[2][3] * tri_vtx[3][2];

		dJt = Jt[0][0] * (Jt[1][1] * Jt[2][2] - Jt[1][2] * Jt[2][1]) \
			- Jt[1][0] * (Jt[0][1] * Jt[2][2] - Jt[0][2] * Jt[2][1]) \
			+ Jt[2][0] * (Jt[0][1] * Jt[1][2] - Jt[0][2] * Jt[1][1]);

		dJt = sqrt(dJt*dJt);

		mesh.ele_area[k] = dJt / 6;
		++k;
	}
}