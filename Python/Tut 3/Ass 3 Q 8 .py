f = open('readlines.txt' , 'r')
t = open('writelines.txt' , 'w')

t.write(f.read().upper())


f.close()