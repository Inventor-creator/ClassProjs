import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import os

def getSpeedMeanByType():
    means = {}
    for type in df["type1"].unique().tolist():
        totalSpeed = 0
        
        temp = df[df[ "type1"] == type]["speed"].tolist() + df[df[ "type2"] == type]["speed"].tolist() 

        length = len(temp)
        for i in temp:
            totalSpeed += i
        means[type] = totalSpeed / length
    
    df2 = pd.DataFrame(means , index= [0])
    df2.to_excel("pokemon.xlsx" , sheet_name="meansByType")




basedir = os.path.abspath(os.path.dirname(__file__))

filename = "pokemon.csv"
var =  os.path.join(basedir, filename)

df = pd.read_csv(var)

# print("original dataset: ")
# print(df)

df.dropna()

df = df.drop(columns=["classfication" , "weight_kg" , "japanese_name" , "wha abilities" ] )

# print(df[df['is_legendary'] == 1 ])

# plt.bar(x = df['type1'].tolist() , height =df["speed"].tolist() )

# print(df[df['speed'] == df["speed"].max()][["name" , "speed"]])
# toPlotType = "water"

# print(df2)
getSpeedMeanByType()

# plt.scatter( x = df[df["type1"] == toPlotType]['speed'].tolist() + df[df["type1"] == toPlotType]["speed"].tolist(), y = df[df["type1"] == toPlotType]['speed'].tolist() + df[df["type1"] == toPlotType]["speed"].tolist() )
# plt.axhline( means[toPlotType] )

# print(totalSpeed  / df[df["type1" == "ice" or "type2" == "flying"]].count() )

# plt.show()

# print(df)
