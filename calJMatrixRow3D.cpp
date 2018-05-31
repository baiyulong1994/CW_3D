#include"calJMatrixRow3D.h"
bool calJMatrixRow(Mesh &mesh, double *dphi, double *aphi, double *jr)
{
	int ele, i, j, k, index[4];
	double indextmp, val;
	int nodem = nb_nodes;
	int noden = dimension;
	int elemm = nb_elements;
	int elemn = nb_ever_ele;
	for (ele = 0; ele<elemm; ++ele)
	{
		for (i = 0; i<elemn; ++i)
		{
			indextmp = *(mesh.elements + (ele + (i*elemm)));
			index[i] = indextmp - 1;
		}

		for (i = 0; i<4; ++i)
		{
			for (j = 0; j<4; ++j)
			{
				for (k = 0; k<4; ++k)
				{
					val = IntFFF3D(i, j, k)* *(mesh.ele_area + ele);
					jr[index[i]] += ((*(dphi + index[k]) * *(aphi + index[j])))*val;
				}
			}
		}
	}
	return true;
}