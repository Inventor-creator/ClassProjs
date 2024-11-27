import matplotlib.pyplot as plt
import numpy as np

monthNum = [1,4,7,10,12]
totalProf = [1200,200,800,1500,1700]

plt.xlabel('Month Number')
plt.ylabel('Total profit in INR ')
plt.plot(monthNum , totalProf , '-or')

plt.show()