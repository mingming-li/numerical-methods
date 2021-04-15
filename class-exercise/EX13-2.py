import numpy as np
import matplotlib.pyplot as plt

x,f,fnew=np.loadtxt("fnew.dat",unpack=True)
plt.plot(x,f)
plt.plot(x,fnew)
plt.show()
