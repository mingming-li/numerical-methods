import numpy as np
import matplotlib.pyplot as plt

T,A=np.loadtxt("dft.dat",unpack=True)
plt.plot(T,A)
plt.plot(T,A,'.')
plt.show()
