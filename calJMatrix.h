#ifndef _CALJMATRIX_H_
#define _CALJMATRIX_H_
#include"mesh.h"
#include"qvec.h"
#include"calJMatrixRow.h"
bool calJMatrix(Mesh &mesh, Eigen::MatrixXd link, Eigen::MatrixXd &data,
	Eigen::MatrixXd &phi, Eigen::MatrixXd &aphi, Eigen::MatrixXd &j_complete);
#endif
