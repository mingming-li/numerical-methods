import numpy as np
import matplotlib.pyplot as plt
x,y1,y2,y3=np.loadtxt("tmp.dat",unpack=True);
plt.plot(x,y1,label="y1")
plt.plot(x,y2,label="y2")
plt.plot(x,y3,label="y3")
plt.legend()
plt.grid()
plt.show()
