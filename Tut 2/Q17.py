import numpy as np 
import matplotlib.pyplot as plt

closingVals = np.random.randint(350, 400 , (1,3))

plt.plot(closingVals[0])
plt.grid(which='both')
plt.tick_params(axis='both',length = 0)

plt.show()