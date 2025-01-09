import numpy as np

ages = np.array([18, 22, 21, 19, 22, 24, 20, 25, 30, 32, 21, 20, 18, 19, 23]) 

filtered_ages = ages[ages > 20 ]
filtered_ages = filtered_ages[filtered_ages  < 30]

print('the mean of the filtered ages is: ', np.mean(filtered_ages))
print('the standard deviation of the filtered ages is: ', np.std(filtered_ages))

adjusted_ages = ages - np.mean(filtered_ages)
print('the adjusted array of ages is: ', adjusted_ages)

negativeAges = np.argwhere(ages < np.mean(filtered_ages)).T


print('the ages ka indices that are below the mean of filtered group are as follows:\n' , negativeAges)