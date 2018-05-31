#include"jacobianStand3D.h"
#include "Eigen/SparseLU"
//#include"Eigen/SuperLUSupport"
#include<time.h>
bool jacobianStand(Mesh &mesh, Source &source, Detector &detector, Eigen::MatrixXd &link,
	Eigen::MatrixXd &ref_data, Eigen::MatrixXd &j_complete)
{

	//����K����

	//Eigen::MatrixXd K = assemblyK(mesh);
	////double sum = 0;
	//Eigen::MatrixXd k_inverse = K.inverse();
	//Eigen::MatrixXd sn = qvec(mesh, source);
	//Eigen::MatrixXd phi_data = k_inverse*sn;
	//Eigen::MatrixXd dn = genSourceAdjoint(mesh, detector);
	//Eigen::MatrixXd aphi_data = k_inverse*dn;

	//Eigen::MatrixXd K1 = K;
	/*for (int i = 0; i < 2030; i++)
	{
	for (int j = 0; j < 2030; j++)
	{
	sum+=K1(i, i);
	}
	}*/
	//cout << sum << endl;
	//������Դ����

	SparseMatrixType K = assemblyK3D(mesh);
	SparseMatrixType sn = qvec(mesh, source);
	//Eigen::MatrixXd K1 = K;
	//����̽��������

	SparseMatrixType dn = genSourceAdjoint3D(mesh, detector);
	//����ڵ�����

	//Eigen::MatrixXd k_inverse = K.inverse();

	//Eigen::MatrixXd phi_data = k_inverse*sn;

	Eigen::SparseLU<SparseMatrixType> solver;
	//Eigen::BiCGSTAB <SparseMatrixType,Eigen::IdentityPreconditioner> solver;
	//solver.setTolerance(1e-12);
	//Eigen::SimplicialLLT<SparseMatrixType> solver;
	solver.compute(K);
	//solver.analyzePattern(K);
	//solver.factorize(K);
	Eigen::MatrixXd phi_data = solver.solve(sn);


	//����̽��������
	ref_data = getBoundaryData3D(detector, mesh, phi_data, link);

	//Eigen::MatrixXd aphi_data = k_inverse*dn;

	Eigen::MatrixXd aphi_data = solver.solve(dn);


	//���ɲο�����
	//data= getBoundaryData(detector, mesh, phi_data, link);
	//ref_data = getBoundaryData(detector, mesh, phi_data, link);
	//�����ſ˱Ⱦ���

	bool a = calJMatrix3D(mesh, link, ref_data,
		phi_data, aphi_data, j_complete);

	return true;
}