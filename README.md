# Poisson disc distribution

A Poisson disc distribution method based on [poisson-disc-distribution-bridson](https://github.com/martynafford/poisson-disc-distribution-bridson).

Compile it to `.so` library so that it can be used in python.

## Compile

``` bash
g++ -shared -Wl,-soname,FPD_Random -o FPD_Random.so -fPIC FPD_Random.cpp
```

## Usage

``` python
from numpy.ctypeslib import ndpointer
from ctypes import POINTER, c_bool, c_int, c_double
import ctypes
lib = ctypes.cdll.LoadLibrary('FPD_Random.so')

width = 5184
height = 3456
min_distance = 10.0

lib = ctypes.cdll.LoadLibrary('FPD_Random.so')
lib.get_FPD_Random.argtypes = [c_int, c_int, c_double]
lib.get_FPD_Random.restype = ndpointer(dtype=ctypes.c_int, shape=(width*height,))

res = lib.get_FPD_Random(width, height, min_distance)
random = res.reshape((height, width))
```
