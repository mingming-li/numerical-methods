import numpy as np
import matplotlib.pyplot as plt
x,y=np.loadtxt("tmp.dat",unpack=True);
plt.plot(x,y)
plt.grid()
plt.show()
