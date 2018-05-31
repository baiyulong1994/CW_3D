#include"genSourceAdjoint.h"
SparseMatrixType genSourceAdjoint(Mesh &mesh, Detector &detector)
{
	//创建三元数组
	int sou, i, j;
	int estimation_of_entries = 3 * nb_detector;
	int *x = new int[3 * nb_detector];
	int *y = new int[3 * nb_detector];
	double *value = new double[3 * nb_detector];
	for (int i = 0; i < 3 * nb_detector; i++)
	{
		x[i] = 0;
		y[i] = 0;
		value[i] = 0.0;
	}
	double coord[2] = {0.0,0.0};
	double area_coord[3] = { 0.0, 0.0, 0.0 };
	//创建存储triplet对象的容器与空的稀疏矩阵
	std::vector<T> tripletList;
	SparseMatrixType mat(nb_nodes, nb_detector);

	for (sou = 0; sou < nb_detector; sou++)
	{
		for (i = 0; i < dimension; i++)
		{
			coord[i] = *(detector.nodes + (sou + i*nb_detector));
		}
		int number = mytSearchN(mesh, area_coord, coord[0], coord[1]);
		for (j = 0; j < nb_ever_ele; j++)
		{
			x[sou*nb_ever_ele + j] = *(mesh.elements + number - 1 + j*nb_elements) - 1;
			y[sou*nb_ever_ele + j] = sou;
			value[sou*nb_ever_ele + j] = area_coord[j] * 0.98877107793604;
		}
	}

	tripletList.reserve(estimation_of_entries);
	for (int i = 0; i < estimation_of_entries; i++)
	{
		tripletList.push_back(T(x[i], y[i], value[i]));
	}
	mat.setFromTriplets(tripletList.begin(), tripletList.end());
	return mat;
}