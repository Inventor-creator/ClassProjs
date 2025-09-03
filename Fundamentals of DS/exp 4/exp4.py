import numpy as np
import pandas as pd
import os
import matplotlib.pyplot as plt

basedir = os.path.abspath(os.path.dirname(__file__))

filename = "all-vehicles-model@public.csv"
var =  os.path.join(basedir, filename)

df = pd.read_csv(var , sep=";")

features = ["Cylinders", "Engine displacement", "Drive", "Transmission", "Vehicle Size Class", "Year"]
target = "Combined Mpg For Fuel Type1"


data = df.replace(-1, np.nan)
data = data.dropna(subset=[target] + features)


category_maps = {}
for col in ["Drive", "Transmission", "Vehicle Size Class"]:
    data[col] = data[col].astype("category")
    category_maps[col] = list(data[col].cat.categories)
    data[col] = data[col].cat.codes


X = data[features].values.astype(float)
Y = data[target].values.astype(float)


X_mean, X_std = X.mean(axis=0), X.std(axis=0)
X_norm = (X - X_mean) / (X_std + 1e-8)


X_b = np.c_[np.ones((X_norm.shape[0], 1)), X_norm]


b = np.linalg.pinv(X_b).dot(Y)


disp_index = features.index("Engine displacement")  


fixed_features = X_mean.copy()


disp_range = np.linspace(X[:, disp_index].min(), X[:, disp_index].max(), 100)

preds = []
for d in disp_range:
    x_temp = fixed_features.copy()
    x_temp[disp_index] = d
    x_scaled = (x_temp - X_mean) / (X_std + 1e-8)
    x_input = np.r_[1, x_scaled]
    preds.append(x_input.dot(b))



disp_index = features.index("Engine displacement")  


fixed_features = X_mean.copy()


disp_range = np.linspace(X[:, disp_index].min(), X[:, disp_index].max(), 100)

preds = []
for d in disp_range:
    x_temp = fixed_features.copy()
    x_temp[disp_index] = d
    x_scaled = (x_temp - X_mean) / (X_std + 1e-8)
    x_input = np.r_[1, x_scaled]
    preds.append(x_input.dot(b))


plt.figure(figsize=(8,6))
plt.scatter(X[:, disp_index], Y, alpha=0.5, label="Actual data", edgecolor="k")
plt.plot(disp_range, preds, "r-", lw=2, label="Best fit line")
plt.xlabel("Engine Displacement (liters)")
plt.ylabel("Combined MPG")
plt.title("Best Fit Line: Engine Displacement vs MPG")
plt.legend()
plt.grid(True)
plt.show()

def predict_engine(cylinders, displacement, drive, transmission, vehicle_size, year):
    
    try:
        drive_code = category_maps["Drive"].index(drive)
        trans_code = category_maps["Transmission"].index(transmission)
        size_code = category_maps["Vehicle Size Class"].index(vehicle_size)
    except ValueError as e:
        raise ValueError(f"Invalid input: {e}")
    
    
    x_raw = np.array([cylinders, displacement, drive_code, trans_code, size_code, year], dtype=float)
    x_scaled = (x_raw - X_mean) / (X_std + 1e-8)
    
    x_new = np.r_[1, x_scaled]  
    mpg = x_new.dot(b)
    gallons_per_mile = 1 / mpg if mpg > 0 else None
    return mpg, gallons_per_mile

mpg, gpm = predict_engine(
    cylinders=6,
    displacement=3.5,
    drive="Rear-Wheel Drive",
    transmission="Automatic 7-spd",
    vehicle_size="Subcompact Cars",
    year=2011
)

print(f"Predicted Combined MPG: {mpg:.2f}")
print(f"Fuel consumption (gallons per mile): {gpm:.4f}")

