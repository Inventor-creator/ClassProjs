import numpy as np

students = 4

subs = ['Mathematics' , 'Science' , 'English']

marks = np.random.randint(50, 100 ,(students , len(subs)))

dict = {}

student = 1

for i in marks:
    k = 0
    temp = {}

    for j in i.tolist():
        temp[subs[k]] = j
        k += 1

    dict[f'student {student}'] = temp
    student += 1
    

print('the complete dataset is : ',dict)