import numpy as np

x = np.arange(1,200 ,7)
y = np.arange(100,200 ,3)

sumx = 0
lenx = len(x)
leny = len(y)
sumy = 0 

for i in x:
    sumx += i
meanx = sumx / lenx
for i in y:
    sumy += i
meany = sumy / leny

sumSquareX = 0
sumSquareY = 0
for i in x:
    sumSquareX += (i - meanx) ** 2
for i in y:
    sumSquareY += (i - meany) ** 2
sumSquareX = sumSquareX **2
sumSquareY = sumSquareY **2
demnominator = (sumSquareX * sumSquareY) ** 0.5

numerator = 0
try:
    for i in range(len(x)):
        numerator += ((x[i] - meanx) * (y[i] - meany))
except:
    pass

print("correlation coefficient: " , (numerator / demnominator))
