import matplotlib.pyplot as plt
import numpy as np

study_hours = [2, 3, 4.5, 1, 6, 7.5, 8, 5, 9, 2.5, 3.5, 7, 6.5, 4, 8.5] 
exam_scores = [55, 60, 65, 50, 75, 85, 90, 70, 95, 58, 63, 88, 80, 68, 92]

plt.subplot(1,2,1)
plt.scatter(study_hours , exam_scores)
plt.xlabel("Student Study Hours")
plt.ylabel("Student Exam Scores")

avgTrendlineX = [np.min(study_hours) , np.max(study_hours)]
avgTrendlineY = [np.min(exam_scores) , np.max(exam_scores)]


plt.plot(avgTrendlineX,avgTrendlineY , color='red')

plt.subplot(1,2,2)
plt.title("The distribution of exam scores" )
plt.hist(exam_scores, edgecolor = 'black')

plt.show()