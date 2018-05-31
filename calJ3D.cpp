#include"calJ3D.h"
inline double IntFFF3D(int i, int j, int k)
{
	if (i == j && j == k) return 0.05;
	else
	{
		if (j == k || j == i || k == i) return 0.01666666667;
		else
			return 0.00833333333;
	}
}