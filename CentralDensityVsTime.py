#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt
import sys

fileName = sys.argv[1] 
#fileName2 = sys.argv[2]
#r, e1, m1, P1, Cs1 = np.loadtxt(fileName, unpack=True)
r, e, m, P, Cs = np.loadtxt(fileName, unpack=True)
#print(r, e1, m1, P1, Cs)
def Plots(x1, y1, yLabel, TYPE):
    # Plot the first graph
    plt.plot(x1, y1, color = 'black', linewidth = 0.8)
    # Overlay the second graph, adjusted to align with the first plot's x-axis
    plt.xlabel('r[km]')
    plt.ylabel(yLabel)
    plt.tick_params(axis = 'both', direction = 'in', which = 'both')
    #plt.legend()
    plt.savefig('Plots/PLOT_for_'+TYPE+'.png')
    plt.show()
   

Plots(r, e, r"$\rho[km^{-2}]$", 'e')
Plots(r, m, r"$M[km]$", 'm')
Plots(r, P, r"$p[km^{-2}]$", 'P')
Plots(r, Cs, r"$C_s$", 'Cs')