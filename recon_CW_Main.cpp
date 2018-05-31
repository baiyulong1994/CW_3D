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
#include"mytSearchN3D.h"
#include"assemblyK3D.h"
#include"getBoundaryData3D.h"
int main()
{
	//在此输入文件存储的路径（到具体文件的名字）
	string file_path = "G:\\cylinder_100_0.3\\cylinder_100_0.3";

	Mesh mesh;
	Mesh recon_mesh;
	Source source;
	Detector detector;
	double volume_coord[4];
	//double anom_data[64];
	double *anom_data = new double[240];
	const int number = 8401;
	//加载网格
	bool a = loadMesh(file_path, mesh);
	
	bool a2 = loadMesh(file_path, recon_mesh);
	//加载光源数据
	bool b = loadSource(file_path, source);
	//加载探测器数据
	bool c = loadDetector(file_path, detector);
	double *recon_data1 = new double[number*number];
	loadDataDoubleRaw(recon_data1, "G:\\cylinder_100_0.3\\cylinder_100_0.3.mass", number*number);
	
	/*Eigen::MatrixXd mass(number,number);
	int k = 0;
	for (int i = 0; i < number; i++)
	{
		for (int j = 0; j < number; j++)
		{
			mass(i,j)=recon_data1[k];
			k++;
		}
		
	}*/
	/*for (int i = 0; i < 100; i++)
	{
		cout << mesh.nodes[i] << " ";
		cout << mesh.nodes[i + nb_nodes] << " ";
		cout << mesh.nodes[i + 2 * nb_nodes] << endl;

	}*/

	
	SparseMatrixType K = assemblyK3D(mesh);
	/*for (int i = 0; i < 300; i++)
	{
		cout <<	K(2, i) << endl;
	}*/
	/*double sum(0);
	for (int i = 0; i < number; i++)
	{
		for (int j = 0; j < number; j++)
		{
			sum += mass(i, j) - K(i, j);
		}
	}*/
	//cout << sum << endl;
	/*int k = 0;
	for (int i = 0; i < 8401; i++)
	{
		for (int j = 0; j < 8401; j++)
		{
			recon_data1[k] = K(i, j);
		}
		k++;
	}*/
	Eigen::MatrixXd qw = qvec(mesh, source);
	clock_t start = clock();
	//Eigen::BiCGSTAB <SparseMatrixType,Eigen::IdentityPreconditioner> solver;
	//solver.setTolerance(1e-12);

	Eigen::SparseLU<SparseMatrixType> solver;
	solver.compute(K);
	Eigen::MatrixXd phi_data = solver.solve(qw);
	Eigen::MatrixXd link = loadLink("G:\\DOT CW\\test_new\\circle_50.link", 240);
	Eigen::MatrixXd boundary_data = getBoundaryData3D(detector, mesh, phi_data, link);
	for (int i = 0; i < 50; i++)
	{
		cout << boundary_data(i, 0) << endl;
	}
	clock_t finish = clock();
	cout << "运行时间：" << (double)(finish - start) / CLOCKS_PER_SEC << "s" << endl;
	//Eigen::MatrixXd K = assemblyK(mesh);
	////加载仿真数据
	//bool d = loadDetectorData(anom_data, 240, file_path);
	//
	////加载link
	//Eigen::MatrixXd link = loadLink("G:\\DOT CW\\test_new\\circle_50.link", 240);
	//
	//Eigen::MatrixXd fem_data = femData(mesh,source,detector,link);
	//
	//clock_t start = clock();
	//bool e = recosntractCW(mesh, recon_mesh, source, detector,anom_data,
	//	link,30, 30, 240, file_path);
	//clock_t finish = clock();
	//cout << "运行时间：" << (double)(finish - start) / CLOCKS_PER_SEC<<"s"<<endl;
	
	/*loadDataDoubleRaw(recon_data1, "D:\\testdata\\circle_50.cn",
		2797*2797);

	Eigen::MatrixXd ni(2797, 2797);
	int k = 0;
	for (int i = 0; i < 2797; i++)
	{
		for (int j = 0; j < 2797; j++)
		{
			ni(i,j)=recon_data1[k];
		}
		k++;
	}*/
	
	//double sum = 0;
	//for (int i = 0; i < 2030; i++)
	//{
	//	sum = abs(sum + recon_data1[i] - recon_mesh.mua[i]);
	//	//cout << recon_mesh.mua[i] << endl;
	//} 
	//cout << sum << endl;




	/*vector<double> cha;
	double wucha[2030];
	for (int i = 0; i < 2030; i++)
	{
		 double a=(recon_mesh.mua[i] - recon_data1[i]) / recon_data1[i] ;
		 cha.push_back(a);
		 wucha[i] = a;
	}*/


	//double fem_datam[240];
	/*for (int i = 0; i < 64; i++)
	{
		fem_datam[i]=fem_data(i, 0);
	}*/


	//FILE *stream = NULL;
	//errno_t err;

	//Open for read (will fail if file "crt_fopen_s.c" does not exist)
	//string as = "D:\\test\\cylinder_100_3.k";
	/*if ((err = fopen_s(&stream, as.c_str(), "wb")) != 0)
	{
		printf("The file  was not opened\n");
		return false;
	}
	for (int i = 0; i != 8401*8401; i++)
	{
		fwrite(&recon_data1[i], sizeof(double), 1, stream);
	}
*/
	//fclose(stream);
	//stream = NULL;
	//cout << *max_element(cha.begin(), cha.end()) << endl;
	/*double sum_all = 0;
	for (int i = 0; i < 2030; i++)
	{
		sum_all += recon_mesh.mua[i] - recon_data1[i];
	}
	cout << "sum" << sum_all << endl;*/
}