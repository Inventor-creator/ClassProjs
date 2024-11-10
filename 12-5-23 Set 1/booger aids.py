#1 a 

inpTuple = (10, 20, 30, 40, 50, 60, 70, 80,
90, 100)



def swapper(oldTup,index):
    a = oldTup[index]
    oldTup[index] = oldTup[index + 1]
    oldTup[index + 1] = a

    return oldTup

inpList = list(inpTuple)

for i in range(len(inpList)):

    if i % 2 == 0:
        swapper(inpList , i )
    else:
        continue

print('tuple w/ swapped stuff is: ' ,tuple(inpList))

# 1 b

inpStr = '''Technical
Education
Regional Office,
World Bank
Project Building,
Govt. Polytechnic
Campus,
49-Kherwadi,
Aliyawar Jung
Marg,
Bandra(East),
Mumbai - 400051 '''

pincode = ''
numbers = '1234567890'

for i in inpStr:
    if i in numbers:
        pincode += i
    elif len(pincode) == 6 :
        break
    else:
        pincode = ''

print('the pincode is ' , pincode)

#2 a



test_list = [(5, 6), (5, 7),
(5, 8), (6, 10), (7, 13)]
newList = []
temp = 0
tempDict = {}

for i in test_list:

    if i[0] not in tempDict:
        tempDict[i[0]] = [i[0],i[1]]
    
    else:
        for j in i[1:]:
            tempDict[i[0]].append(j)
        

for i in tempDict:
    newList.append(tuple(tempDict[i]))
print(newList)

#2 b

def find_average( *nums,rounded = False ):
    sum = 0
    print(nums)
    for i in nums:
        sum += float(i)
        print(sum)
    
    average = sum / len(nums)


    if rounded:
        roundedNum =  average + (1 - (average - int(average)))
        return roundedNum
    
    return average


    

print(find_average(2,3,4,5,rounded=True))
    