#!/bin/python

from sys import stdout

for i in range(1,100):
  stdout.write("\r There are " + str(i) + "apples")
  stdout.flush()
