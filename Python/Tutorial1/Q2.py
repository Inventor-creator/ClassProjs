import numpy as np


temps = np.random.randint(0,100,(7,24))
print(temps)

totalTemp = temps.sum(axis=1) / 24
print(totalTemp )

maxTemp = totalTemp.max()
minTemp = totalTemp.min()

days = ['sunday' , 'monday' , 'tuesday' , 'wednesday' , 'thursday' , 'friday' , 'saturday']

print(f'max temp is: {int(maxTemp)} and the day is: {days[totalTemp.argmax()]}')
print(f'min temp is: {int(minTemp)} and the day is: {days[totalTemp.argmin()]}')