num1 = input("Enther the first number ")
num2 = input("Enther the second number ")

try:
    t = int(num1) / int(num2)
    print(t)
except ValueError:
    print('nums ki value theek nahi')
except ZeroDivisionError:
    print("Num2 zero mat daal")
except TypeError:
    print("numbers daal na")