#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt
import sys

fileName = sys.argv[1] 
fileName2 = sys.argv[2]
r, e1, m1, P1, Cs1 = np.loadtxt(fileName, unpack=True)
x, e, m, P, Cs = np.loadtxt(fileName2, unpack=True)
#print(r, e1, m1, P1, Cs)
def Plots(x1,y1, x2, y2, yLabel):
    # Plot the first graph
    plt.plot(x1, y1, label='r')
    # Overlay the second graph, adjusted to align with the first plot's x-axis
    plt.plot(x2, y2, label='x')
    plt.xlabel('spatial coordinate[km]')
    plt.ylabel(yLabel)
    plt.tick_params(axis = 'both', direction = 'in', which = 'both')
    plt.legend()
    plt.show()


Plots(r, e1, x, e, r"$\rho[km^{-2}]$")
Plots(r, m1, x, m, r"$M[km]$")
Plots(r, P1, x, P, r"$p[km^{-2}]$")
Plots(r, Cs1, x, Cs, r"$C_s$")