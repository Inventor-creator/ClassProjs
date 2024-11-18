import numpy as np 
import matplotlib.pyplot as plt


normalArr = np.arange(1,20.01,1.25)

print('the regular array is: ' , normalArr)

logArray = np.log(normalArr)

print('the logarithmic array is ' , logArray)

cosArray = np.cos(normalArr)
plt.subplot(2,2,1)
plt.plot(normalArr)
plt.plot(cosArray , 'green' , linestyle = '-.')



plt.subplot(2,2,2)
plt.scatter(logArray,normalArr , marker  = 'd' , color = 'blue')
plt.subplot(2,2,3)
plt.scatter(cosArray,normalArr , marker  ='o' , color ='black')

plt.show()