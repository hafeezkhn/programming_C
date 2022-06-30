from ctypes import *

libcalc = CDLL("./libcal.so")
libcalc.connect()
