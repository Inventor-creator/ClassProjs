import matplotlib.pyplot as plt
import numpy as np

months = ["January", "February", "March", "April", "May", "June",  "July", "August", "September", "October", "November", "December"] 
temperatures = [5, 7, 10, 15, 20, 25, 30, 29, 22, 16, 10, 6] 
winter = [10, 6 , 5]
summer = temperatures[5:8]
spring = temperatures[2:5]
autumn = temperatures[8:11]
seasons = ['winter', 'spring' ,'summer', 'autumn']

avg=[np.sum(winter)/ 3 ,np.sum(summer)/ 3,np.sum(spring)/ 3,np.sum(autumn)/ 3]


plt.subplot(1,2,1)
plt.bar(months,temperatures )
plt.title("Temps vs Months")
plt.grid()

plt.subplot(1,2,2)
plt.title("seasons and average temp")
plt.bar(seasons, avg )



plt.show()