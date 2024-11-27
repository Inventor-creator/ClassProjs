#1a

x = [23, 4, -6, 23,
-9, 21, 3, -45, -8]
positive = 0
negative = 0
zero = 0

for i in x:
    if i > 0: 
        positive += 1
    elif i < 0:
        negative += 1
    elif i == 0 :
        zero += 1

print(f'Positive: {positive}')    
print(f'Negative: {negative}')    
print(f'Zero: {zero}')    

#1b
inpStr = '''The little bird flew across the blue sky and landed on the soft green grass.'''

words = inpStr.strip()
words = words.replace('.' , '')
words = words.split(' ')



vovels = 'aeiou'
wordLst = []

for word in words:
    if len(word) == 3 or len(word) == 4:
        if word[-1] in vovels:
            
            wordLst.append(word)
            continue

print(wordLst)               

#2 a galat hai idk outpuy kya likha hai

newList = []

test_tuple1 = (4,5,6)
test_tuple2 = (7,8)

for i in test_tuple1:
    for j in test_tuple1:
        if i == j: 
            continue
        newList.append((i,j))
    for j in test_tuple2:

        newList.append((i,j))
    
for i in test_tuple2:
    for j in test_tuple2:
        if i == j: 
            continue
        newList.append((i,j))
    for j in test_tuple1:

        newList.append((i,j))

print(list(set(newList)))

#2 b
lst_1 = [1,6,7,10]
lst_2 = [13,17,18,32]

#1 
print(list(filter(lambda x:x in lst_2 , lst_1)))
#2

print(list(filter(lambda x:x not in lst_2  , lst_1)))
#3
print(list(filter(lambda x:x not in lst_1 , lst_2)))
#4

for i in lst_2:
    if i not in lst_1:
        lst_1.append(i)
print(lst_1)
