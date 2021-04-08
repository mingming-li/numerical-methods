import numpy as np
import matplotlib.pyplot as plt

x,y=np.loadtxt("fnew.dat",unpack=True)
plt.plot(x,y)
plt.show();
