import sys
import numpy as np
import scipy.fftpack
import matplotlib.pyplot as plt

fileName = sys.argv[1] 
fileName2 = sys.argv[2]
t, h, u, s, xx, yy = np.genfromtxt(fileName, unpack=True)
fr = np.genfromtxt(fileName2,unpack = True)


def Signal(t, signal,type):
    # Convert time to seconds by dividing through by the speed of sound in km/s
    t = (t / 2.99792458e5)

    FFT = abs(scipy.fft.fft(signal))
    freqs = scipy.fftpack.fftfreq(signal.size, (t[1] - t[0]))

    plt.subplot(211)
    plt.plot(t, signal, 'k',linewidth = 0.5)
    #plt.yscale('log')
    plt.xlabel('Time(s)')
    plt.tick_params(axis = 'both', direction = 'in',which = 'both')

    plt.subplot(212)
    plt.semilogy(freqs/1000, FFT, 'k', linewidth = 0.5)
    plt.xlabel('Frequency in kHz')
    plt.xlim(0, 50)  # Output is in Hz. Restricting to 50kHz
    plt.tick_params(axis = 'both', direction = 'in', which = 'both')
    
    FFTmax = []
    for i in range(len(fr)):
        FFTmax.append(np.max(FFT)/4)

    plt.scatter(fr, FFTmax, s = 20, c = 'black', alpha = 0.5, marker = 'o')

    plt.subplots_adjust(hspace=0.5)

    # plt.ylim(0, 1)  # Uncomment and adjust ylim as needed
    plt.savefig('Plots/PowerSpectrum_for_'+type+'.png')
    plt.show()

Signal(t, h, 'h'); #: Amplitude and the Power Spectrum of the function h
Signal(t, u, 'u'); #: Amplitude and the Power Spectrum of the function u
Signal(t, s, 's'); #: Amplitude and the Power Spectrum of the function s

