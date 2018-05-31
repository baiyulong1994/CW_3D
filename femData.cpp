#include "femData.h"
Eigen::MatrixXd femData(Mesh &mesh, Source &source, Detector &detector, Eigen::MatrixXd link)
{
	//����K����
	Eigen::MatrixXd K = assemblyK(mesh);
	//������Դ����
	Eigen::MatrixXd qw = qvec(mesh, source);
	
	//����ڵ�����
	Eigen::MatrixXd data = (K.inverse())*qw;


	//����̽��������
	Eigen::MatrixXd boundary_data = getBoundaryData(detector, mesh, data, link);

	return boundary_data;
}