import numpy as np
import matplotlib.pyplot as plt

x,y=np.loadtxt("EX08.output.dat",unpack=True);
plt.plot(x,y,label="linear interp.")
plt.plot(x,y,'.',label="linear interp.")



x,y=np.loadtxt("EX08.dat",unpack=True);
plt.plot(x,y,'.',label="obs. data")

plt.show()
