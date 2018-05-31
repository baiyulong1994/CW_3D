#ifndef JACOBIANSTAND_H_
#define JACOBIANSTAND_H_
#include"mesh.h"
#include"qvec.h"
#include"Detector.h"
#include"source.h"
#include"genSourceAdjoint.h"
#include"femData.h"
#include"calJMatrix.h"

bool jacobianStand(Mesh &mesh, Source &source, Detector &detector, Eigen::MatrixXd &link,
	Eigen::MatrixXd &data, Eigen::MatrixXd &j_complete);
#endif
