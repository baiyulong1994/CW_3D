#include"reconstractCW3D.h"
#include"loadDoubleRaw.h"
#include<time.h>
//读取探测器数据
//数据个数
bool recosntractCW3D(Mesh &mesh, Mesh &recon_mesh, Source &source, Detector &detector, double *anom_data1, Eigen::MatrixXd &link,
	int iteration, double lamda, int nb_data, string fn)
{
	int nb_iteration = 1;
	double diff = 0.0;
	double pre_diff = 0.0;
	double diff_change = 0.0;
	//double *anom_data1=new double[nb_data];
	bool a = loadDetectorData(anom_data1, nb_data, fn);
	Eigen::MatrixXd anom_data(nb_data, 1);
	for (int i = 0; i < nb_data; i++)
	{
		anom_data(i, 0) = anom_data1[i];
	}



	//bool b = jacobianStand(mesh, source, detector, link, ref_data, j_complete);

	//bool d = jacobianStand(mesh, source, detector, link, ref_data, j_complete);

	for (int i = 0; i < iteration; i++)
	{
		Eigen::MatrixXd ref_data(nb_data, 1);
		Eigen::MatrixXd j_complete(nb_data, nb_nodes);
		for (int i = 0; i < nb_data; i++)
		{
			ref_data(i, 0) = 0;
			for (int j = 0; j < nb_nodes; j++)
			{
				j_complete(i, j) == 0;
			}
		}

		bool a = jacobianStand3D(recon_mesh, source, detector, link, ref_data, j_complete);

		for (int i = 0; i < nb_data; i++)
		{
			ref_data(i, 0) = log(ref_data(i, 0));
		}

		pre_diff = diff;
		diff = 0;
		Eigen::MatrixXd data_diff = anom_data - ref_data;
		for (int i = 0; i < nb_data; i++)
		{
			diff = diff + data_diff(i, 0)*data_diff(i, 0);
		}
		cout << "---------------------------------" << endl;
		cout << "Iteration Number          =" << nb_iteration << endl;
		cout << "Projection error          =" << diff << endl;


		if (nb_iteration != 1)
		{
			diff_change = (pre_diff - diff) / pre_diff * 100;
			cout << "Projection error change   =" << diff_change << "%" << endl;
			if (diff_change <= 2)
			{
				cout << "---------------------------------" << endl;
				cout << "STOPPING CRITERIA REACHED" << endl;
				break;
			}
		}

		for (int i = 0; i < j_complete.rows(); i++)
		{
			for (int j = 0; j < nb_nodes; j++)
			{
				j_complete(i, j) = j_complete(i, j)*recon_mesh.mua[j];
			}
		}

		if (nb_iteration != 1)
		{
			lamda = lamda / 1.77827941003892;
		}

		Eigen::MatrixXd HESS = j_complete*j_complete.adjoint();

		int nrow = HESS.rows();
		int ncol = HESS.cols();
		double hess_max = (HESS.diagonal()).maxCoeff();
		double reg_amp = lamda*hess_max;
		Eigen::MatrixXd reg(nrow, 1);
		reg.setOnes(nrow, 1);
		reg = reg*reg_amp;

		cout << "Amp Regularization        =" << reg(0, 0) << endl;
		for (int i = 0; i < nrow; i++)
		{
			HESS(i, i) = HESS(i, i) + reg(i);
		}

		Eigen::MatrixXd foo = j_complete.adjoint()*(HESS.inverse()*data_diff);

		for (int i = 0; i < nb_nodes; i++)
		{
			foo(i, 0) = recon_mesh.mua[i] * foo(i, 0);
		}

		for (int i = 0; i < nb_nodes; i++)
		{
			recon_mesh.mua[i] += foo(i, 0);
			recon_mesh.kappa[i] = 1 / (3 * recon_mesh.mua[i] + 3 * recon_mesh.mus[i]);
			if (recon_mesh.mua[i] < 0)
			{
				cout << "---------------------------------" << endl;
				cout << "-ve mua calculated...not saving solution" << endl;
				cout << "---------------------------------" << endl;
				cout << "STOPPING CRITERIA REACHED" << endl;
				return true;
			}
		}
		nb_iteration++;
	}
	return true;

}







