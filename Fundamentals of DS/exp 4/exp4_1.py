import numpy as np
import pandas as pd
import os
import matplotlib.pyplot as plt

basedir = os.path.abspath(os.path.dirname(__file__))

filename = "all-vehicles-model@public.csv"
var =  os.path.join(basedir, filename)

data = pd.read_csv(var , sep=";")


X = data["Cylinders"].values
Y = data["Engine displacement"].values


mask = ~np.isnan(X) & ~np.isnan(Y)
X = X[mask]
Y = Y[mask]


X = X.reshape(-1, 1)
X_b = np.c_[np.ones((X.shape[0], 1)), X]  


b = np.linalg.pinv(X_b).dot(Y)

print("Regression equation: Displacement = {:.4f} + {:.4f} * Cylinders".format(b[0], b[1]))


def predict_displacement(cylinders):
    return b[0] + b[1] * cylinders


Y_pred = X_b.dot(b)


ss_res = np.sum((Y - Y_pred) ** 2)
ss_tot = np.sum((Y - np.mean(Y)) ** 2)
r2 = 1 - (ss_res / ss_tot)
rmse = np.sqrt(np.mean((Y - Y_pred) ** 2))

print(f"Model R²: {r2:.4f}")
print(f"Model RMSE: {rmse:.4f} liters")


plt.figure(figsize=(8,6))
plt.scatter(X, Y, alpha=0.6, label="Data points", edgecolor="k")
plt.plot(X, Y_pred, "r-", lw=2, label="Best fit line")
plt.xlabel("Number of Cylinders")
plt.ylabel("Engine Displacement (liters)")
plt.title("Cylinders vs Engine Displacement with Best Fit Line")
plt.legend()
plt.grid(True)
plt.show()


example_cylinders = 4
predicted_value = predict_displacement(example_cylinders)
print(f"Predicted engine displacement for {example_cylinders} cylinders: {predicted_value:.2f} liters")
