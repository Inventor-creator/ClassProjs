import numpy as np 
import matplotlib.pyplot as plt


temps = np.random.randint(0,100,(7,24))
print(temps)

AvgTemp = temps.sum(axis=1) / 24
print(AvgTemp )

maxTemp = AvgTemp.max()
minTemp = AvgTemp.min()

days = ['sunday' , 'monday' , 'tuesday' , 'wednesday' , 'thursday' , 'friday' , 'saturday']

print(f'max temp is: {int(maxTemp)} and the day is: {days[AvgTemp.argmax()]}')
print(f'min temp is: {int(minTemp)} and the day is: {days[AvgTemp.argmin()]}')

# from here for tut 2
plt.subplot(2,2,1)
plt.title('the average temps for all the days')
plt.plot(days , AvgTemp)
plt.grid()

plt.subplot(2,2,2)
plt.title("Histogram for frequency of temps " )
plt.hist(temps)

lowmidhigh = [0,0,0]

for i in temps:
    for j in i:
        if j < 22:
            lowmidhigh[0] += 1
        elif j > 22 and j < 40:
            lowmidhigh[1] += 1
        else:
            lowmidhigh[2] += 1

labels = ['Low Temps', 'Mid Temps' , 'High temps']

plt.subplot(2,2,3)
plt.title("the Temps in ranges")
plt.pie(lowmidhigh)
plt.legend(labels)

plt.show()
