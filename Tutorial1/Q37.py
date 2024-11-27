import numpy as np

arr = np.array([(4,6,5),
                  (7,9,8),
                  (12,11,10)])


sortedArr = np.sort(arr , axis=1)

columnSum = np.sum(sortedArr , axis=0)

print('the sorted row array is:\n',sortedArr)
print('column wise sum is: ' , columnSum)
