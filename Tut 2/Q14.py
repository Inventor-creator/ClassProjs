import numpy as np 
import matplotlib.pyplot as plt

flavFreq = [44 ,76,30 ,78  ,39 ,11 ,22]
flavs = ['Strawberry', 'Vanilla', 'Chocolate' ,'Butterscotch', 'Raspberry', 'Mint', 'Blueberry' ]

plt.title("Childrens favourite icecream flavours")
plt.pie(flavFreq)
plt.legend(flavs)

plt.show()