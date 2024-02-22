import random
import math
import matplotlib.pyplot as plt

# calculate distance between two cities
def distance(x1, y1, x2, y2):
    return (((x2 - x1)**2 +(y2 - y1)**2)**0.5) 

def totalDistance(cCounted):
    cost = 0.0
    for i in range(len(cCounted) - 1):
        cost += distance(cCounted[i][1], cCounted[i][2], cCounted[i+1][1], cCounted[i+1][2])
    return cost

def drawMap(city, answer):
    for j in city:
        plt.plot(j[1], j[2], "ro")
        plt.annotate(j[0], (j[1], j[2]))

    for i in range(len(answer[1])):
        try:
            first = answer[1][i]
            secend = answer[1][i + 1]

            plt.plot([first[1], secend[1]], [first[2], secend[2]], "black")
        except:
            continue

    first = answer[1][0]
    secend = answer[1][-1]
    plt.plot([first[1], secend[1]], [first[2], secend[2]], "black")

    plt.show()

cityAmount = 1000
populationSize = 100
generationAmount = 1000

city = []

# inputting city data into the list
for i in range(0, cityAmount):
    n = input()
    split = n.split()
    city.append([int(split[0]), float(split[1]), float(split[2])])

chromosome = []

for i in range(0, populationSize):
    copy = city.copy()
    random.shuffle(copy)
    copy.append(copy[0])
    cost = totalDistance(copy)
    chromosome.append([cost, copy])

chromosome.sort(key = lambda x: x[0])
original = chromosome[0][0]

print("Initial Best Distance: " + str(original))

# "Genetic Algorithm"
for i in range(0, generationAmount):
    dis = 0
    newPop = []
    p1 = chromosome[0][1]
    for loc in chromosome:
        if loc[1] != p1:   
            p2 = chromosome[1][1]
            break

    if p1 not in newPop:
        newPop.append([chromosome[0][0], chromosome[0][1]])

    chromosome = []
    for j in range(0, int(populationSize/4)):
        randomizer = []
        while n:
            tempChild = []
            randomizer = []
            while len(randomizer) < int(len(p1)/2):
                randomNumber = random.randint(1, len(p1)-1)
                if(randomNumber not in randomizer):
                    randomizer.append(randomNumber)

            for k in p1:
                if k[0] in randomizer:
                    tempChild.append(k)
            for k in p2:
                if k not in tempChild:
                    tempChild.append(k)
            tempChild.append(tempChild[0])

            dis = totalDistance(tempChild)
            if(tempChild not in newPop):
                newPop.append([dis, tempChild])
                break

        while n:
            tempChild = []
            randomizer = []

            while len(randomizer) < int(len(p1)/2):
                randomNumber = random.randint(1, len(p1)-1)
                if(randomNumber not in randomizer):
                    randomizer.append(randomNumber)

            for k in p2:
                if k[0] in randomizer:
                    tempChild.append(k)
            for k in p1:
                if k not in tempChild:
                    tempChild.append(k)
            tempChild.append(tempChild[0])

            dis = totalDistance(tempChild)
            if(tempChild not in newPop):
                newPop.append([dis, tempChild])
                break

        tempChild = []
        randomizer = []

        # Mix parent1 into parent2
        while n:
            tempChild = []
            for k in range(0, int(len(p1)/2)):
                tempChild.append(p1[k])
            random.shuffle(tempChild)
            for k in p2:
                if k not in tempChild:
                    tempChild.append(k)
            tempChild.append(tempChild[0])
            dis = totalDistance(tempChild)
            if tempChild not in newPop:
                newPop.append([dis, tempChild])
                break

        tempChild = []

        while n:
            tempChild = []
            # Mix parent2 into parent1
            for k in range(0, int(len(p2)/2)):
                tempChild.append(p2[k])
            random.shuffle(tempChild)
            for k in p1:
                if k not in tempChild:
                    tempChild.append(k)
            tempChild.append(tempChild[0])
            dis = totalDistance(tempChild)
            if tempChild not in newPop:
                newPop.append([dis, tempChild])
                break

        tempChild = []

    # # ----------------Complete Randomizer---------------
    for j in range(0, math.ceil(populationSize / 10)):
        cp1 = p1.copy()
        cp1.pop()
        random.shuffle(cp1)
        cp1.append(cp1[0])
        dis = totalDistance(cp1)
        if cp1 not in newPop:
            newPop.append([dis,cp1])
            break
    newPop.sort(key = lambda x : x[0])
    chromosome = newPop.copy()
    newPop = []
    if(i % 10 == 0):
        print("Current best distance of Gen " + str(i) + ": " + str(chromosome[0][0]))

print("\n\nBest cost of initial population: " + str(original))
print("\n\nlo and behold, The final result after training is: ")
print(chromosome[0][0])
path = []
for i in range(0, int(cityAmount+1)):
    path.append(chromosome[0][1][i][0])
print("\n\nwith the path of: \n")
print(path)
drawMap(city, chromosome[0])