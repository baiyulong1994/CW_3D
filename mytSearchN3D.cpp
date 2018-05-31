#include"mytSearchN3D.h"

int mytSearchN3D(Mesh &mesh, double *volume_coord, double x, double y, double z)
{
	double *distance = new double[nb_nodes];
	double *distanceTmp = new double[nb_nodes];
	double coord[] = { x,y,z };
	double p[3];
	double q[3];
	double r[3];
	double s[3];
	//用于存储距离最近的10个元素的编号。
	int number[10];
	//距离向量初始化
	for (int i = 0; i < nb_nodes; i++)
	{
		distance[i] = 0.0;
		distanceTmp[i] = 0.0;
	}
	double tempX = 0.0;
	double tempY = 0.0;
	double tempZ = 0.0;

	for (int i = 0; i < nb_nodes; i++)
	{
			tempX = (x - mesh.nodes[i])
				*(x - mesh.nodes[i]);
			tempY = (y - mesh.nodes[i+nb_nodes])
				*(y - mesh.nodes[i+nb_nodes]);
			tempZ = (z - mesh.nodes[i+2*nb_nodes])
				*(z - mesh.nodes[i+2*nb_nodes]);
			distance[i] = sqrt(tempX + tempY + tempZ);
			distanceTmp[i] = distance[i];
	}

	//将distance数组进行局部排序，相比于sort可以节省时间
	partial_sort(distanceTmp, distanceTmp + 20, distanceTmp + nb_nodes);
	//sort(distanceTmp, distanceTmp + nb_nodes);
	for (int i = 0; i < 10; i++)
	{
		int temp = 0;
		while (abs(distance[temp]-distanceTmp[i])>0.00000001)
		{
			++temp;
		}
		number[i] = temp+1;
	}
	/*for (int i = 0; i < 10; i++)
	{
		cout << number[i] << endl;
	}*/
	
		
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j< nb_elements; j++)
		{
			if (mesh.elements[j] == number[i] || mesh.elements[j + nb_elements] == number[i]
				|| mesh.elements[j + 2 * nb_elements] == number[i] ||
				mesh.elements[j + 3 * nb_elements] == number[i])
				
			{
				int numP = mesh.elements[j];
				int numQ = mesh.elements[j + nb_elements];
				int numR = mesh.elements[j + 2 * nb_elements];
				int numS = mesh.elements[j + 3 * nb_elements];

				p[0] = mesh.nodes[numP - 1];
				p[1] = mesh.nodes[numP - 1 + nb_nodes];
				p[2] = mesh.nodes[numP - 1 + 2*nb_nodes];

				q[0] = mesh.nodes[numQ - 1];
				q[1] = mesh.nodes[numQ - 1 + nb_nodes];
				q[2] = mesh.nodes[numQ - 1 + 2 * nb_nodes];

				r[0] = mesh.nodes[numR - 1];
				r[1] = mesh.nodes[numR - 1 + nb_nodes];
				r[2] = mesh.nodes[numR - 1 + 2 * nb_nodes];

				s[0] = mesh.nodes[numS - 1];
				s[1] = mesh.nodes[numS - 1 + nb_nodes];
				s[2] = mesh.nodes[numS - 1 + 2 * nb_nodes];
				bool a = insideTetrahedron(coord, p, q, r, s);
				if (a)
				{
					Eigen::Matrix4d A;
					Eigen::MatrixXd b(4, 1);
					//矩阵初始化
					A.setZero();
					b.setZero();
					//输入元素
					A << p[0], q[0], r[0], s[0], p[1], q[1], r[1], s[1], p[2], q[2], r[2], s[2],
						1, 1, 1,1;
					b << x, y, z, 1;
					Eigen::MatrixXd volumeCoord = A.lu().solve(b);
					volume_coord[0] = volumeCoord(0);
					volume_coord[1] = volumeCoord(1);
					volume_coord[2] = volumeCoord(2);
					volume_coord[3] = volumeCoord(3);
					return j+1;
				}
				
			}
		}
	}
	
	return -1;
	
}