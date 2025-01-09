import numpy as np
start = int(input('Start: '))
End = int(input('End: '))
Intervals = int(input('Intervals: '))
rows = int(input('Rows: '))
Cols = int(input('Cols: '))

list1 = []


list1 = np.linspace(start ,End ,Intervals)

try:
    np.reshape(lsit1 , (rows , Cols))
    print(list1)
except:
    print("enter valid values ")

