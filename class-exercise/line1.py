import numpy as np
import matplotlib.pyplot as plt

n,area,area2=np.loadtxt("tmp.dat",unpack=True)
plt.plot(n,area,label="Trapezoid")
plt.plot(n,area2,label="Constant")
plt.legend()
plt.xlim(2,10)
plt.ylim(2.75,3.0)
plt.xlabel("n number")
plt.ylabel("area")
plt.savefig("b.pdf")
plt.show()
