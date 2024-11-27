star = '*'

n = int(input())

# first line

print(star * n )

# lines
for i in range(n-2):
        
    print(star, end='')
    print(' ' * (n-2) , end='')
    print(star)

#last line
print(star * n )

inp = list(input().split(' '))

even = []
odd = []

for i in inp:
    if int(i) % 2 == 0:
        even.append(int(i))
    else:
        odd.append(int(i))

print(sorted(even) + sorted (odd))

# solved 3rd qn 



def exam(L):
    marks = 0
    temp = []
    for i in range(len(L)):
        if L[i] == correctAns[i]:
            marks +=1
        else:
            marks -=0.5
            temp.append(i +1)
    return temp , marks



L = ['a','b','c','d',"a",'d','c','a','a','b']
correctAns = ['a','b' , 'c' , 'c' ,'d' ,'c' ,'d' ,'c' ,'a' ,'b' ]

wrongQ , marks = exam(L)

print(f'wrong questions are: {wrongQ} and the marks are {marks}')
