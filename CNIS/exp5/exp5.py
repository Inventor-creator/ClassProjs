import math


def isPrime(n):
    if n <= 1:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True



def findPrimRoots(p):
    primitive_roots = []
    required_set = set(num for num in range(1, p) if math.gcd(num, p) == 1)

    for g in range(1, p):
        actual_set = set(pow(g, powers, p) for powers in range(1, p))
        if required_set == actual_set:
            primitive_roots.append(g)

    return primitive_roots



p = int(input("Enter a prime number: "))

if not isPrime(p):
    print("The number entered is not prime.")
    exit()


roots = findPrimRoots(p)

print("\nPrimitive Roots of", p, "are:")
print(roots)


g = int(input("\nSelect one primitive root from the above list: "))

if g not in roots:
    print("Invalid primitive root selected.")
    exit()


a = int(input("Enter private key for Party A: "))
b = int(input("Enter private key for Party B: "))


public_A = pow(g, a, p)
public_B = pow(g, b, p)

print("\nPublic Key of Party A:", public_A)
print("Public Key of Party B:", public_B)


key_A = pow(public_B, a, p)
key_B = pow(public_A, b, p)

print("\nShared Key computed by Party A:", key_A)
print("Shared Key computed by Party B:", key_B)

if key_A == key_B:
    print("\nKey Exchange Successful! Communication Key:", key_A)
else:
    print("\nKey Exchange Failed!")
