from os import PRIO_DARWIN_BG
import subprocess
from types import LambdaType
import numpy as np
import matplotlib.pyplot as plt
from numpy._typing import NDArray

#modified for exp1 quick sort
c_program_path = "./a.out"

nForExecution = [25,50,75,100]
stepsRequired = []
numWorstCase = []
print("worst case:")
for i in nForExecution:
    numWorstCase.append(i * i)

for i in nForExecution:
    numberOfElements = i

    input_data = f"{numberOfElements}\n"

    sortedStraight = np.sort(np.random.randint(1,10 , size=i))[::-1]

    for j in sortedStraight:
        input_data+=f"{j}\n"

    process = subprocess.run(
        c_program_path,
        input=input_data,
        text=True,
        capture_output=True
    )

    # sortedArr = map(lambda x: int(x) , process.stdout.split())

    steps = int(process.stdout)
    stepsRequired.append(steps)
    print(f"steps for {i}: " + str(steps))



plt.plot(nForExecution , stepsRequired)
plt.plot(nForExecution , numWorstCase)
plt.legend(["Actual Steps", "Theoretical Worst Case"])
plt.title("Worst Case")
plt.xlabel("Num of Elements")
plt.ylabel("Required Steps")
plt.show()

print("best case:")
stepsRequired = []
numBestCase = []

#QuickSort
for i in nForExecution:
    numBestCase.append(i)

for i in nForExecution:
    numberOfElements = i

    input_data = f"{numberOfElements}\n"

    sortedStraight = np.sort(np.random.randint(1,10 , size=i))

    for j in sortedStraight:
        input_data+=f"{j}\n"


    process = subprocess.run(
        c_program_path,
        input=input_data,
        text=True,
        capture_output=True
    )

    # sortedArr = map(lambda x: int(x) , process.stdout.split())

    steps = int(process.stdout)
    stepsRequired.append(steps)
    print(f"steps for {i}: " + str(steps))



plt.plot(nForExecution , stepsRequired)
plt.plot(nForExecution , numBestCase)
plt.title("Best Case")
plt.legend(["Actual Steps", "Theoretical Best Case"])
plt.xlabel("Number of Elements")
plt.ylabel("Steps Required")
plt.show()
