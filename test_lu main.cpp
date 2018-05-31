#include<string>
#include<math.h>
#include"mesh.h"
#include"source.h"
#include"detector.h"
#include"qvec.h"
#include"loadLink.h"
#include"loadMesh.h"
#include"loadSource.h"
#include"loadDetector.h"
#include"reconstractCW.h"
#include"femData.h"
#include"assemblyK.h"
#include<time.h>
#include<algorithm>
#include<vector>
#include<iterator>
#include <Eigen/Dense> 
#include<Eigen/LU>
#include<Eigen/Cholesky>
#include <Eigen/SparseQR>
#include <Eigen/OrderingMethods>
//int main()
//{
//		string file_path = "D:\\testdata\\circle_50";
//		Mesh mesh;
//		Mesh recon_mesh;
//		Source source;
//		Detector detector;
//		//double anom_data[64];
//		double *anom_data = new double[240];
//		double recon_data1[2030];
//		//加载网格
//		bool a = loadMesh(file_path, mesh);
//		bool a2 = loadMesh(file_path, recon_mesh);
//		//加载光源数据
//		bool b = loadSource(file_path, source);
//		//加载探测器数据
//		bool c = loadDetector(file_path, detector);
//
//		//Eigen::MatrixXd k = assemblyK(mesh);
//		SparseMatrixType K = assemblyK(mesh);
//		Eigen::MatrixXd qw = qvec(mesh, source);
//		clock_t start = clock();
//		//Eigen::PartialPivLU<Eigen::MatrixXd> lltOfA(k);
//		//Eigen::MatrixXd L = lltOfA.matrixL();
//		//Eigen::MatrixXd l = k.inverse();
//		
//		//计算节点数据
//		 //k.inverse();
//		//Eigen::MatrixXd data = k.householderQr().solve(qw);
//		Eigen::SparseLU<SparseMatrixType> solver;
//		//Eigen::SimplicialLLT<SparseMatrixType> solver;
//		solver.analyzePattern(K);
//		solver.factorize(K);
//		Eigen::MatrixXd phi_data = solver.solve(qw);
//		//Eigen::MatrixXd lt = l.adjoint();
//		//Eigen::MatrixXd v = l*lt;
//		clock_t finish = clock();
//		cout << "运行时间：" << (double)(finish - start) / CLOCKS_PER_SEC<<"s"<<endl;
//		//Eigen::FullPivLU<Eigen::MatrixXd> lu(A);
//		/*Eigen::MatrixXd l = lu.matrixLU().triangularView<Eigen::Lower>();
//		Eigen::MatrixXd u = lu.matrixLU().triangularView<Eigen::Upper>();
//		cout << l << endl;
//		cout << u << endl;
//		Eigen::MatrixXd full = l*u;
//		cout << full << endl;*/
//		//Eigen::PartialPivLU<Eigen::MatrixXd> lu(A);
//}