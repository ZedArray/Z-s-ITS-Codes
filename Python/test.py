import random

# calculate distance between two cities
def distance(x1, y1, x2, y2):
    return (((x2 - x1)**2 +(y2 - y1)**2)**0.5) 

cityAmount = 10

cityAmount = input("Input the number of cities\n(10 is default)\n")

city = []

# inputting city data into the list
for i in range(0, cityAmount):
    n = input()
    split = n.split()
    # print(split)
    city.append([int(split[0]), float(split[1]), float(split[2])])

for i in range(0, 50):
    # assigning randomizers to cities
    for i in range(0, cityAmount):
        city[i].insert(0, random.random())
    city.sort(key = lambda x: x[0])
    city.append(city[0])
    # print(city)
    cost = 0.0

    for i in range(0 , cityAmount+1):
        cost += distance(city[i][2], city[i][3], city[i+1][2], city[i+1][3])
    
print(cost)
print( )
print(city)
print( )

temp = []
for i in range(0, ):
    temp.append([city[0][0], city[0][1], city[0][2], city[0][3]])
    city.pop(0)

print(temp)
print( )
print(city)