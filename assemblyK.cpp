#include"assemblyK.h"
SparseMatrixType assemblyK(Mesh &mesh)
{
	errno_t err;
	//定义有关K矩阵存储信息的矩阵
	const int nzmax = nb_elements*(nb_ever_ele*(nb_ever_ele + 1));
	int estimation_of_entries = 0;
	int *I = new int[nzmax];
	int *J = new int[nzmax];
	double *Sr = new double[nzmax];
	double *Si = new double[nzmax];
	for (int i = 0; i < nzmax; i++)
	{
		I[i] = 0.0;
		J[i] = 0.0;
		Sr[i] = 0.0;
	}
	std::vector<T> tripletList;
	SparseMatrixType mat(nb_nodes, nb_nodes);
	
	if ((err=calMassMatrix(mesh, I, J, Sr, Si)) == false)
	{
		cout << "刚度矩阵计算错误" << endl;
	}
	else
	{
		for (int i = 0; i < nzmax; i++)
		{
			if (I[i] != 0)
			{
				I[i] = I[i] - 1;
				J[i] = J[i] - 1;
				estimation_of_entries++;
				/*if (I[i] < 0 || I[i]>2029 || J[i] < 0 || J[i]>2029)
				{
					cout << I[i]<< endl;
					cout << J[i] << endl;
				}*/
			}
		}
	}
	tripletList.reserve(estimation_of_entries);
	for (int i = 0; i < estimation_of_entries; i++)
	{
		tripletList.push_back(T(I[i], J[i], Sr[i]));
	}
	mat.setFromTriplets(tripletList.begin(), tripletList.end());
	delete I;
	delete J;
	delete Sr;
	
	return mat;
}