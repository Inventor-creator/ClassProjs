import numpy as np 
import matplotlib.pyplot as plt

prods =  ["A", "B", "C", "D", "E"]
sales = [15, 30, 25, 10, 20] 
plt.subplot(1,2,1)
plt.title("The Bar Chart")
plt.bar(prods , sales )
plt.subplot(1,2,2)

plt.title("The Pie Chart")
plt.pie(sales)
plt.legend(prods)

plt.show()
