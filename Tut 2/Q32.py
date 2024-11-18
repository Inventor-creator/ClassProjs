import matplotlib.pyplot as plt
import numpy as np

cats = ['cat1' ,'cat2', 'cat3', 'cat4' ,'cat5']
perce= [15, 25, 35, 10, 15]
plt.title("Percentages with their respective categories")
plt.pie(perce , labels=cats )


plt.show()
