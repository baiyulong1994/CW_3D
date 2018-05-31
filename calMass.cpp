#include"calMass.h"
void gradphi(double g[3][2], double kappa[3], double val[3][3])
{
	int ii, jj;
	static int L[2][3] = { { -1.0,1.0,0.0 }, \
	{-1.0,0.0,1.0} };
	static double w[3] = { 1.0 / 6.0,1.0 / 6.0,1.0 / 6.0 };
	static double ip[3][2] = { { 1.0 / 2.0,0.0 },{ 1.0 / 2.0,1.0 / 2.0 },{ 0.0,1.0 / 2.0 } };
	double Jt[2][2], dJt, iJt[2][2], S[3], G[2][3], GG[3][3], tmp;
	double x0 = g[0][0]; double x1 = g[1][0];
	double x2 = g[2][0];
	double y0 = g[0][1]; double y1 = g[1][1];
	double y2 = g[2][1];
	double k0 = kappa[0]; double k1 = kappa[1];
	double k2 = kappa[2];

	Jt[0][0] = L[0][0] * x0 + L[0][1] * x1 + L[0][2] * x2;
	Jt[0][1] = L[0][0] * y0 + L[0][1] * y1 + L[0][2] * y2;
	Jt[1][0] = L[1][0] * x0 + L[1][1] * x1 + L[1][2] * x2;
	Jt[1][1] = L[1][0] * y0 + L[1][1] * y1 + L[1][2] * y2;

	dJt = (Jt[0][0] * Jt[1][1]) - (Jt[0][1] * Jt[1][0]);

	iJt[0][0] = +(Jt[1][1]) / dJt;
	iJt[0][1] = -(Jt[0][1]) / dJt;
	iJt[1][0] = -(Jt[1][0]) / dJt;
	iJt[1][1] = +(Jt[0][0]) / dJt;

	dJt = sqrt(dJt*dJt);

	G[0][0] = iJt[0][0] * L[0][0] + iJt[0][1] * L[1][0];
	G[0][1] = iJt[0][0] * L[0][1] + iJt[0][1] * L[1][1];
	G[0][2] = iJt[0][0] * L[0][2] + iJt[0][1] * L[1][2];
	G[1][0] = iJt[1][0] * L[0][0] + iJt[1][1] * L[1][0];
	G[1][1] = iJt[1][0] * L[0][1] + iJt[1][1] * L[1][1];
	G[1][2] = iJt[1][0] * L[0][2] + iJt[1][1] * L[1][2];

	GG[0][0] = G[0][0] * G[0][0] + G[1][0] * G[1][0];
	GG[0][1] = G[0][0] * G[0][1] + G[1][0] * G[1][1];
	GG[0][2] = G[0][0] * G[0][2] + G[1][0] * G[1][2];
	GG[1][0] = G[0][1] * G[0][0] + G[1][1] * G[1][0];
	GG[1][1] = G[0][1] * G[0][1] + G[1][1] * G[1][1];
	GG[1][2] = G[0][1] * G[0][2] + G[1][1] * G[1][2];
	GG[2][0] = G[0][2] * G[0][0] + G[1][2] * G[1][0];
	GG[2][1] = G[0][2] * G[0][1] + G[1][2] * G[1][1];
	GG[2][2] = G[0][2] * G[0][2] + G[1][2] * G[1][2];

	for (ii = 0; ii<3; ++ii) {
		for (jj = 0; jj<3; ++jj) {
			val[ii][jj] = 0;
		}
	}

	for (ii = 0; ii<3; ++ii) {
		S[0] = 1 - ip[ii][0] - ip[ii][1];
		S[1] = ip[ii][0];
		S[2] = ip[ii][1];
		tmp = k0*S[0] + k1*S[1] + k2*S[2];
		tmp = tmp*w[ii];
		val[0][0] += GG[0][0] * tmp;
		val[0][1] += GG[1][0] * tmp;
		val[0][2] += GG[2][0] * tmp;
		val[1][0] += GG[0][1] * tmp;
		val[1][1] += GG[1][1] * tmp;
		val[1][2] += GG[2][1] * tmp;
		val[2][0] += GG[0][2] * tmp;
		val[2][1] += GG[1][2] * tmp;
		val[2][2] += GG[2][2] * tmp;
	}
	for (ii = 0; ii<3; ++ii) {
		for (jj = 0; jj<3; ++jj) {
			val[ii][jj] = val[ii][jj] * dJt;
		}
	}


}
void phidotphi(double g[3][2], double mua[3], double val[3][3])
{
	int ii, jj;
	static int L[2][3] = { { -1.0,1.0,0.0 }, \
	{-1.0,0.0,1.0} };
	static double w[3] = { 1.0 / 6.0,1.0 / 6.0,1.0 / 6.0 };
	static double ip[3][2] = { { 1.0 / 2.0,0.0 },{ 1.0 / 2.0,1.0 / 2.0 },{ 0.0,1.0 / 2.0 } };
	double Jt[2][2], dJt, S[3], tmp;
	double x0 = g[0][0]; double x1 = g[1][0];
	double x2 = g[2][0];
	double y0 = g[0][1]; double y1 = g[1][1];
	double y2 = g[2][1];
	double k0 = mua[0]; double k1 = mua[1];
	double k2 = mua[2];

	Jt[0][0] = L[0][0] * x0 + L[0][1] * x1 + L[0][2] * x2;
	Jt[0][1] = L[0][0] * y0 + L[0][1] * y1 + L[0][2] * y2;
	Jt[1][0] = L[1][0] * x0 + L[1][1] * x1 + L[1][2] * x2;
	Jt[1][1] = L[1][0] * y0 + L[1][1] * y1 + L[1][2] * y2;

	dJt = (Jt[0][0] * Jt[1][1]) - (Jt[0][1] * Jt[1][0]);

	dJt = sqrt(dJt*dJt);

	for (ii = 0; ii<3; ++ii) {
		for (jj = 0; jj<3; ++jj) {
			val[ii][jj] = 0;
		}
	}

	for (ii = 0; ii<3; ++ii) {
		S[0] = 1 - ip[ii][0] - ip[ii][1];
		S[1] = ip[ii][0];
		S[2] = ip[ii][1];
		tmp = k0*S[0] + k1*S[1] + k2*S[2];
		tmp = tmp*w[ii];
		val[0][0] += S[0] * S[0] * tmp;
		val[0][1] += S[1] * S[0] * tmp;
		val[0][2] += S[2] * S[0] * tmp;
		val[1][0] += S[0] * S[1] * tmp;
		val[1][1] += S[1] * S[1] * tmp;
		val[1][2] += S[2] * S[1] * tmp;
		val[2][0] += S[0] * S[2] * tmp;
		val[2][1] += S[1] * S[2] * tmp;
		val[2][2] += S[2] * S[2] * tmp;
	}
	for (ii = 0; ii<3; ++ii) {
		for (jj = 0; jj<3; ++jj) {
			val[ii][jj] = val[ii][jj] * dJt;
		}
	}
}


