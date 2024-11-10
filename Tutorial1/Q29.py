import numpy as np

arr = np.random.randint(2,100, (3,3))
print(f'the original array:\n{arr}')

determinat = np.linalg.det(arr)



print(f'the determinant of the array is: {determinat} ')