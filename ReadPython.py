#!/usr/bin/python

import matplotlib.pyplot as plt
import numpy as np
import pylab as pylab
import sys


FrameFile = sys.argv[1]
FrameFile2 = sys.argv[2]
print(FrameFile, FrameFile2)
values1 = [];
values2 = [];
values3 = [];
values4 = [];
values5 = [];
values6 = [];
values7 = [];
values8 = [];
values9 = []
values1,values2,values3,values4,values5,values6,values7,values8,values9 = np.loadtxt(FrameFile, unpack = True)

values11 = [];
values12 = [];
values13 = [];
values14 = [];
values15 = [];
values16 = [];
values17 = [];
values18 = [];
values19 = []
values11,values12,values13,values14,values15,values16,values17,values18,values19 = np.loadtxt(FrameFile2, unpack = True)
#plt.plot(np.array(values1), np.array(values5))
#plt.show()
fig, axs = plt.subplots(nrows = 4, ncols = 2, figsize = (7, 7))

# plot time signal: #axs[0, 0].set_title("")
axs[0, 0].plot(
    np.array(values1),
    np.array(values3),
    'o',
    ms = 0.5,
    label = 'T1'
)
axs[0, 0].plot(np.array(values1), np.array(values13), label = 'T2')
axs[0, 0].set_xlabel("R(km)")
axs[0, 0].set_ylabel(r"$e$")
axs[0, 0].legend()
# plot different spectrum types: #axs[1, 0].set_title("Magnitude Spectrum")
axs[0, 1].plot(
    np.array(values1),
    np.array(values4),
    'o',
    ms = 0.5,
    label = 'T1'
)
axs[0, 1].plot(np.array(values1), np.array(values14), label = 'T2')
axs[0, 1].set_xlabel("R(km)")
axs[0, 1].set_ylabel(r"$p$")
axs[0, 1].legend()
#axs[1, 1].set_title("Log. Magnitude Spectrum")
axs[1, 0].plot(
    np.array(values1),
    np.array(values5),
    'o',
    ms = 0.5,
    label = 'T1'
)
axs[1, 0].plot(np.array(values1), np.array(values15), label = 'T2')
axs[1, 0].set_xlabel("R(km)")
axs[1, 0].set_ylabel(r"$\lambda$")
axs[1, 0].legend()
#axs[2, 0].set_title("Phase Spectrum ")
axs[1, 1].plot(
    np.array(values1),
    np.array(values6),
    'o',
    ms = 0.5,
    label = 'T1'
)
axs[1, 1].plot(np.array(values1), np.array(values16), label = 'T2')
axs[1, 1].set_xlabel("R(km)")
axs[1, 1].set_ylabel(r"$\nu$")
axs[1, 1].legend()
#axs[2, 1].set_title("Angle Spectrum")
axs[2, 0].plot(
    np.array(values1),
    np.array(values7),
    'o',
    ms = 0.5,
    label = 'T1'
)
axs[2, 0].plot(np.array(values1), np.array(values17), label = 'T2')
axs[2, 0].set_xlabel("R(km)")
axs[2, 0].set_ylabel(r"$\nu^{'}$")
axs[2, 0].legend()
axs[2, 1].plot(
    np.array(values1),
    np.array(values8),
    'o',
    ms = 0.5,
    label = 'T1'
)
axs[2, 1].plot(np.array(values1), np.array(values18), label = 'T2')
axs[2, 1].set_xlabel("R(km)")
axs[2, 1].set_ylabel(r"$\lambda^{'}$")
axs[2, 1].legend()
axs[3, 0].plot(
    np.array(values1),
    np.array(values9),
    'o',
    ms = 0.5,
    label = 'T1'
)
axs[3, 0].plot(np.array(values1), np.array(values19), label = 'T2')
axs[3, 0].set_xlabel("R(km)")
axs[3, 0].set_ylabel(r"$c_s$")
axs[3, 0].legend()
fig.tight_layout()
plt.show()