void boundary_int(double gg[3][2], double bnd_index[3], double ksir[3], \
	double valr[2][2])
{
	double ksirtmp[2];
	int i, j;
	double g[2][2], val;

	for (i = 0; i<2; ++i) {
		for (j = 0; j<2; ++j) {
			valr[i][j] = 0;
		}
	}

	if (bnd_index[0] == 1 && bnd_index[2] == 1) {
		ksirtmp[0] = ksir[0];
		ksirtmp[1] = ksir[2];
		g[0][0] = gg[0][0];
		g[0][1] = gg[0][1];
		g[1][0] = gg[2][0];
		g[1][1] = gg[2][1];
		for (i = 0; i<2; ++i) {
			for (j = 0; j <= i; ++j) {
				bound2(g, i, j, ksirtmp, &val);
				valr[i][j] = val;
			}
		}
	}
	else if (bnd_index[0] == 1 && bnd_index[1] == 1) {
		ksirtmp[0] = ksir[0];
		ksirtmp[1] = ksir[1];
		g[0][0] = gg[0][0];
		g[0][1] = gg[0][1];
		g[1][0] = gg[1][0];
		g[1][1] = gg[1][1];

		for (i = 0; i<2; ++i) {
			for (j = 0; j <= i; ++j) {
				bound2(g, i, j, ksirtmp, &val);
				valr[i][j] = val;
			}
		}
	}
	else if (bnd_index[1] == 1 && bnd_index[2] == 1) {
		ksirtmp[0] = ksir[1];
		ksirtmp[1] = ksir[2];
		g[0][0] = gg[1][0];
		g[0][1] = gg[1][1];
		g[1][0] = gg[2][0];
		g[1][1] = gg[2][1];

		for (i = 0; i<2; ++i) {
			for (j = 0; j <= i; ++j) {
				bound2(g, i, j, ksirtmp, &val);
				valr[i][j] = val;
			}
		}
	}
}
void bound2(double g[2][2], int il, int im, double ksir[2], \
	double *val)
{
	static double w[2] = { 1.0 / 2.0,1.0 / 2.0 };
	static double ip[2] = { 0.21132486540519,0.78867513459481 };
	double dJt, S[2], tmp, tmpval;
	int ii;
	double x0 = g[0][0]; double x1 = g[1][0];
	double y0 = g[0][1]; double y1 = g[1][1];
	double k0 = ksir[0]; double k1 = ksir[1];

	dJt = sqrt(((g[1][0] - g[0][0])*(g[1][0] - g[0][0])) + \
		((g[1][1] - g[0][1])*(g[1][1] - g[0][1])));


	tmpval = 0.0;
	for (ii = 0; ii<2; ++ii) {
		S[0] = 1 - ip[ii];
		S[1] = ip[ii];
		tmp = k0*S[0] + k1*S[1];
		tmp = tmp*w[ii];
		tmpval += S[il] * S[im] * tmp;
	}
	*val = tmpval*dJt;
}