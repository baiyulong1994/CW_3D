#include"mytSearchN.h"
#include"inTraingle.h"
int mytSearchN(Mesh &mesh, double *area_coord, double x, double y)
{
	for (int i = 1; i <= nb_elements; ++i)
	{
		if (inTraingle(mesh, i, x, y,area_coord))
		{
			return i;
		}
	}
	return -1;
}
//guture