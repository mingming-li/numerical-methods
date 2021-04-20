import numpy as np
import matplotlib.pyplot as plt

xmod,ymod=np.loadtxt("cf.dat.fit",unpack=True)
xobs,yobs=np.loadtxt("cf.dat",unpack=True)

plt.plot(xmod,ymod)
plt.plot(xobs,yobs,'.')
plt.show()
