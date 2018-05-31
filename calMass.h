#ifndef _CALMASS_H_
#define _CALMASS_H_
#include<iostream>
using namespace std;
void gradphi(double g[3][2], double kappa[3], double val[3][3]);

void phidotphi(double g[3][2], double mua[3], double val[3][3]);

void boundary_int(double g[3][2], double bnd_index[3], double ksir[3], double valr[2][2]);

void bound2(double g[2][2], int il, int im, double ksir[2], double *val);
#endif
