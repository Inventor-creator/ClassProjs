#1 a 

inpBin = 101
inpBin = str(inpBin)

baseVal = len(inpBin)
exp = 0
Sum = 0

for i in inpBin:
    Sum += int(i) *( baseVal ** exp )
    exp += 1

print(Sum)

#1 b

def pass_checker(passw):
    letters = 'abcdefghijklmnopqrstuvwxyz'
    Upperletter = False
    lowerletter = False
    nums ='1234567890'
    num = False
    specialz = '!@#$%^&*()'
    specials = False
    if len(passw) < 12:
        return 'weak password'
    for i in passw:
        if i in letters:
            lowerletter = True
        elif i in letters.upper():
            Upperletter = True
        elif i in nums:
            num = True
        elif i in specialz :
            specials = True
    
    if Upperletter and lowerletter and num and specials:
        return 'Strong password'
    
    return 'weak password'

print(pass_checker('!$d3Itagamm@^'))

#2 a 

test_list = [(4, ), (5, 6), (2,
3, 5), (5, 6, 8, 2), (5, 9)]
i = 5
j = 6

newlist = list(filter(lambda x: len(x) >= i and len(x) <= j , test_list))
print(newlist)

#2 b wrong kaise aa rha hai bhai bruh

def fibo(inp):
    if inp < 0: 
        return 'Invalid Input'
    elif inp == 0 or inp == 1:
        return 0
    elif inp == 2:
        return 1    
    
    fiboNums = {1:0,
                2:1,}
    
    for i in range(3, inp + 1):
  
        fiboNums[i] = fiboNums[i - 1] + fiboNums[i - 2]        

    return fiboNums[inp]

print(fibo(100))

