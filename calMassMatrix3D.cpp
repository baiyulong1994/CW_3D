#include"calMassMatrix3D.h"
#include"calMass3D.h"
bool calMassMatrix3D(Mesh &mesh, int *I, int *J, double *Sr)
{
	int nodem = nb_nodes;
	int noden = dimension;
	int elemm = nb_elements;
	int elemn = nb_ever_ele;
	int ele, i, j, index[4], k;
	double indextmp, tri_vtx[4][3];
	double bnd_index[4], kappa_index[4], mua_index[4], c_index[4];
	double k_val[4][4], c_val[4][4], b_val[4][4], f_valr;
	double ksir_index[4];
	k = 0;
	for (ele = 0; ele<elemm; ++ele){
		for (i = 0; i<elemn; ++i){
			indextmp = *(mesh.elements + (ele + (i*elemm)));
			index[i] = indextmp;
		}

		for (i = 0; i<elemn; ++i){
			kappa_index[i] = *(mesh.kappa + (index[i] - 1));
			mua_index[i] = *(mesh.mua + (index[i] - 1));
			//c_index[i] = omega / *(mesh.c + (index[i] - 1)) * -1;
			bnd_index[i] = *(mesh.bndvtx + (index[i] - 1));
			ksir_index[i] = *(mesh.ksir + (index[i] - 1));
			for (j = 0; j<noden; ++j){
				tri_vtx[i][j] = *(mesh.nodes + (index[i] - 1 + (j*nodem)));
			}
		}
		gradphi(tri_vtx, kappa_index, k_val);
		phidotphi(tri_vtx, mua_index, c_val);
		f_valr = 0.0;

		/*    mexPrintf("%g %g %g %g\n %g %g %g %g\n %g %g %g %g\n%g %g %g %g\n", \
		k_val[0][0], k_val[0][1],k_val[0][2], k_val[0][3], \
		k_val[1][0], k_val[1][1],k_val[1][2], k_val[1][3], \
		k_val[2][0], k_val[2][1],k_val[2][2], k_val[2][3], \
		k_val[3][0], k_val[3][1],k_val[3][2], k_val[3][3]);*/
		/*    mexPrintf("%g %g %g %g\n %g %g %g %g\n %g %g %g %g\n%g %g %g %g\n", \
		c_val[0][0], c_val[0][1],c_val[0][2], c_val[0][3], \
		c_val[1][0], c_val[1][1],c_val[1][2], c_val[1][3], \
		c_val[2][0], c_val[2][1],c_val[2][2], c_val[2][3], \
		c_val[3][0], c_val[3][1],c_val[3][2], c_val[3][3]);*/
		/*    mexPrintf("%g %g %g %g\n %g %g %g %g\n %g %g %g %g\n%g %g %g %g\n", \
		b_val[0][0], b_val[0][1],b_val[0][2], b_val[0][3], \
		b_val[1][0], b_val[1][1],b_val[1][2], b_val[1][3], \
		b_val[2][0], b_val[2][1],b_val[2][2], b_val[2][3], \
		b_val[3][0], b_val[3][1],b_val[3][2], b_val[3][3]);*/

		for (i = 0; i<4; ++i){
			for (j = 0; j<4; ++j){
				if (bnd_index[0] + bnd_index[1] + bnd_index[2] + bnd_index[3] != 0){
					boundary_int(tri_vtx, bnd_index, ksir_index, 
						&i, &j, &f_valr);
				}
				I[k] = index[i];
				J[k] = index[j];
				Sr[k] = k_val[j][i] + c_val[j][i] + f_valr;
				++k;
			}
		}

	}
	return true;
}