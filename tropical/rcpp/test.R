library(Rcpp)
#library(inline)

dyn.load("my_tropicalprod.so")

trprod <- function(a,b){ 
    .Call("tropical_prod",
      arg1=as.matrix(a),
      arg2=as.matrix(b)
	)
}

trplus <- function(a,b){ 
    .Call("tropical_sum",
      arg1=as.matrix(a),
      arg2=as.matrix(b)
	)
}

mysum <- function(a,b){ 
    .Call("mysum",           #Cルーチン名
      arg1=as.double(a), #Cルーチン第1引数の型指定
      arg2=as.double(b) #Cルーチン第2引数
	  )
}

mysum2 <- function(a,b){ 
    tmp <- .Call("mysum",           #Cルーチン名
      arg1=as.double(a), #Cルーチン第1引数の型指定
      arg2=as.double(b), #Cルーチン第2引数
      arg3=as.double(1) #Cルーチン第2引数
	  )
	tmp
}

a1 <- runif(30); dim(a1) <- c(3,10)
a2 <- runif(30); dim(a2) <- c(3,10)
b1 <- runif(50); dim(b1) <- c(10, 5)
b2 <- runif(50); dim(b2) <- c(10, 5)

c <- trplus(a1, a2)
d <- trprod(a1, a2)


