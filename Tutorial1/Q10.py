#Q 10
import numpy as np

values = np.arange(0 , 2 * np.pi ,0.1 )
print('the initial arrays containing the angles for the sine and cosine array are:' , values)

sine = np.sin(values)
print('the sine values are:' , sine)

cosine = np.cos(values)
print('the cosine values are:' , cosine)