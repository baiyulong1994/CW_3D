#ifndef _CALJMATRIX3D_H_
#define _CALJMATRIX3D_H_
#include"mesh.h"
#include"qvec.h"
#include"calJMatrixRow3D.h"
bool calJMatrix3D(Mesh &mesh, Eigen::MatrixXd link, Eigen::MatrixXd &data,
	Eigen::MatrixXd &phi, Eigen::MatrixXd &aphi, Eigen::MatrixXd &j_complete);
#endif
