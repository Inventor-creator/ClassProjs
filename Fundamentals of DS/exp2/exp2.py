import pandas as pd
import os

basedir = os.path.abspath(os.path.dirname(__file__))

filename = "pokemon.csv"
var =  os.path.join(basedir, filename)

df = pd.read_csv(var)

# Select relevant columns
columns = ['attack', 'speed', 'defense', 'sp_defense']

# Drop rows with missing values
data = df[columns].dropna()


for col in columns:
    print(col)
    col = sorted(data[col].tolist())
    length = len(col)
    summ = 0
    freq = {}
    for value in col:
        summ += value
        
        try:
            freq[value] += 1
        except:
            freq[value] = 1

    mean = summ / length

    if length % 2 == 0:
        median =( col[length // 2] + col[(length // 2) - 1]) / 2
    else:
        median = col[length // 2]
        
        pass

    
    maxFreq = max(freq.values())
    manual_modes = [k for k, v in freq.items() if v == maxFreq]

    print(f"mean: {mean} \n median: {median} \n mode: {manual_modes}" )
    variance = 0
    for value in col:
        
        variance += (value - mean) ** 2
    standardDev = (variance / length ) ** 0.5
    print(f"variance: {variance}")
    print(f"standard deviation: {standardDev}")


    q1Index = int(length * 0.25)
    q3Index = int(length * 0.75)


    if length * 0.25 % 1 == 0:
        q1 = (col[q1Index - 1] + col[q1Index]) / 2
    else:
        q1 = col[q1Index]

    if length * 0.75 % 1 == 0:
        q3 = (col[q3Index - 1] + col[q3Index]) / 2
    else:
        q3 = col[q3Index]


    iqrVal = [x for x in col if q1 <= x <= q3]
    iqrMean = sum(iqrVal) / len(iqrVal)

    iqrVar = sum((x - iqrMean) ** 2 for x in iqrVal) / len(iqrVal)

    print(f"IQR: {q3 - q1}")
    print(f"Interquartile Variance: {iqrVar}")
    print()


