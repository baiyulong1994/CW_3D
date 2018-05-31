#ifndef _QVEC_H_
#define _QVEC_H_
#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Sparse>
#include"mesh.h"
#include"source.h"
#include"mytSearchN3D.h"
#include"mytSearchN.h"
typedef Eigen::Triplet<double> T;
typedef Eigen::SparseMatrix<double> SparseMatrixType;
typedef Eigen::MatrixXd Matrix;
//输入mesh和source对象，返回一个光源稀疏矩阵
SparseMatrixType qvec(Mesh &mesh,Source &source);
#endif
