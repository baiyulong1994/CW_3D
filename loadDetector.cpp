#include"loadDetector.h"
#include"loadDoubleRaw.h"
bool loadDetector(string file_path, Detector &detector)
{
	errno_t err;
	bool a = loadDataDoubleRaw(detector.nodes, file_path + ".detector", nb_detector*dimension);
	if (err = a == 0)
	{
		cout << "There is something worng with the input data!" << endl;
		return false;
	}
	cout << "The dectector data has been loaded successfully!" << endl;
}