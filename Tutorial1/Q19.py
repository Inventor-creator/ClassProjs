import numpy as np

arr1 = np.random.randint(1,10,(3,3))
arr2 = np.random.randint(1,10,(3,3))
print(arr1)
print(arr2)

print(f'element wise addition: \n{arr1 + arr2}')
print(f'element wise substraction: \n{arr1 - arr2}')
print(f'element wise multiplication: \n{arr1 * arr2}')
print(f'element wise division:\n {arr1 - arr2}')