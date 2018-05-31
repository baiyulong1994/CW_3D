#include"getBoundaryData.h"
Eigen::MatrixXd getBoundaryData(Detector &detector,Mesh &mesh, Eigen::MatrixXd data, Eigen::MatrixXd &link)
{
	
	int sou, i, j;
	int estimation_of_entries = 3 * nb_detector;
	//int *x = new int[3 * nb_source];
	//int *y = new int[3 * nb_source];
	//for (int i = 0; i < 3 * nb_source; i++)
	//{
	//	x[i] = 0;
	//	y[i] = 0;
	//}

	double *coord = new double[dimension];
	for (int i = 0; i < dimension; i++)
	{
		coord[i] = 0.0;
	}
	double area_coord[3] = { 0, 0, 0 };
	//创建存储triplet对象的容器与空的double矩阵
	Eigen::MatrixXi tem(nb_detector, 4);

	Eigen::MatrixXd tem1(nb_detector, 4); 
	for (int i = 0; i < nb_detector; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			tem(i, j) = 0.0;
			tem1(i, j) = 0.0;
		}
	}

	//将数据读入tem和tem1中
	for (sou = 0; sou < nb_detector; sou++)
	{
		for (i = 0; i < dimension; i++)
		{
			coord[i] = *(detector.nodes + (sou + i*nb_detector));
		}
		int number = mytSearchN(mesh, area_coord, coord[0], coord[1]);
		tem(sou, 0) = number;
		tem1(sou, 0) = number;
		for (j = 0; j < nb_ever_ele; j++)
		{
			
			tem(sou,j+1)= *(mesh.elements + number - 1 + j*nb_elements);
			tem1(sou, j + 1) = area_coord[j];
		}
	}
	//如果节点为边界节点，则该点的面积坐标为0
	for (int i = 0; i < nb_detector; i++)
	{
		for (int j = 1; j < 4; j++)
		{
		
			if (*(mesh.bndvtx + tem(i, j) - 1) == 0)
			{
				tem1(i, j) = 0;
			}
		}
	}
	Eigen::MatrixXd tem2 = tem1;
	for (int i = 0; i < nb_detector; i++)
	{
		for (int j = 1; j < 4; j++)
		{

			tem2(i, j) = tem1(i, j) / (tem1(i, 1) + tem1(i, 2) + tem1(i, 3) );
		}
	}
	//计算每个探测器的数据
	Eigen::MatrixXd boundary_data(link.rows(), 1);
	for (int i = 0; i < link.rows(); i++)
	{
		boundary_data(i, 0)=0.0;
	}
	//cout << tem;
	for (int i = 0; i < link.rows(); i++)
	{
		//光源编号
		int sn = link(i,0);
		//探测器编号
		int dn = link(i,1);
		for (int j = 0; j < nb_ever_ele; j++)
		{
			boundary_data(i, 0) =boundary_data(i,0)+ data(tem(dn - 1, j+1)-1, sn - 1)*tem2(dn - 1, j + 1);
			//boundary_data(i, 0) = log(boundary_data(i, 0));
		}
		
	}
	/*for (int i = 0; i < link.rows(); i++)
	{
		boundary_data(i, 0) = log(boundary_data(i, 0));
	}*/
	return boundary_data;
	
}