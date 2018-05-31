#include"loadLink.h"



Eigen::MatrixXd loadLink(string filename, const int column)
{
	FILE *stream = NULL;
	errno_t err;
	double *link = new double[column * 2];
	Eigen::MatrixXd mt(column, 2);
	loadDataDoubleRaw(link,  filename, column*2);
	// Open for read (will fail if file "crt_fopen_s.c" does not exist)
	
	int ii = 0;
	for (int i = 0; i != column; i++)
	{
		for (int j = 0; j != 2; j++)
		{
			mt(i,j)= *(link +ii);
			ii++;
		}

	}
	return mt;
}