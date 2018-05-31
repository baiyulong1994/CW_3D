#ifndef _GETBOUNDARYDATA_H_
#define _GETBOUNDARYDATA_H_
#include<math.h>
#include"mesh.h"
#include"source.h"
#include"Detector.h"
#include"qvec.h"
Eigen::MatrixXd getBoundaryData(Detector &detector,Mesh &mesh, Eigen::MatrixXd data, Eigen::MatrixXd &link);
#endif