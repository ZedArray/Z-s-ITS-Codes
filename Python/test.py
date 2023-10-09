import random
import math

# calculate distance between two cities
def distance(x1, y1, x2, y2):
    return (((x2 - x1)**2 +(y2 - y1)**2)**0.5) 

def totalDistance(cCounted):
    cost = 0.0
    for i in range(len(cCounted) - 1):
        cost += distance(cCounted[i][1], cCounted[i][2], cCounted[i+1][1], cCounted[i+1][2])
    return cost



cityAmount = 10
populationSize = 100
generationAmount = 100




# cityAmount = input("Input the number of cities\n(10 is default)\n")
# cityAmount = int(cityAmount)

city = []

# inputting city data into the list
for i in range(0, cityAmount):
    n = input()
    split = n.split()
    # print(split)
    city.append([int(split[0]), float(split[1]), float(split[2])])

chromosome = []

for i in range(0, populationSize):
    # print("Start of Chromosme " + str(i) + "--------------\n\n")
    copy = city.copy()
    random.shuffle(copy)
    copy.append(copy[0])
    # print("Shuffled Copy")
    # print(copy)
    # print("\n\n")
    cost = totalDistance(copy)
    chromosome.append([cost, copy])
    
    # print("End of Chromosome " + str(i) + "----------------\n\n")

chromosome.sort(key = lambda x: x[0])
# print("orginal Chromosome ")
# print(chromosome)
# print("\n\n")
original = chromosome[0][0]
newPop = []

for i in range(0, generationAmount):
    newPop.clear()
    # "mutation"
    p1 = chromosome[0][1]
    p2 = chromosome[1][1]
    # print([chromosome[0][0], chromosome[0][1]])
    # print([chromosome[1][0], chromosome[1][1]])

    newPop.append([chromosome[0][0], chromosome[0][1]])
    newPop.append([chromosome[1][0], chromosome[1][1]])

    chromosome.clear()
    # print("Parents in the NewPop")
    # print(newPop)
    # p1.pop()
    # p2.pop()

    # print("\n\n----------Parents-----------")
    # print(p1)
    # print(p2)
    # print("\n\n")

    # --------Crossover----------
    for j in range(0, int(populationSize/2)):
        randomizer = []
        print("rando n p1")
        print(randomizer)
        print(p1)
        while len(randomizer) < int(len(p1)/2):
            randomNumber = random.randint(1, len(p1))
            print(randomNumber)
            if(randomNumber not in randomizer):
                randomizer.append(randomNumber)

        print("-------first child-------------")
        print("randomizer")
        print(randomizer)
        tempChild = []
        for k in p1:
            if k[0] in randomizer:
                tempChild.append(k)
        # print("first rando half")
        # print(tempChild)
        for k in p2:
            if k not in tempChild:
                tempChild.append(k)
        print("last rand")
        print(tempChild)
        tempChild.append(tempChild[0])
        # print(tempChild)

        dis = totalDistance(tempChild)
        newPop.append([dis, tempChild])
        tempChild.clear()
        randomizer.clear()

        while len(randomizer) < int(len(p1)/2):
            randomNumber = random.randint(1, len(p1))
            if(randomNumber not in randomizer):
                randomizer.append(randomNumber)

        print("-------second child----------")
        print(randomizer)
        for k in p2:
            if k[0] in randomizer:
                tempChild.append(k)
        # print("first rando half")
        # print(tempChild)
        for k in p1:
            if k not in tempChild:
                tempChild.append(k)
        print("last rand")
        print(tempChild)
        tempChild.append(tempChild[0])
        # print(tempChild)

        dis = totalDistance(tempChild)
        newPop.append([dis, tempChild])
        tempChild.clear()
        randomizer.clear()

        # # Mix parent1 into parent2

        # for j in range(0, int(len(p1)/2)):
        #     tempChild.append(p1[i])
        # for j in p2:
        #     if j not in tempChild:
        #         tempChild.append(i)
        # tempChild.append(tempChild[0])
        # print(tempChild)
        # dis = totalDistance(tempChild)
        # newPop.append([dis, tempChild])
        # tempChild.clear()


        # # Mix parent2 into parent1
        # for j in range(0, int(len(p2)/2)):
        #     tempChild.append(p2[i])
        # for j in p1:
        #     if j not in tempChild:
        #         tempChild.append(i)
        # tempChild.append(tempChild[0])
        # print(tempChild)
        # dis = totalDistance(tempChild)
        # newPop.append([dis, tempChild])
        # tempChild.clear()



    # # ----------------Complete Randomizer---------------
    # for j in range(0, math.ceil(populationSize / 2)):
    #     cp1 = p1.copy()
    #     cp1.pop()
    #     random.shuffle(cp1)
    #     cp1.append(cp1[0])
    #     dis = totalDistance(cp1)
    #     newPop.append([dis,cp1])
    #     # print("shuffled cp1")
    #     # print(cp1)
    #     # print("\n\n")
    #     cp2 = p2.copy()
    #     cp2.pop()
    #     random.shuffle(cp2)
    #     cp2.append(cp2[0])
    #     dis = totalDistance(cp2)
    #     newPop.append([dis,cp2])
    #     # print("shuffled cp2")
    #     # print(cp2)
    #     # print("\n\n")

    newPop.sort(key = lambda x : x[0])
    # print("\n\n--------New Pop-------")
    # print(newPop)
    chromosome = newPop.copy()
    # print("\n\n-------new Chromosome-------")
    # print(chromosome)
    if(i % 10 == 0):
        print("Current best distance of Gen " + str(i) + ": " + str(chromosome[0][0]))
        # print(newPop)

print("\n\nBest cost of initial population: " + str(original))
print("\n\nlo and behold, The final result after training is: ")
print(chromosome[0][0])

# print(chromosome[0][1])
path = []
for i in range(0, cityAmount+1):
    path.append(chromosome[0][1][i][0])
print("\n\nwith the path of: \n")
print(path)



# for i in range(0, cityAmount):
#     print(chromosome[0][0][0][0])

# for i in range(0, len(cp1) - math.ceil(len(cp1)/3)):
    
# print(cost)
# print( )
# print(city)
# print( )

# temp = []
# for i in range(0, ):
#     temp.append([city[0][0], city[0][1], city[0][2], city[0][3]])
#     city.pop(0)

# print(temp)
# print( )
# print(city)