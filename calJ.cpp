#include"calJ.h"
double IntFFF(int i, int j, int k) {
	double intfff;
	//之前的3个系数是直接计算出来积分以后给出的系数
	if (i == j && i == k)
		intfff = 1 / 10.0;
	else if (i == j || i == k || j == k)
		intfff = 1 / 30.0;
	else
		intfff = 1 / 60.0;
	return intfff;
}