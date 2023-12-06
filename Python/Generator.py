import numpy as np


#: convert density from g/cm^3 to km^{-2}
def CONVERTOR(const, point_array):
    new = np.zeros(len(point_array))
    for i in range(len(point_array)):
        new[i] = format(i/const, 'e')
    return new

#: generate values of densities from START to END with the given number POINTS
def RANGE(start, end, num_points):
    return np.linspace(start, end, num_points)

#: Write your the densities values into a text file and place that file into folder bin
def WRITE(array):
    with open('bin/Densities.txt', 'w') as file:
        for i in array:
            file.write(str(i)+'\n')

    return 'done!'
#: define the main method

def main():
    num_points = 50  #: number of points
    start = 1e14    #: starting density
    end = 2e16      #: end point density
    const = 1.346635096409055e18 #: conversion constant between g/cm^3 and km^{-2}

if __name__=='__main__':
    main()