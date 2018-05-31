#include"qvec.h"
SparseMatrixType qvec(Mesh &mesh, Source &source)
{
	//创建三元数组
	int sou, i, j;
	int estimation_of_entries = 4 * nb_source;
	int *x = new int[4 * nb_source];
	int *y = new int[4 * nb_source];
	double *value = new double[4 * nb_source];
	for (int i = 0; i < 4 * nb_source; i++)
	{
		x[i] = 0;
		y[i] = 0;
		value[i] = 0.0;
	}
	double coord[3] = {0.0,0.0,0.0};
	double volume_coord[4] = { 0, 0, 0,0 };
	cout << nb_ever_ele << endl;
    //创建存储triplet对象的容器与空的稀疏矩阵
	std::vector<T> tripletList;
	SparseMatrixType mat(nb_nodes, nb_source);

	for (sou= 0; sou < nb_source; sou++)
	{
		for (i = 0; i < dimension; i++)
		{
			coord[i] = *(source.nodes + (sou+i*nb_source));
		}
		int number = mytSearchN3D(mesh, volume_coord, coord[0], coord[1],coord[2]);
		for (j = 0; j < nb_ever_ele; j++)
		{
			x[sou*nb_ever_ele+j] = *(mesh.elements + number - 1 + j*nb_elements)-1;
			y[sou*nb_ever_ele + j] = sou;
			value[sou*nb_ever_ele + j] = volume_coord[j]*0.98877107793604;
			cout << x[sou*nb_ever_ele + j] << " " << y[sou*nb_ever_ele + j] << " " << value[sou*nb_ever_ele + j];
			cout << endl;
		}
		//cout << endl;
	}
	
    tripletList.reserve(estimation_of_entries);
	for (int i = 0; i < estimation_of_entries; i++)
	{
		tripletList.push_back(T(x[i], y[i], value[i]));
	}
	mat.setFromTriplets(tripletList.begin(), tripletList.end());
	
	return mat;
}