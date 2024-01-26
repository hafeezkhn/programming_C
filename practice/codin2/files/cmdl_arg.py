#!/bin/python3
import sys
#prints complete list
print(sys.argv)
#prints itaratively
for i in range(len(sys.argv)):
    if i == 0:
        print("Name:",sys.argv[0])
    else:
        print(f"{i}. argument: {sys.argv[i]}")


