import matplotlib.pyplot as plt
import numpy as np

companies = ['Samsung' , 'Apple' ,'Xiaomi' , 'vivo' , 'OPPO' , 'Others']
share = [ 18.4 , 15.6, 14.5,8.8,8.8,33.8]

plt.title("Pie chart of companies and their marketshare")
plt.pie(share , labels=companies)


plt.show()