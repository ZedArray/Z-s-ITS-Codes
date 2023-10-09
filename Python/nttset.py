import random
import math

# def distance(x1, y1, x2, y2):
#     return (((x2 - x1)**2 +(y2 - y1)**2)**0.5) 

# print(distance(-810,735,-438, 534))

# bruh = [[1, 2, 3], [4, 5, 6]]

# for i in range(0, 10):
# 	print(bruh)
# 	random.shuffle(bruh[0])

newPop = []

citylist1 = [[1, -810, 735], [2, -438, 534], [3, -64, -288], [4, -234, 124], [5, -214, 643], [6, -123, -423], [7, 142, 345]]
citylist2 = [[4, -234, 124], [5, -214, 643], [6, -123, -423], [1, -810, 735], [2, -438, 534], [3, -64, -288], [7, 142, 345]]

print(citylist1)
print(citylist2)

random.shuffle(citylist1)
random.shuffle(citylist2)

print(citylist1)
print(citylist2)



print("\n\n")
# for i in reversed(range(0, 10)):
#     print(i)

# randomizer = []
# while len(randomizer) < int(len(citylist1)/2):
#     randomNumber = random.randint(1, len(citylist1))
#     if(randomNumber not in randomizer):
#         randomizer.append(randomNumber)

# print("randomizer")
# print(randomizer)
tempChild = []
# for i in range(0, 10):
# 	randomizer = []
# 	while len(randomizer) < int(len(citylist1)/2):
# 		randomNumber = random.randint(1, len(citylist1))
# 		if(randomNumber not in randomizer):
# 			randomizer.append(randomNumber)

# 	print("-------first child-------------")
# 	print("randomizer")
# 	print(randomizer)
# 	tempChild = []
# 	for j in citylist1:
# 		if j[0] in randomizer:
# 			tempChild.append(j)
# 	print("first rando half")
# 	print(tempChild)
# 	for j in citylist2:
# 		if j not in tempChild:
# 			tempChild.append(j)
# 	print("last rand")
# 	print(tempChild)

# 	print("with origin return")
# 	tempChild.append(tempChild[0])
# 	print(tempChild)
# 	newPop.append(tempChild)

# 	tempChild.clear()

# 	print("-------second child----------")
# 	print(randomizer)
# 	for j in citylist2:
# 		if j[0] in randomizer:
# 			tempChild.append(j)
# 	print("first rando half")
# 	print(tempChild)
# 	for j in citylist1:
# 		if j not in tempChild:
# 			tempChild.append(j)
# 	print("last rand")
# 	print(tempChild)
# 	print("with origin return")
# 	tempChild.append(tempChild[0])
# 	print(tempChild)
# 	newPop.append(tempChild)
# 	tempChild.clear()

# Mix parent1 into parent2
for i in range(0, int(len(citylist1)/2)):
    tempChild.append(citylist1[i])
for i in citylist2:
	if i not in tempChild:
          tempChild.append(i)
print("child1")
print(tempChild)
tempChild.clear()
# Mix parent2 into parent1
for i in range(0, int(len(citylist2)/2)):
    tempChild.append(citylist2[i])
for i in citylist1:
	if i not in tempChild:
          tempChild.append(i)
print("c2")
print(tempChild)
tempChild.clear()

print(random.randint(0, len(citylist1)))
print(len(citylist1))


print("\n\n---------New Population------------")
print(newPop)

child = []

# for i in citylist1:
#     if i[0] is 2:
#          print(i)
#     else:
#          print("Not found")

print(child)

# print("bruh")

# print(math.floor(len(bruh)/2))
# x = 5/3
# print(x)
# print(math.floor(x))