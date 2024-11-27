import numpy as np

arr = np.random.randint(10,50,(6,6))

print('the original 6x6 matrix is:\n' , arr)

arr[arr % 2 == 0] = -1

print(arr)