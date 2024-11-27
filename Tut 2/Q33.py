import matplotlib.pyplot as plt
import numpy as np


x = np.linspace(-10, 10, 400)  
y = x**2

plt.plot(x, y)

plt.xlabel('X Values')
plt.ylabel('Y Values')
plt.title('Line Plot of y = x^2')
plt.grid()



plt.legend()


plt.show()