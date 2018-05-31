#include"genSourceAdjoint3D.h"
SparseMatrixType genSourceAdjoint3D(Mesh &mesh, Detector &detector)
{
	//������Ԫ����
	int sou, i, j;
	int estimation_of_entries = 4 * nb_detector;
	int *x = new int[4 * nb_detector];
	int *y = new int[4 * nb_detector];
	double *value = new double[4 * nb_detector];
	for (int i = 0; i < 4 * nb_detector; i++)
	{
		x[i] = 0;
		y[i] = 0;
		value[i] = 0.0;
	}
	double coord[3] = { 0.0, 0.0, 0.0 };
	double volume_coord[4] = { 0, 0, 0, 0 };
	cout << nb_ever_ele << endl;
	//�����洢triplet�����������յ�ϡ�����
	std::vector<T> tripletList;
	SparseMatrixType mat(nb_nodes, nb_detector);

	for (sou = 0; sou < nb_detector; sou++)
	{
		for (i = 0; i < dimension; i++)
		{
			coord[i] = *(detector.nodes + (sou + i*nb_detector));
		}
		int number = mytSearchN3D(mesh, volume_coord, coord[0], coord[1], coord[2]);
		for (j = 0; j < nb_ever_ele; j++)
		{
			x[sou*nb_ever_ele + j] = *(mesh.elements + number - 1 + j*nb_elements) - 1;
			y[sou*nb_ever_ele + j] = sou;
			value[sou*nb_ever_ele + j] = volume_coord[j] * 0.98877107793604;
			cout << x[sou*nb_ever_ele + j] << " " << y[sou*nb_ever_ele + j] << " " << value[sou*nb_ever_ele + j];
			cout << endl;
		}
		cout << endl;
	}

	tripletList.reserve(estimation_of_entries);
	for (int i = 0; i < estimation_of_entries; i++)
	{
		tripletList.push_back(T(x[i], y[i], value[i]));
	}
	mat.setFromTriplets(tripletList.begin(), tripletList.end());

	return mat;
}