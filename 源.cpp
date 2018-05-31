

#include<string>
#include<math.h>
#include"mesh.h"
#include"source.h"
#include"detector.h"
#include"qvec.h"
#include"loadLink.h"
#include"femData.h"
#include"loadDoubleRaw.h"
#include"loadMesh.h"
#include"loadSource.h"
#include"loadDetector.h"
#include"assemblyK.h"
#include"eleArea.h"
#include"inTraingle.h"
#include"mytSearchN.h"
#include"getBoundaryData.h"
#include"genSourceAdjoint.h"


using namespace std;
using namespace Eigen;
typedef Eigen::Triplet<double> T;
typedef Eigen::SparseMatrix<double> SparseMatrixType;
typedef Eigen::MatrixXd Matrix;

//int main()
//{
//	Mesh mesh;
//	Source source;
//	Detector detector;
//	
//	SparseMatrixType q(nb_nodes, nb_source);
//	MatrixXd mt(nb_nodes, nb_nodes);
//	MatrixXd mt2(nb_nodes, nb_nodes);
//	MatrixXd boundarydata(nb_source, 4);
//	//�ڴ������ļ��洢��·�����������ļ������֣�
//	string file_path = "D:\\testdata\\circle_50";
//
//	//��������
//	bool a = loadMesh(file_path, mesh);
//	//���ع�Դ����
//	bool b = loadSource(file_path, source);
//	//����̽��������
//	bool c = loadDetector(file_path, detector);
//	//����link
//	MatrixXd link1 = loadLink("D:\\testdata\\circle_50.link", 240);
//
//	//����K����
//	Eigen::MatrixXd K = assemblyK(mesh);
//	//��������Դ����
//
//	//��ȡ�ؽ����ݲ���������
//	
//
//	////������Դ����
//	//Eigen::MatrixXd qw = qvec(mesh, source);
//	////����ڵ�����
//	//Eigen::MatrixXd data = (K.inverse())*qw;
//	////����̽��������
//	//Eigen::MatrixXd boundary_data = getBoundaryData(detector, mesh, data, link1);
//	////����̽��������
//	/*MatrixXd boundary_data = femData(mesh, source, detector, link1);
//
//	double *boundary_d = new double[240];
//	loadDataDoubleRaw(boundary_d, "D:\\testdata\\circle_50.data", 46812);
//	double sum = 0;
//	for (int i = 0; i < 240; i++)
//	{
//		sum+=boundary_data(i, 0) - boundary_d[i];
//	}
//	cout << sum;*/
//	/*const int nzmax = nb_elements*(nb_ever_ele*(nb_ever_ele + 1));
//	int estimation_of_entries = 0;
//	int *I = new int[nzmax];
//	int *J = new int[nzmax];
//	double *Sr = new double[nzmax];
//	double *Si = new double[nzmax];
//	double *s = new double[46812];
//	double *i = new double[46812];
//	double *j = new double[46812];
//	bool d=calMassMatrix(mesh, I, J, Sr, Si);
//
//	loadDataDoubleRaw(i, "D:\\testdata\\circle_50.i", 46812);
//	loadDataDoubleRaw(j, "D:\\testdata\\circle_50.j", 46812);
//	loadDataDoubleRaw(s, "D:\\testdata\\circle_50.s", 46812);
//	double sum = 0;
//	
//	for (int i = 0; i < 46812; i++)
//	{
//		sum = sum + Sr[i] - s[i];
//	}
//	cout << sum;*/
//	/*for (int ii = 0; ii< 35580; ii++)
//	{
//		mt(i[ii] - 1, j[ii] - 1) = mt(i[ii] - 1, j[ii] - 1) + s[ii];
//	}
//	for (int ii = 0; ii< 35580; ii++)
//	{
//		mt2(I[ii] - 1, J[ii] - 1) = mt2(I[ii] - 1, J[ii] - 1) + Sr[ii];
//	}*/
//	
//
//	
//	////����̽��������
//	////cout << K.nonZeros();
//	///*double a1= 0.0003;
//	//cout<<a1;*/
//	//double *mass = new double[2030 * 2030];
//	//Eigen::MatrixXd mass1(2030, 2030);
//	//loadDataDoubleRaw(mass, "D:\\testdata\\circle_50.k", 2030*2030);
//	//// Open for read (will fail if file "crt_fopen_s.c" does not exist)
//
//	//int ii = 0;
//	//for (int i = 0; i != 2030; i++)
//	//{
//	//	for (int j = 0; j != 2030; j++)
//	//	{
//	//		mass1(i, j) = *(mass + ii);
//	//		ii++;
//	//	}
//
//	//}
//	//double sum = 0;
//	//for (int i = 0; i < 2030; i++)
//	//{
//	//	for (int j = 0; j < 2030; j++)
//	//	{
//	//		sum += K(i, j) - mass1(i, j);
//	//	}
//	//}
//	//cout << sum;
//
//	//double su = 0;
//
//	//for (int ii = 100; ii < 120; ii++)
//	//{
//	//	cout << Sr[ii] << endl;
//	//}
//
//	
//	//for (int i = 0; i != 2030; i++)
//	//{
//	//	for (int j = 0; j < 2030; j++)
//	//	{
//	//		su = su + mt2(i, j) - mt(i,j);
//	//	}
//	//	//cout << mass1(i, 3) << " " << mt(i, 3) << " " << mt2(i, 3) << " " << mt3(i, 3) << endl;
//	//
//	//}
//	//cout << su;
//
//	
//	/*bool d=loadDataDoubleRaw(link,"D:\\testdata\\circle_50.link",240*2);
//	int ii = 0;
//	for (int i = 0; i != 240; i++)
//	{
//		for (int j = 0; j != 2; j++)
//		{
//			link1(i, j) = *(link + ii);
//			ii++;
//		}
//
//	}*/
//	//cout << link1;
//	////����link����
//	//for (int i = 0; i < 240; i++)
//	//{
//	//	for (int j = 0; j < 2; j++)
//	//	{
//	//		cout << link[i][j] << " ";
//	//	}
//	//	cout << endl;
//	//}
//	//����նȾ���
//	/*boundarydata = getBoundaryData(detector, mesh);
//	cout << boundarydata;
//	*/
//	/*for (sou = 0; sou < nb_source; sou++)
//	{
//		for (i = 0; i < dimension; i++)
//		{
//			coord[i] = *(source.nodes + (sou + i*nb_source));
//		}
//		int number = mytSearchN(mesh, area_coord, coord[0], coord[1]);
//
//		for (j = 0; j < nb_ever_ele; j++)
//		{
//			x[sou*nb_ever_ele + j] = *(mesh.elements + number - 1 + j*nb_elements);
//			y[sou*nb_ever_ele + j] = sou;
//			value[sou*nb_ever_ele + j] = area_coord[j] * 0.98877107793604;
//		}
//	}*/
//	
//
//	
//	/*double area_coord[3] = { 0, 0, 0 };
//	int number = mytSearchN(mesh, area_coord, 26, 27);
//	cout << number << endl;
//	for (int i = 0; i <= 2; i++)
//	{
//		cout << area_coord[i] << endl;
//	}*/
//	/*mat = qvec(mesh, source);
//	int a2 = 3;
//	int b2 = 8;
//	cout << mat;*/
//	return 0;
//}