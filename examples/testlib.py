#!/usr/bin/python

import ctypes

def main():
    LibHello = ctypes.cdll.LoadLibrary('libhello.so')
    print LibHello.sum(5,3)

if __name__ == '__main__':
    main()

