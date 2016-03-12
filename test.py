#!/usr/bin/python

import matplotlib.pyplot as plt
import numpy as np

pi=np.pi
sin=np.sin

t=np.arange(0,2*pi,0.001)
x=sin(2*pi*t)
plt.plot(t,x)
plt.show()
