#include"loadMesh.h"
#include"loadDoubleRaw.h"
//加载网格数据的函数，需要的参数：1.存储数据的路径 2.网格对象的指针
bool loadMesh(string file_path, Mesh &mesh)
{
	errno_t err;
	bool a = loadDataDoubleRaw(mesh.nodes, file_path + ".nodes", nb_nodes*dimension);
	bool b = loadDataDoubleRaw(mesh.elements, file_path + ".elements", nb_elements*nb_ever_ele);
	bool c = loadDataDoubleRaw(mesh.bndvtx, file_path + ".bndvtx", nb_nodes);
	bool d = loadDataDoubleRaw(mesh.mua, file_path + ".mua", nb_nodes);
	bool e = loadDataDoubleRaw(mesh.kappa, file_path + ".kappa", nb_nodes);
	bool f = loadDataDoubleRaw(mesh.ksir, file_path + ".ksir", nb_nodes);
	bool g = loadDataDoubleRaw(mesh.c, file_path + ".c", nb_nodes);
	bool h= loadDataDoubleRaw(mesh.mus, file_path + ".mus", nb_nodes);
	if ((err = a&&b&&c&&d&&e&&f&&g&&h) == 0)
	{
		cout << "There is something worng with the input data!"<<endl;
		return false;
	}
	cout << "The mesh data has been loaded successfully!"<<endl;

	
	return true;
}