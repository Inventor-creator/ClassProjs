import numpy as np

height = np.array([150 , 160 , 170 , 175 , 180])
#height in cm
weight = np.array([50,60,80,65,90])

BMI = weight / (height * 0.01 ) ** 2
print('the bmi array is: ', np.array(BMI))


