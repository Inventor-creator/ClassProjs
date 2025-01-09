r1 = int(input('Enther R1 '))
r2 = int(input('Enther R2 '))
x1 = int(input('Enther X1 '))
x2 = int(input('Enther X2 '))
y1 = int(input('Enther Y1 '))
y2 = int(input('Enther Y2 '))

distCenters = ((x2 - x1) ** 2 + (y2 - y1) ** 2) ** 0.5


if distCenters < r1 + r2 or distCenters > abs(r1 - r2):
    print("Circles are intersecting")
elif distCenters > r1 + r2:
    print('Circles dont intersect') 
elif distCenters == r1 + r2:
    print("Circles touch at one point from outside")
elif    distCenters == r1 - r2:
    print("Circles touch at one point from inside")
elif distCenters < r1 - r2:
    print('Circles lie inside each other')


