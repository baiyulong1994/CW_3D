#include<String>
#include"mesh.h"
#include"loadDoubleRaw.h"
#include"loadMesh.h"
#include"calMassMatrix.h"
#include"eleArea.h"
#include"inTraingle.h"
#include"mytSearchN.h"

//int main()
//{
//	Mesh mesh;
//	//在此输入文件存储的路径（到具体文件的名字）
//	string file_path = "D:\\testdata\\circle_50";
//	//定义有关K矩阵存储信息的矩阵
//	const int nzmax = nb_elements*(nb_ever_ele*(nb_ever_ele + 1));
//	int *I = new int[nzmax];
//	int *J = new int[nzmax];
//	double *Sr = new double[nzmax];
//	double *Si = new double[nzmax];
////	double I[nzmax], J[nzmax], Sr[nzmax], Si[nzmax];
//	//加载网格
//	bool a=loadMesh(file_path, mesh);
//	//计算刚度矩阵
////	bool b = calMassMatrix(mesh, I,J,Sr, Si);
//	double area_coord[3] = { 0, 0, 0 };
//	int number = mytSearchN(mesh, area_coord, 26, 27);
//	cout << number << endl;
//	for (int i = 0; i <=2; i++)
//	{
//		cout << area_coord[i] << endl;
//	}
////	double nodes[nb_nodes][dimension];
//	double(*nodes)[dimension] = new double[nb_nodes][dimension];
//	FILE *stream = NULL;
//	errno_t err;
//
//	// Open for read (will fail if file "crt_fopen_s.c" does not exist)
//	if ((err = fopen_s(&stream, "E:\\寒假资料\\nodes.raw", "rb")) != 0)
//	{
//		cout<<"The file  was not opened\n";
//	}
//	for (int i = 0; i != nb_nodes; i++)
//	{
//		for (int j = 0; j != 3; j++)
//		{
//			fread(&nodes[i][j], sizeof(double), 1, stream);
//		}
//		
//	}
//
//	for (int i = 0; i != nb_nodes; i++)
//	{
//		for (int j = 0; j != 3; j++)
//		{
//			cout<<nodes[i][j]<<'\t';
//		}
//		cout << endl;
//
//	}
//	fclose(stream);
//	stream = NULL;
//}