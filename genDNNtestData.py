#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" 
This script generates a toy data that can be used 
another trainig/validation/test data for the 
Theano-based deep learning code 
(Its default dataset is the mnist.pkl.gz)
"""

import numpy
import cPickle as pickle
import os
import random

dat = []
lab = []

dat.append([1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0])
lab.append(0)

dat.append([1,1,1,1,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0])
lab.append(1)

dat.append([0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0])
lab.append(2)

dat.append([0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1])
lab.append(3)

dat.append([1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1])
lab.append(4)

def addNoiseOne(x):
	return x + random.random() * 0.1

def addNoise(x):
	return map (addNoiseOne, x)

ds = []
ls = []
ds_v = []
ls_v = []
ds_t = []
ls_t = []
for i in range(10000):
    for j in range(5):
		print j, lab[j]
		ds.append(addNoise(dat[j]))
		ls.append(lab[j])

for i in range(1000):
    for j in range(5):
		ds_v.append(addNoise(dat[j]))
		ls_v.append(lab[j])

for i in range(1000):
    for j in range(5):
		ds_t.append(addNoise(dat[j]))
		ls_t.append(lab[j])

ds = numpy.array(ds, dtype=numpy.float32)
ls = numpy.array(ls, dtype=numpy.int32)

ds_v = numpy.array(ds_v, dtype=numpy.float32)
ls_v = numpy.array(ls_v, dtype=numpy.int32)

ds_t = numpy.array(ds_t, dtype=numpy.float32)
ls_t = numpy.array(ls_t, dtype=numpy.int32)

z = []
z.append((ds, ls))
z.append((ds_v, ls_v))
z.append((ds_t, ls_t))

print z

pickle.dump(z, open("test.pkl", "w"))
os.system("gzip test.pkl")
