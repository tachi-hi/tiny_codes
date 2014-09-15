#!/bin/bash

# usage: bash ./transposeMatric.sh test1.dat output.dat
# It transposes a matrix data

IN=$1
OUT=$2

if [ -z ${IN} ];
then
	echo "[error] No intput file"
	echo "Usage: bash ./transposeMatric.sh inputMatrixFile.dat outputMatrixFile.dat"
	exit 1
fi

if [ -z ${OUT} ];
then
	echo "[error] No output file"
	echo "Usage: bash ./transposeMatric.sh inputMatrixFile.dat outputMatrixFile.dat"
	exit 1
fi

R --vanilla --slave << EOF
	a <- read.table("${IN}", sep=" ") 
	b <- as.matrix(a) 
	write.table(t(b), file = "${OUT}", row.names=F, col.names=F)
EOF

