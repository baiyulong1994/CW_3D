#include"calJ.h"
double IntFFF(int i, int j, int k) {
	double intfff;
	//֮ǰ��3��ϵ����ֱ�Ӽ�����������Ժ������ϵ��
	if (i == j && i == k)
		intfff = 1 / 10.0;
	else if (i == j || i == k || j == k)
		intfff = 1 / 30.0;
	else
		intfff = 1 / 60.0;
	return intfff;
}