import numpy as np
import matplotlib.pyplot as plt
x,y1,y2,y3=np.loadtxt("tmp.dat",unpack=True);
plt.plot(x,y1,label="Rectangle method")
plt.plot(x,y2,label="Trapezoid method")
plt.plot(x,y3,label="Simpson's method")
plt.legend()
plt.xlim(2,20)
plt.ylim(0.5,2.0)
plt.xlabel("n")
plt.ylabel("area")
plt.savefig("hw04.pdf")
plt.show()
