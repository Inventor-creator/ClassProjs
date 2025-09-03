import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import os , math

basedir = os.path.abspath(os.path.dirname(__file__))

filename = "all-vehicles-model@public.csv"
var =  os.path.join(basedir, filename)

df = pd.read_csv(var , sep=";")
df = df[:750]


def correlation(x, y):
    n = len(x)
    meanX = sum(x) / n
    meanY = sum(y) / n
    
    numerator = 0
    denominatorX = 0
    denominatorY = 0
    
    for i in range(n):
        dx = x[i] - meanX
        dy = y[i] - meanY
        numerator += dx * dy
        denominatorX += dx ** 2
        denominatorY += dy ** 2
    
    return numerator / ((denominatorX * denominatorY) ** 0.5)


def bestFit(x, y):
    n = len(x)
    meanX = sum(x) / n
    meanY = sum(y) / n
    
    numerator = sum((x[i] - meanX) * (y[i] - meanY) for i in range(n))
    denominator = sum((x[i] - meanX) ** 2 for i in range(n))
    
    b = numerator / denominator   
    a = meanY - b * meanX          
    return a, b


df = df.dropna(subset=["Engine displacement", "Cylinders", "Combined Mpg For Fuel Type1", "City Mpg For Fuel Type1", "Year"])


x1, y1 = df["Engine displacement"].tolist(), df["Cylinders"].tolist()
x2, y2 = df["Engine displacement"].tolist(), df["Combined Mpg For Fuel Type1"].tolist()
x3, y3 = df["Year"].tolist(), df["City Mpg For Fuel Type1"].tolist()


r1 = correlation(x1, y1)
r2 = correlation(x2, y2)
r3 = correlation(x3, y3)

print("Positive correlation (Engine displacement vs Cylinders):", round(r1, 3))
print("Negative correlation (Engine displacement vs Combined MPG):", round(r2, 3))
print("No correlation (Year vs City MPG):", round(r3, 3))

plt.figure(figsize=(12,4))


plt.subplot(1,3,1)
plt.scatter(x1, y1, color="green")
a, b = bestFit(x1, y1)
xLine = sorted(x1)
yLine = [a + b * xi for xi in xLine]
plt.plot(xLine, yLine, color="black")
plt.title("Positive Correlation")
plt.xlabel("Engine displacement")
plt.ylabel("Cylinders")


plt.subplot(1,3,2)
plt.scatter(x2, y2, color="red")
a, b = bestFit(x2, y2)
xLine = sorted(x2)
yLine = [a + b * xi for xi in xLine]
plt.plot(xLine, yLine, color="black")
plt.title("Negative Correlation")
plt.xlabel("Engine displacement")
plt.ylabel("Combined MPG")


plt.subplot(1,3,3)
plt.scatter(x3, y3, color="blue")
a, b = bestFit(x3, y3)
xLine = sorted(x3)
yLine = [a + b * xi for xi in xLine]
plt.plot(xLine, yLine, color="white")
plt.title("No Correlation")
plt.xlabel("Year")
plt.ylabel("City MPG")

plt.tight_layout()
plt.show()
