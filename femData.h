#ifndef _FEMDATA_H_
#define _FEMDATA_H_
#include "mesh.h"
#include"source.h"
#include"Detector.h"
#include"qvec.h"
#include"assemblyK.h"
#include"getBoundaryData.h"

Eigen::MatrixXd femData(Mesh &mesh, Source &source, Detector &detector, Eigen::MatrixXd link);
#endif
