#ifndef JACOBIANSTAND3D_H_
#define JACOBIANSTAND3D_H_
#include"mesh.h"
#include"qvec.h"
#include"Detector.h"
#include"source.h"
#include"genSourceAdjoint3D.h"
#include"calJMatrix3D.h"
#include"assemblyK3D.h"
#include"getBoundaryData3D.h"
bool jacobianStand3D(Mesh &mesh, Source &source, Detector &detector, Eigen::MatrixXd &link,
	Eigen::MatrixXd &data, Eigen::MatrixXd &j_complete);
#endif
