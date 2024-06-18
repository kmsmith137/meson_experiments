import os
import ctypes
import numpy as np

# Assumes that meson shared_library('name' ...) creates filename 'libname.so'.
_libgpu_mm = ctypes.cdll.LoadLibrary(os.path.join(os.path.dirname(__file__), 'libexample_ctypes_module.so'))

# https://docs.python.org/3/library/ctypes.html#fundamental-data-types
_sum_cda = _libgpu_mm.sum_contiguous_double_array
_sum_cda.argtypes = (ctypes.c_void_p,)
_sum_cda.restype = ctypes.c_double

def sum_contiguous_double_array(arr):
    assert arr.dtype == float
    assert arr.flags.c_contiguous
    return _sum_cda(arr.ctypes.data, arr.size)
