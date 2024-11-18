import numpy as np 
import matplotlib.pyplot as plt

Months = ['Jan', 'Feb', 'Mar','Apr', 'May','Jun','Jul','Aug','Sep', 'Oct','Nov','Dec'] 
sales= [12000, 15000, 13000, 17000, 14000, 17000, 18000, 17000, 17700, 18900, 20000, 21000]

plt.title("Sales V/S Months ")
plt.xlabel('Months')
plt.ylabel('Sales')
plt.plot(Months , sales , 'o' , linestyle = '-')

plt.grid()




plt.show()
