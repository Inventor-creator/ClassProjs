import numpy as np 
import matplotlib.pyplot as plt

plt.subplot(2,2,1)
x = [5, 7, 8, 7, 2, 17, 2, 9, 4, 11]
y = [99, 86, 87, 88, 100, 86, 103, 87, 94, 78] 

plt.title("This is the linechart")
plt.plot(x)
plt.plot(y)


plt.subplot(2,2,2)
plt.title("This is the scatterplot")
plt.scatter(x,y)


plt.subplot(2,2,3)
plt.title("This is the Histogram")
data = [22, 87, 5, 43, 56, 73, 55, 54, 11, 20, 51, 5, 79, 31, 27]
plt.hist(data , bins = 5 , edgecolor = 'black')

plt.subplot(2,2,4)
plt.title("This is the barchart")
categories = ['A', 'B', 'C', 'D']
values = [5, 7, 3, 8]

plt.bar(categories , values)


plt.show()