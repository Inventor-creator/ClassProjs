import matplotlib.pyplot as plt
import numpy as np

temps = np.random.randint(30 , 45 , (5,92))
days = np.arange(1,93 , 1)

for idx , i in enumerate(temps):

    plt.subplot(3,2, idx + 1)
    plt.xlabel("days")
    plt.ylabel("Temperature")
    plt.title(f'Bar chart of year {idx + 1}')

    plt.bar( days ,i )

plt.show()