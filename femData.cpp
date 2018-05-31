#include "femData.h"
Eigen::MatrixXd femData(Mesh &mesh, Source &source, Detector &detector, Eigen::MatrixXd link)
{
	//创建K矩阵
	Eigen::MatrixXd K = assemblyK(mesh);
	//创建光源向量
	Eigen::MatrixXd qw = qvec(mesh, source);
	
	//计算节点数据
	Eigen::MatrixXd data = (K.inverse())*qw;


	//计算探测器数据
	Eigen::MatrixXd boundary_data = getBoundaryData(detector, mesh, data, link);

	return boundary_data;
}