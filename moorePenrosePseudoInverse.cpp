#include<Eigen/Core> 
#include<Eigen/SVD>
#include<cassert>

using namespace Eigen;

// temporary version (to be tested later)
// Eigen3 is required
// compile: -I/usr/include/eigen3

const double EPSILON = 1e-10;

MatrixXd moorePenrosePseudoInverse(const MatrixXd& X){
	JacobiSVD< MatrixXd > svd ( X, Eigen::ComputeFullU | Eigen::ComputeFullV );

	const MatrixXd& V = svd.matrixV();
	const VectorXd& S = svd.singularValues();
	const MatrixXd& U = svd.matrixU();

	MatrixXd Sd = MatrixXd::Zero( X.cols(), X.rows() );
	
	for(int i = 0; i != S.rows(); ++i)
		Sd(i,i) = S(i) > EPSILON ? 1 / S(i) : 0;

	return V * Sd * U.transpose();
}


// solve AX = B
MatrixXd mldivide(const MatrixXd& A, const MatrixXd& B){
	assert(A.rows() == B.rows());
	return moorePenrosePseudoInverse(A) * B;
}

