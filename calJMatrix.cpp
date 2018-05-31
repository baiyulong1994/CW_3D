#include"calJMatrix.h"
bool calJMatrix(Mesh &mesh, Eigen::MatrixXd link, Eigen::MatrixXd &data,
	Eigen::MatrixXd &phi, Eigen::MatrixXd &aphi, Eigen::MatrixXd &j_complete)
{
	int k = 0;
	int nsd = link.rows();
	Eigen::MatrixXd j_complex(nsd, nb_nodes);
	for (int i = 0; i < nsd; i++)
	{
		for (int j = 0; j < nb_nodes; j++)
		{
			j_complex(i,j) = 0.0;
		}
	}
	double *detector_phi=new double[nb_nodes];
	double *adjoint_phi = new double[nb_nodes];
	double *jr = new double[nb_nodes];
	for (int i = 0; i < nb_nodes; i++)
	{
		detector_phi[i] = 0;
		adjoint_phi[i] = 0;
		jr[i] = 0;
	}
	
	for (int i = 0; i <nsd; i++)
	{
		//¹âÔ´µÄ±àºÅ
		int sn = link(i, 0);
		
		//Ì½²âÆ÷µÄ±àºÅ
		int dn = link(i, 1);
		
		for (int i = 0; i <nb_nodes ; i++)
		{
			detector_phi[i] = phi(i,sn-1);
			adjoint_phi[i] = aphi(i, dn - 1);
		}
		
		bool a = calJMatrixRow(mesh, detector_phi, adjoint_phi, jr);
		
		for (int i = 0; i <nb_nodes ; i++)
		{
			j_complex(k, i) = -jr[i];
			j_complete(k, i) = j_complex(k, i) / data(k,0);
			jr[i] = 0;
		}
		k++;
	}
	
}
