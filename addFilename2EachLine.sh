#!/bin/bash

#---------------------
# a simple awk example
#---------------------

# File exists?
OUTPUT=output_file.txt
if [ -e $OUPUT ];
then
  rm ${OUTPUT}
fi

# input file
INPUT=intput_file.txt

# proc
awk -v fn=${INPUT} '{print fn, "\t", $1}' $INPUT > $OUTPUT
