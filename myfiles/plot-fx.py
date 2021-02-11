import numpy as np
import matplotlib.pyplot as plt
x=np.linspace(0,1,100)
#y=x**3-3*x+1
#y=1.0*(1.0+x*(1/0.01-1))**2
A=0.5;B=5.0;
y=A-np.exp(B*x);
plt.plot(x,y)
plt.grid()
plt.xlabel('x')
plt.ylabel('f(x)')
#plt.savefig("a.pdf")
plt.show()
