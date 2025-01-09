nums = [2,3,4,5,6,7,8,9]
evenNums = []
for i in nums:
    if i % 2 == 0:
        evenNums.append(i)
    else:
        continue

print(f'The even nums are: {evenNums}')