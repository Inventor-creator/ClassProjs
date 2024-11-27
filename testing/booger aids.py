import numpy as np
import matplotlib.pyplot as plt

#WAP numbers string -> total no digits even: 1st digit last and others come back vice versa for odd

numberstr = '1234567890'
newstr = ''

# if len(numberstr) % 2 == 0:
#     newstr += numberstr[1:] + numberstr[0]
# else:
#     newstr += numberstr[-1] + numberstr[0 : len(numberstr) - 1]

# print(newstr)


# swap even and odd indices

# if len(numberstr)  % 2 != 0:
#     reversedStr = numberstr[-2::-1]
#     lastdigit = numberstr[-1] 
    
#     for i in range(len(numberstr)):
#         if i % 2 != 0:
#             newstr += numberstr[i]
#             newstr += numberstr[i -1]
#     newstr += lastdigit
# else:
#     reversedStr = numberstr[::-1]
#     for i in range(len(numberstr)):
#         if i % 2 != 0:
#             newstr += numberstr[i]
#             newstr += numberstr[i -1]

# print(newstr)

# inpInt = []



# while True:
#     inp = (input("enter a num: "))
#     if inp == '':
#         break
#     try:
#         inp = int(inp)
#         assert inp > 0 and inp < 100
#     except ValueError:
#         print('enter a valid int')
#         continue
#     except AssertionError:
#         print("enter a valid num between 1 and 100")
#         continue
#     inpInt.append(inp)

# summ = 0
# count = 0

# with open('nigga.txt' , 'w') as f:
    
#     for i in inpInt:
#         f.write(f'{i}\n')
#         summ += i 
#         count += 1

# avg = summ / count

# with open('example.bin', 'wb') as file:
#     file.write(f'{summ}\n'.encode('utf-8'))
#     file.write(f'{avg}\n'.encode('utf-8'))


num = -10

try:
    if num < 0:
        raise NegativeValueError
except :
    print('NegativeValueError')
else:
    print(num ** 0.5)
