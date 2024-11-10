import numpy as np


names = np.array(['Alice', 'Bob', 'Charlie', 'David', 'Eva'])
marks = np.array([88, 72, 91, 65, 78])


print("Student Names:", names)
print("Mathematics Scores:", marks)


averageScore = np.mean(marks)
print("\nAverage Score in Mathematics:", averageScore)


condition = marks > 75
studentsAbove75 = names[condition]
scoresAbove75 = marks[condition]
print("\nStudents who scored above 75:")
for name, score in zip(studentsAbove75, scoresAbove75):
    print(f"{name}: {score}")


sortedIndices = np.argsort(-marks)
sortedNames = names[sortedIndices]
sortedScores = marks[sortedIndices]
print("\nSorted Scores in Descending Order:")
for name, score in zip(sortedNames, sortedScores):
    print(f"{name}: {score}")


highestScoreIndex = np.argmax(marks)
lowestScoreIndex = np.argmin(marks)
print("\nHighest Score:")
print(f"{names[highestScoreIndex]}: {marks[highestScoreIndex]}")
print("\nLowest Score:")
print(f"{names[lowestScoreIndex]}: {marks[lowestScoreIndex]}")
