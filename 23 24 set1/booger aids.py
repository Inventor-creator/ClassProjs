#WAP to sort all elements in dict depending on key values

testDict = {'a' : 1 ,'b' : 10 ,'c' : 4 ,'d' :7 ,'e' : 9}
vals = []
for i  in testDict.values():
    vals.append(i)

vals = sorted(vals)

newDict = {}

for i in vals:
    for j in testDict:
        if testDict[j] == i:
            newDict[j] = i


print(newDict)

binStr = '10010101010'

pattern = '010'

l = 0
r = len(pattern)

count = 0

while r < len(binStr) +1:
    
    if binStr[l:r] == pattern:
        count += 1
    r +=1
    l += 1

print(count)

testlst = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,29]
i = 0
primes = []
while i < len(testlst):
    flag = True
    for j in range(2,testlst[i]):
       
       if testlst[i] % j ==0:
           flag = False
           break
       else:
           continue
    if testlst[i] == 1:
        pass
    elif flag:
        primes.append(testlst[i])
           
        
    i += 1

print(primes)


matrix = [[4,5,6],
          [3,1,2]]
transMatix = []

for i in range(len(matrix[0])):
    temp = []
    #first column
    for j in range(len(matrix)):
        temp.append(matrix[j][i])


    transMatix.append(temp)
    




print(transMatix)



