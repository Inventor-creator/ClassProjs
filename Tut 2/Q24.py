import matplotlib.pyplot as plt
import numpy as np

height = np.array([150 , 160 , 170 , 175 , 180])
#height in cm
weight = np.array([50,60,80,65,90])

BMI = weight / (height * 0.01 ) ** 2
print('the bmi array is: ', np.array(BMI))

plt.subplot(2,2,1)
plt.title("The scatter of height and BMI")
plt.scatter(height , np.array(BMI))
plt.grid()
plt.xlabel("Heights")
plt.ylabel("BMIs ")

plt.subplot(2,2,2)
plt.title("The bar plot of weight and bmi")
plt.bar(weight , np.array(BMI))
plt.grid()
plt.xlabel("Weight")
plt.ylabel("BMIs")

plt.subplot(2,2,3)
plt.title("line plot of height and weight")
plt.plot(height , weight)
plt.grid()
plt.xlabel("height")
plt.ylabel("weight")


plt.show()