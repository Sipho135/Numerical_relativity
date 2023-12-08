# Numerical relativity
This code solves the TOV equations derived from a static spherically symmetric Schwarzschild metric and the Einstein field equations, where the energy-momentum tensor is for a perfect fluid. C++ code solves the TOV equations equations for given some initial Central density, and using the polytropic EOS we can the find the interior composition of a the neutron star such as Mass, Pressure, Density. We are working with two types of coordinates, the r-coordinate and the x-coordinate and we use geometric units in our solutions. 

For the r-coordinate, the C++ code produces an output with 9 columns, and that output is used as the input to solve the sturm Liovelle problem to get the eigen frequencies. 

For the x-coordinate, the C++ code produces another 9 columns output that acts and input to the perturbed radial equations for the ADM formalism to find solutions to the perturbed metric h, entropy s, and 4-velocity u.

## How build the code
run the Makefile

-- make
## execute the code
make run

## clean the code

make clean