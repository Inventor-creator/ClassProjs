import numpy as np 
import matplotlib.pyplot as plt

fiftyDataX = np.random.randint(1,1000 , (1,50))
fiftyDataY = np.random.randint(1,1000 , (1,50))

avgX = np.sum(fiftyDataX) / 50
avgY = np.sum(fiftyDataY) / 50


plt.title("THe scatterplot of 50 random datapoints")


plt.scatter(fiftyDataX , fiftyDataY , s = 3)
plt.scatter(avgX , avgY , color = 'red' ,s = 3 )
plt.show()