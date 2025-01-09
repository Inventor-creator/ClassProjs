string = "EXAM"
i = 0
while i <= len(string):

    print(string[:i])

    i += 1

i = -1

while -i <= len(string):
    
    print(string[:i])
    i -= 1

popu = 1100000

for i in range(10):
    popu = popu / 1.1
    print(popu) 

inp = input("enter an integer ")

try:
        inp = float(inp)
except:
    print("enter a valid number")

evenNums = 0
oddNums = 0

for i in str(inp):
    if i == '.':
        continue

    if int(i) % 2 == 0:
        evenNums += 1
    else:
        oddNums += 1

print( evenNums , oddNums)


def ispriime(x):
    
    if x == 2:
        return True
    elif x == 1:
        return False
    for i in range(3,x):
        
        if x % i == 0:
            return False          
    return True

def primefactors(n):
    factors = []
    primeFactors = []

    for i in range(1,n):
        if n % i == 0:
            
            factors.append(i)
    
    for j in factors:
        if ispriime(j):
            primeFactors.append(j)
    return primeFactors



print(primefactors(int(input("enter the number you want to check "))))