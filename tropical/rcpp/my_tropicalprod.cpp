#include <R.h>
#include <Rinternals.h>
#include <iostream>
using namespace std;

#include <Rcpp.h>

extern "C"{

	double mymax(double a, double b) {return a > b ? a : b;}
	double INF = -1000000000;

	SEXP tropical_prod(SEXP a_, SEXP b_){
		Rcpp::NumericMatrix a (a_);
		Rcpp::NumericMatrix b (b_);
		int n = a.nrow();
		int r = a.ncol();
		int m = b.ncol();
		Rcpp::NumericMatrix c(n,m);
		PROTECT(c);

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				double max_ = INF;
				for(int k = 0; k < r; k++){
					double tmp = mymax(a(i, k) + b(k, j), INF);
					max_ = mymax(max_, tmp);
				}
				c(i, j) = max_;
			}
		}
		return c;
	}

	SEXP tropical_sum(SEXP a_, SEXP b_){
		Rcpp::NumericMatrix a (a_);
		Rcpp::NumericMatrix b (b_);
		int n = a.nrow();
		int m = b.ncol();
		Rcpp::NumericMatrix c(n,m);
		PROTECT(c);

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				c(i,j) = mymax(a(i, j), b(i, j));
			}
		}
		return c;
	}



	// basics
	SEXP mysum(SEXP a, SEXP b){
		REAL(a)[0] += REAL(b)[0];
		return a;
	}

	void mysum2(double *a, double *b, double *c){
		*c = *a + *b;
	}

}

