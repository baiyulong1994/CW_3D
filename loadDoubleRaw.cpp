#include "loadDoubleRaw.h"

bool loadDataDoubleRaw(double* ga, string filename, const int nb)
{
	FILE *stream = NULL;
	errno_t err;

	// Open for read (will fail if file "crt_fopen_s.c" does not exist)
	if ((err = fopen_s(&stream, filename.c_str(), "rb")) != 0)
	{
		printf("The file  was not opened\n");
		return false;
	}
	for (int i = 0; i != nb; i++)
	{
		fread(&ga[i], sizeof(double), 1, stream); 
	}

	fclose(stream); 
	stream = NULL;
	return true;
}
      