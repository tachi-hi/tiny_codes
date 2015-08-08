#!/bin/python

from sys import stdout
import time

for i in range(1,100):
  stdout.write("\r There are " + str(i) + " apples")
  stdout.flush()
  time.sleep(0.1)
