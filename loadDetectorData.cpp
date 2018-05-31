#include"loadDetectorData.h"
bool loadDetectorData(double *anom_data,int nb_data,string fn)
{
	
	bool a=loadDataDoubleRaw(anom_data, fn + ".anom_data", nb_data);
	for (int i = 0; i < nb_data; i++)
	{
		anom_data[i] = log(anom_data[i]);
	}
	return true;
}
