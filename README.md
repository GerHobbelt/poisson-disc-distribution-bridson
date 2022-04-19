<!--
 * @Author: xunmeibuyue
 * @Date: 2021-12-21 14:09:29
 * @LastEditors: xunmeibuyue
 * @LastEditTime: 2021-12-21 14:38:19
 * @Encoding: UTF-8
 * @Description: file content
-->
# Poisson disc distribution

A Poisson disc distribution method based on [poisson-disc-distribution-bridson](https://github.com/martynafford/poisson-disc-distribution-bridson).

Compile it to `.so` library so that it can be used in python.

## Compile

``` bash
g++ -shared -Wl,-soname,FPD_Random -o FPD_Random.so -fPIC src/FPD_Random.cpp
```

## Usage

``` python
from numpy.ctypeslib import ndpointer
from ctypes import c_int, c_double
import ctypes

width = 5184
height = 3456
min_distance = 10.0

lib = ctypes.cdll.LoadLibrary('FPD_Random.so')
lib.get_FPD_Random.argtypes = [c_int, c_int, c_double, c_int]
lib.get_FPD_Random.restype = ndpointer(dtype=c_int, shape=(width*height,))

res = lib.get_FPD_Random(width, height, min_distance, 100)
random = res.reshape((height, width))
```
