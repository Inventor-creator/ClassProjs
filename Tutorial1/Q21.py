import numpy as np

array1 = np.array([5, 10, 15, 20, 25])

print("Array from list:", array1)

array2 = np.arange(10)

print("Array using arange():", array2)


array3 = np.random.randint(1, 10, (5,2))

print("Array using np.random.randint:", array3)


array4 = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])

print("2D Array:", array4)




meanValue = np.mean(array1)

print("Mean of array1:", meanValue)


medianValue = np.median(array1)

print("Median of array1:", medianValue)


std_dev = np.std(array1)

print("Standard deviation of array1:", std_dev)



sumValue = np.sum(array4)

print("Sum of elements in 2D array:", sumValue)


minValue = np.min(array1)

maxValue = np.max(array1)


print("Min value:", minValue, "Max value:", maxValue)

reshapedArray = array1.reshape(1, 5)

print("Reshaped array (1 row, 5 columns):", reshapedArray)


reshapedArray2 = array2.reshape(2, 5)

print("Reshaped array2 (2 rows, 5 columns):", reshapedArray2)


filteredArray = array1[array1 > 10]

print("Filtered array (elements > 10):", filteredArray)


evenNumbers = array2[array2 % 2 == 0]

print("Even numbers in array2:", evenNumbers)

addResult = array1 + array2[:5]  

print("Array1 + Array2:", addResult)


subResult = array1 - array2[:5]

print("Array1 - Array2:", subResult)

mulResult = array1 * array2[:5]

print("Array1 * Array2:", mulResult)


divResult = array1 / (array2[:5] + 1)  

print("Array1 / Array2:", divResult)


dotProduct = np.dot(array4, array4.T)  

print("Dot product of array4 with its transpose:\n", dotProduct)


transposeArray = array4.T

print("Transpose of array4:\n", transposeArray)



broadcastResult = array1 + 5

print("Broadcasting addition (array1 + some scalar):", broadcastResult)
