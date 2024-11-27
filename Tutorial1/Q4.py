import numpy as np

arra = np.array([[1,2,3],
                 [4,5,6],
                 [7,8,9]])

tofind = 3

index = np.argwhere(arra == tofind)
print(f'The element you are trying to find is at {index[0][0] + 1} , {index[0][1] + 1}')

toSort = np.random.randint(0 , 100 , (1,10))
print(f'the random array to sort is as follows: \n{toSort}')
sortedAscen = np.sort(toSort)
print(f' the ascending sorted arr is: \n{sortedAscen}')

sortedDescen = np.flip(sortedAscen)
print(f' the Descending sorted arr is: \n{sortedDescen}')