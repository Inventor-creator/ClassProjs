import pandas as pd
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt
from sklearn.preprocessing import MinMaxScaler, StandardScaler
from sklearn.cluster import KMeans
from sklearn.linear_model import LinearRegression

# Load dataset
df = pd.read_csv("large_dataset.csv")

def load_dataset():
    global df
    print("\nDataset loaded successfully!\n")

def show_head():
    print("\n--- First 5 Rows ---")
    print(df.head())

def show_info():
    print("\n--- Dataset Info ---")
    print(df.info())

def describe_data():
    print("\n--- Statistical Summary ---")
    print(df.describe())

def missing_values():
    print("\n--- Missing Values ---")
    print(df.isnull().sum())

def central_tendency():
    print("\n--- Measures of Central Tendency ---")
    print(df.mean(numeric_only=True))
    print("\n--- Median ---")
    print(df.median(numeric_only=True))
    print("\n--- Mode ---")
    print(df.mode(numeric_only=True).iloc[0])

def variability():
    print("\n--- Variability (Standard Deviation, Variance, Range) ---")
    print("Standard Deviation:\n", df.std(numeric_only=True))
    print("\nVariance:\n", df.var(numeric_only=True))
    print("\nRange:\n", df.max(numeric_only=True) - df.min(numeric_only=True))

def correlation_heatmap():
    plt.figure(figsize=(10, 6))
    sns.heatmap(df.corr(numeric_only=True), annot=True, cmap='coolwarm')
    plt.title("Correlation Heatmap")
    plt.show()

def scatter_plot():
    x = input("Enter column name for X-axis: ")
    y = input("Enter column name for Y-axis: ")
    if x in df.columns and y in df.columns:
        plt.scatter(df[x], df[y])
        plt.xlabel(x)
        plt.ylabel(y)
        plt.title(f"Scatter Plot between {x} and {y}")
        plt.show()
    else:
        print("Invalid column names!")

def simple_regression():
    x = input("Enter independent variable: ")
    y = input("Enter dependent variable: ")
    if x in df.columns and y in df.columns:
        X = df[[x]].values
        Y = df[y].values
        model = LinearRegression()
        model.fit(X, Y)
        plt.scatter(X, Y, color='blue')
        plt.plot(X, model.predict(X), color='red')
        plt.xlabel(x)
        plt.ylabel(y)
        plt.title("Simple Linear Regression")
        plt.show()
        print(f"Coefficient: {model.coef_[0]:.4f}")
        print(f"Intercept: {model.intercept_:.4f}")
    else:
        print("Invalid column names!")

def min_max_normalization():
    scaler = MinMaxScaler()
    df_scaled = pd.DataFrame(scaler.fit_transform(df.select_dtypes(include=np.number)),
                             columns=df.select_dtypes(include=np.number).columns)
    print("\n--- Min-Max Normalized Data ---")
    print(df_scaled.head())

def z_score_normalization():
    scaler = StandardScaler()
    df_scaled = pd.DataFrame(scaler.fit_transform(df.select_dtypes(include=np.number)),
                             columns=df.select_dtypes(include=np.number).columns)
    print("\n--- Z-Score Normalized Data ---")
    print(df_scaled.head())

def kmeans_discretization():
    n_clusters = int(input("Enter number of clusters: "))
    numeric_df = df.select_dtypes(include=np.number)
    kmeans = KMeans(n_clusters=n_clusters, random_state=42)
    df['Cluster'] = kmeans.fit_predict(numeric_df)
    print("\n--- K-Means Clustering Done ---")
    print(df['Cluster'].value_counts())

def histogram():
    col = input("Enter column name: ")
    if col in df.columns:
        plt.hist(df[col], bins=10, color='skyblue', edgecolor='black')
        plt.title(f"Histogram of {col}")
        plt.xlabel(col)
        plt.ylabel("Frequency")
        plt.show()
    else:
        print("Invalid column name!")

def box_plot():
    col = input("Enter column name: ")
    if col in df.columns:
        sns.boxplot(y=df[col])
        plt.title(f"Box Plot of {col}")
        plt.show()
    else:
        print("Invalid column name!")

def bar_plot():
    col = input("Enter column name: ")
    if col in df.columns:
        df[col].value_counts().plot(kind='bar', color='teal')
        plt.title(f"Bar Plot of {col}")
        plt.xlabel(col)
        plt.ylabel("Count")
        plt.show()
    else:
        print("Invalid column name!")

def pie_chart():
    col = input("Enter categorical column name: ")
    if col in df.columns:
        df[col].value_counts().plot(kind='pie', autopct='%1.1f%%')
        plt.title(f"Pie Chart of {col}")
        plt.ylabel("")
        plt.show()
    else:
        print("Invalid column name!")


# ================================
# MENU LOOP
# ================================
while True:
    print("\n" + "=" * 40)
    print("1. Load Dataset")
    print("2. Show Head")
    print("3. Show Info")
    print("4. Describe Data")
    print("5. Missing Values")
    print("6. Central Tendency")
    print("7. Variability")
    print("8. Correlation Heatmap")
    print("9. Scatter Plot")
    print("10. Simple Regression")
    print("11. Min-Max Normalization")
    print("12. Z-Score Normalization")
    print("13. K-Means Discretization")
    print("14. Histogram")
    print("15. Box Plot")
    print("16. Bar Plot")
    print("17. Pie Chart")
    print("18. Exit")
    print("=" * 40)
    
    choice = input("Enter your choice: ")

    if choice == '1': load_dataset()
    elif choice == '2': show_head()
    elif choice == '3': show_info()
    elif choice == '4': describe_data()
    elif choice == '5': missing_values()
    elif choice == '6': central_tendency()
    elif choice == '7': variability()
    elif choice == '8': correlation_heatmap()
    elif choice == '9': scatter_plot()
    elif choice == '10': simple_regression()
    elif choice == '11': min_max_normalization()
    elif choice == '12': z_score_normalization()
    elif choice == '13': kmeans_discretization()
    elif choice == '14': histogram()
    elif choice == '15': box_plot()
    elif choice == '16': bar_plot()
    elif choice == '17': pie_chart()
    elif choice == '18':
        print("Exiting program...")
        break
    else:
        print("Invalid choice! Please try again.")
