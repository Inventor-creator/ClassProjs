# list1 = [1,2,3,4,5]
# list2 =[5,6,7,8,9]
# count = 0
# for i in list1:
#     if count == 3:
#         print(True)
#         break
#     if i in list2:
#         count +=1
    
# if count < 3:
#     print(False)



# def encript(sentence , shift):
#     newsentence = ''
   

#     for i in sentence:

#         if i.lower() in alphabets:
#             indexI = alphabets.find(i.lower())
#             if (indexI + shift)/26 < 1:
#                 newsentence += alphabets[indexI + shift]
#             else:
#                 newsentence += alphabets[(indexI + shift) - 26]
#         else:
#             newsentence += i
    
#     return newsentence

   

# def decript(sentence , shift):
#     newsentence = ''
   

#     for i in sentence:

#         if i.lower() in alphabets:
#             indexI = alphabets.find(i.lower())
            
#             newsentence += alphabets[indexI - shift]    
            
                
#         else:
#             newsentence += i

#     return newsentence




    

# alphabets = 'abcdefghijklmnopqrstuvwxyz'


# print(encript('Ceaser Cypher 5.0 is fun' , 10))
# print(decript('mokcob mizrob 5.0 sc pex' , 10))


test_list = [10,20,30,40,50,30]

count = {}
sum = 0

for i in test_list:
    if i not in count:
        count[i] = 1
    else:
        count[i] += 1
    
    sum += i



    mean = sum / len(test_list)

if len(test_list) % 2 == 0:
    print("the median is: " ,( test_list[len(test_list)//2] + test_list[len(test_list)//2 + 1]) / 2)
else:
    print('The median is ' , test_list[len(test_list)// 2])

for i in count:
    if count[i] == max(count.values()):
        print('The mode is ', i)
        break
    
print('the mean is ',mean)



#already solved last question.


