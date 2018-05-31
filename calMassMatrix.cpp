#include"calMassMatrix.h"
#include"calMass.h"

bool calMassMatrix(Mesh &mesh, int *I, int *J, double *Sr, double *Si)
{

	int nodem = nb_nodes;
	int noden = dimension;
	int elemm = nb_elements;
	int elemn = nb_ever_ele;
	int ele, i, j, index[3], k;
	double indextmp, tri_vtx[3][2];
	double bnd_index[3], kappa_index[3], mua_index[3], c_index[3];
	double k_val[3][3], c_val[3][3], b_val[3][3], f_valr[2][2];
	double ksir_index[3];
	k = 0;
	//elemm为有限元数目
	//elen为每个单元中节点的数目
	for (ele = 0; ele<elemm; ++ele) {
		for (i = 0; i<elemn; ++i) {
			indextmp = *(mesh.elements + (ele + (i*elemm)));
			index[i] = indextmp;
		}

		for (i = 0; i<elemn; ++i) {
			kappa_index[i] = *(mesh.kappa + (index[i] - 1));
			mua_index[i] = *(mesh.mua + (index[i] - 1));
			c_index[i] = omega / *(mesh.c + (index[i] - 1)) * -1;
			bnd_index[i] = *(mesh.bndvtx + (index[i] - 1));
			ksir_index[i] = *(mesh.ksir + (index[i] - 1));
			for (j = 0; j<noden; ++j) {
				tri_vtx[i][j] = *(mesh.nodes + (index[i] - 1 + (j*nodem)));
			}
		}
		gradphi(tri_vtx, kappa_index, k_val);
		phidotphi(tri_vtx, mua_index, c_val);
		phidotphi(tri_vtx, c_index, b_val);

		for (i = 0; i<3; ++i) {
			for (j = 0; j<3; ++j) {
				I[k] = index[i];
				J[k] = index[j];
				Sr[k] = k_val[j][i] + c_val[j][i];
				Si[k] = b_val[j][i];
				++k;
			}
		}


		if (bnd_index[0] + bnd_index[1] + bnd_index[2] != 0) {
			boundary_int(tri_vtx, bnd_index, ksir_index, f_valr);
			if (bnd_index[0] == 1 && bnd_index[2] == 1) {
				int index1[2];
				index1[0] = index[0];
				index1[1] = index[2];
				for (i = 0; i<2; ++i) {
					for (j = 0; j <= i; ++j) {
						I[k] = index1[i];
						J[k] = index1[j];
						Sr[k] = f_valr[i][j];
						Si[k] = 0.0;
						++k;
					}
				}
			}
			else if (bnd_index[0] == 1 && bnd_index[1] == 1) {
				int index1[2];
				index1[0] = index[0];
				index1[1] = index[1];
				for (i = 0; i<2; ++i) {
					for (j = 0; j <= i; ++j) {
						I[k] = index1[i];
						J[k] = index1[j];
						Sr[k] = f_valr[i][j];
						Si[k] = 0.0;
						++k;
					}
				}
			}
			else if (bnd_index[1] == 1 && bnd_index[2] == 1) {
				int index1[2];
				index1[0] = index[1];
				index1[1] = index[2];
				for (i = 0; i<2; ++i) {
					for (j = 0; j <= i; ++j) {
						I[k] = index1[i];
						J[k] = index1[j];
						Sr[k] = f_valr[i][j];
						Si[k] = 0.0;
						++k;
					}
				}
			}
		}


	}
	return true;
}