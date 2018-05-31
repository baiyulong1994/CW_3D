
#ifndef _RECONSTRACTCW_H_
#define _RECONSTRACTCW_H_
#include"Mesh.h"
#include"loadLink.h"
#include"jacobianStand.h"
#include"loadDetectorData.h"
bool recosntractCW(Mesh &mesh, Mesh &recon_mesh, Source &source, Detector &detector,double *anom_data1,Eigen::MatrixXd &link,
	int iteration, double lamda,int nb_data,string fn);
#endif