# vovels = 'aeiou'
# inpStr = input().lower()

# newStr = ''
# alphabetical = 'abcdefghijklmnopqrstuvwxyz'
# for i in inpStr:
#     if i not in vovels:
#         newStr += i

# temp = []
# for i in newStr:
#     t = alphabetical.find(i)
#     temp.append(t)

# temp.sort()
# newlst = []

# for i in temp:
#     newlst.append(alphabetical[i])
# print(newlst)


# inplst = []
# while True:
#     inp = input("Enther the str , enter empty to break: ")
#     if inp.strip() == '':
#         break
#     inplst.append(inp.strip())

# newlst = []
# for i in inplst:
#     if i != i [::-1]:
#         newlst.append(i)

# print(newlst)

# def converter(str):
#     temp = ''
#     numbers = '1234567890'
#     for i in str:
#         if i not in numbers:
#             temp += i
#     return temp

# inp1 = converter(input('Enther String 1 '))
# inp2 = converter(input('enter string2 '))

# print((inp1 + inp2).upper())
        
# inpsent = input().split(' ')
# i = len(inpsent) -1
# new = ''
# while i >= 0:
    
    
#     new += f'{inpsent[i]} '

#     i -= 1

# print(new)


# sampleDict = {'a': 3, 'b': 4, 'c': 10, 'd': 5, 'e': 12, 'f': 100}
# newdict = {}
# for i in sampleDict:
#     if sampleDict[i] % 2 == 0:
#         newdict[i] = sampleDict[i]
# print(newdict)


# sampleList =['abc', 'xyz', 'aba', '1221']

# newList = list(filter(lambda x : x[0] == x[-1] , sampleList))
# print(len(newList))


# sampleList = [12, 7, 15, 22, 10, 6,20]
# newList = list(filter(lambda x : x > 10 and x % 2 ==0 , sampleList))
# print(len(newList))




start = '''
********************BILL********************
Item Name \t Item Quantity \t Item Price \n'''

add = '''
********************************************
Total Amount to be paid
******************************************** '''
temp2 = []
while True:
    
    inp = input('enter stuff: [item name , item quality , item price]')
    if inp.strip() == '':
        break
    inp2 = list(inp.split(' '))
    temp2.append(inp2)
    

with open("nashe.txt" , 'w') as f:
    f.write(start)
    total = 0
    for i in temp2:
        f.write(f'{i[0]}\t\t\t{i[1]}\t\t\t{i[2]} \n')
        total += int(i[2])
    
    f.write(f'''********************************************
Total Amount to be paid {total}
******************************************** ''')
            












