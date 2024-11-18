import numpy as np 
import matplotlib.pyplot as plt

y = ['a','b' ,'c','d']

meanVel = [0.2474, 0.1235, 0.1737, 0.1824 ]
sdVel = [ 0.3314, 0.2278, 0.2836, 0.2645 ]

plt.bar(y , meanVel  , yerr = sdVel)


plt.show()