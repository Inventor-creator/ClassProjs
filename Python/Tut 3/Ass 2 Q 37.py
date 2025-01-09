def calculateStats():
    
    userInp = input("Enter a list of numbers separated by spaces: ")
    numList = list(map(float, userInp.split()))

   
    mean = sum(numList) / len(numList)

    numList_sorted = sorted(numList)
    n = len(numList_sorted)
    if n % 2 == 1:
        median = numList_sorted[n // 2]
    else:
        median = (numList_sorted[n // 2 - 1] + numList_sorted[n // 2]) / 2

    #
    frequency = {}
    for num in numList:
        if num in frequency:
            frequency[num] += 1
        else:
            frequency[num] = 1

    
    max_freq = max(frequency.values())
    modes = [key for key, value in frequency.items() 
             if value == max_freq]


    if len(modes) == len(numList):
        mode = "No mode"
    elif len(modes) > 1:
        mode = modes  
    else:
        mode = modes[0]  

 
    print(f"Mean is: {mean}")
    print(f"Median is: {median}")
    print(f"Mode is: {mode}")


calculateStats()
