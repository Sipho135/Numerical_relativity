#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt
import sys

# Define time values (you can modify this)
time = np.linspace(0, 10000, 283015)  # Example time values from 0 to 10

def ReadFile():
    density = np.loadtxt(sys.argv[1])
    return np.array(density)/density[0]


rho_c_over_rho_c0 = ReadFile()
# Create the plot
plt.figure(figsize=(8, 6))
plt.plot(time, rho_c_over_rho_c0, label=r'$\rho_c/\rho_{c,0}$')
plt.xlabel('Time')
plt.ylabel(r'$\rho_c/\rho_{c,0}$')
plt.title('Central Energy Density vs Time')
plt.grid(True)
plt.legend()
plt.show()