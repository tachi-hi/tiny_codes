#!/bin/bash

# This script displays an array of numbers in a csv file.
# This requires R and Tcl/Tk
#
#    usage: 
#        showCSV.sh input_file.csv [T of F]
#
# input_file.csv should be like
#   1.1, 2.3, 5.3, 4.4, 2.5
#   5.3, 2.8, 5.4, 2.7, -0.5
#   1.0, 0.6, 0.3, 5.2, 10.0


# Input file name
file=$1

# Flag whether to save or not
flag=$2 # T (save) or F (just display the figure)
if [ -z $flag ]; then flag=F; fi
echo $flag


R --vanilla << EOF
    library(tcltk)
    dat <- as.matrix(read.csv("$file", header=FALSE))
    n <- ncol(dat)
    m <- nrow(dat)
    if($flag==F){
        x11()
    }else{
        png("test.png")
    }
    image (1:m, 1:n, -dat, xlab="", ylab="", col=grey(0:100/100))

    if($flag==F){
        # Following code is from 
        #    http://stackoverflow.com/questions/15272916/how-to-wait-for-a-keypress-in-r
        # 
    
        tt <- tktoplevel()
        tkpack( tkbutton(tt, text='Exit', command=function()tkdestroy(tt)), side='bottom')
        tkbind(tt,'<Key>', function()tkdestroy(tt) )
    
        tkwait.window(tt)    
    }
EOF
