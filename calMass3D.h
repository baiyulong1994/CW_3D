#ifndef _CALMASS3D_H_
#define _CALMASS3D_H_
#include<iostream>
using namespace std;

void gradphi(double g[4][3], double kappa[4], double val[4][4]);

void phidotphi(double g[4][3], double mua[4], double val[4][4]);

void boundary_int(double gg[4][3], double bnd_index[4], 
	double ksir[4], int *ii, int *jj,
	double *valr);
#endif
