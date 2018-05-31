#include"mesh.h"
#ifndef _LOADDOUBLERAW_H_
#define _LOADDOUBLERAW_H_
//bool loadDataDouble(double ga[][dimension], string filename, const int column)
//{
//	FILE *stream = NULL;
//	errno_t err;
//
//	// Open for read (will fail if file "crt_fopen_s.c" does not exist)
//	if ((err = fopen_s(&stream, filename.c_str(), "rb")) != 0)
//	{
//		printf("The file  was not opened\n");
//		return false;
//	}
//	for (int i = 0; i != column; i++)
//	{
//		for (int j = 0; j != dimension; j++)
//		{
//			fread(&ga[i][j], sizeof(double), 1, stream);
//		}
//
//	}
//
//	fclose(stream);
//	stream = NULL;
//
//	return true;
//
//}

//double向量的读取函数
bool loadDataDoubleRaw(double* ga, string filename, const int nb);
#endif