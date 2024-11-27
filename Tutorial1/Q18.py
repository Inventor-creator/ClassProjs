import numpy as np


sample1 = np.array([2,4,6,8,10])
sample2 = np.array([1,3,5,7,9])

added = sample1 + sample2
difference = sample1 - sample2

print('the added array is: ', added)
print('the diffrence of array is: ', difference)

completeArr = np.append(sample1 , sample2)

print('the elements between 4 and 9 are: ', completeArr[ (completeArr > 4) & (completeArr< 9) ])

