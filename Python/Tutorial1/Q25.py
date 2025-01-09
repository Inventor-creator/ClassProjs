import numpy as np

ogArray = np.array([1,2,3,4,5,6,7,8,9])

evenArr = ogArray[ogArray % 2 == 0]

print(f'the even elements from the original array are: {evenArr}')