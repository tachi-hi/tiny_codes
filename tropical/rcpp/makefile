
# how to install Rcpp
# (1) install.packages("Rcpp")
# or
# (2) apt-get install r-cran-rcpp

all:
	PKG_CPPFLAGS=`Rscript -e 'Rcpp:::CxxFlags()'` \
	PKG_LIBS=`Rscript -e 'Rcpp:::LdFlags()'` \
	R CMD SHLIB my_tropicalprod.cpp

clean:
	rm *.o *.so
