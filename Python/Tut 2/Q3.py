import numpy as np 
import matplotlib.pyplot as plt

months = ['Jan' ,'Feb', 'Mar', 'Apr' ,'May' ,'June' ,'Jul', 'Aug' ,'Sep', 'Oct', 'Nov', 'Dec']
salesData = np.random.randint(500000 , 1000000 ,(1,12))
maxMonth = np.argmax(salesData )


plt.title('Barchart of SalesData V/S months')
plt.bar(months, salesData[0])
plt.bar(months[maxMonth], salesData[0][maxMonth], color = 'red')
plt.ylabel("The sales for the month normalized as max")
plt.xlabel("Months")


plt.show()