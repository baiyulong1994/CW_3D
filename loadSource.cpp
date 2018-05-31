#include"loadSource.h"
#include"loadDoubleRaw.h"
bool loadSource(string file_path, Source &source)
{
	errno_t err;
	bool a = loadDataDoubleRaw(source.nodes, file_path + ".source", nb_source*dimension);
	if (err = a== 0)
	{
		cout << "There is something worng with the input data!" << endl;
		return false;
	}
	cout << "The source data has been loaded successfully!" << endl;
}