secs = int(input("enter num of seconds "))

mins = int(secs /60)
hours = int(mins / 60)

newSecs = int(secs % 60)
newmins = int(mins % 60)


print(f'The time in HH:MM:SS is {hours}:{newmins}:{newSecs}')
i = 0
while i <= 9:
    digit3Num = input("enter your number ")
    if len(digit3Num) != 3:
        print("Enter a Valid 3 digit number")

        continue
    
    try:
        print(int(digit3Num[1]) ** 2)
    except:
        print("enter a valid num")
        continue
    
    i += 1

List = []

while True:
    inp = input("enter the thing you want to append, enter a blank space to end. ")
    if inp.strip() == '':
        break

    List.append(inp)
    



print(list(set(List)))
    
list1 = [131, 666, 99, 113, 161, 18, 21]
list2 = [4, 818, 12, 21, 23, 242, 282]
newLst = list1 + list2
palin = []
for i in newLst:
    j = int(str(i)[::-1])
    if i == j:
        palin.append(i)
    
print(palin)



