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


cityAmount = 100
populationSize = 10
generationAmount = 10000




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
# print(original)

print("Initial Best Distance: " + str(original))

# "Genetic Algorith"
for i in range(0, generationAmount):
    # print("\n\nle chromosome of: " + str(i))
    # print(chromosome)
    # print("\n\n")
    dis = 0
    newPop = []
    # print("\n\nle chromosome")
    # print(chromosome)
    p1 = chromosome[0][1]
    # print(p1)
    for loc in chromosome:
        if loc[1] != p1:   
            p2 = chromosome[1][1]
            break
    # print(p2)

    # print([chromosome[0][0], chromosome[0][1]])
    # print([chromosome[1][0], chromosome[1][1]])

    if p1 not in newPop:
        newPop.append([chromosome[0][0], chromosome[0][1]])
    # if p2 not in newPop:
    #     newPop.append([chromosome[1][0], chromosome[1][1]])

    chromosome = []
    # print("\n\nParents in the NewPop")
    # print(newPop)
    # p1.pop()
    # p2.pop()

    # print("\n\n----------Parents-----------")
    # print(p1)
    # print(p2)
    # print("\n\n")
    # --------Crossover----------
    for j in range(0, int(populationSize/4)):
        # print("\n\nNEWPOPOOPOPO")
        # print(newPop)

        randomizer = []
        while n:
            tempChild = []
            randomizer = []
            # print("rando n p1")
            # print(randomizer)
            # print(p1)
            while len(randomizer) < int(len(p1)/2):
                randomNumber = random.randint(1, len(p1)-1)
                if(randomNumber not in randomizer):
                    randomizer.append(randomNumber)

            # print("-------first child-------------")
            # print("randomizer")
            # print(randomizer)
            for k in p1:
                if k[0] in randomizer:
                    tempChild.append(k)
            # print("first rando half")
            # print(tempChild)
            for k in p2:
                if k not in tempChild:
                    tempChild.append(k)
            # print("last rand")
            # print(tempChild)
            tempChild.append(tempChild[0])
            # print(tempChild)

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

            # print("-------second child----------")
            # print(randomizer)
            for k in p2:
                if k[0] in randomizer:
                    tempChild.append(k)
            # print("first rando half")
            # print(tempChild)
            for k in p1:
                if k not in tempChild:
                    tempChild.append(k)
            # print("last rand")
            # print(tempChild)
            tempChild.append(tempChild[0])
            # print(tempChild)

            dis = totalDistance(tempChild)
            # print("aopisdfjapiosdjf")
            # print(tempChild)
            if(tempChild not in newPop):
                newPop.append([dis, tempChild])
                break
            # print(newPop)

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
            # print("\n\n tempchild1")
            # print(tempChild)
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
            # print("\n\ntempchild2")
            # print(tempChild)
            dis = totalDistance(tempChild)
            if tempChild not in newPop:
                newPop.append([dis, tempChild])
                break

        tempChild = []

        # print("\n\nnewpop")
        # print(newPop)



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
    # print("\n\nunsorted newpop")
    # print(newPop)
    newPop.sort(key = lambda x : x[0])
    # print("\n\n--------New Pop-------")
    # print(newPop)
    chromosome = newPop.copy()
    newPop = []
    # print("\n\n-------new Chromosome-------")
    # print(chromosome)
    if(i % 10 == 0):
        print("Current best distance of Gen " + str(i) + ": " + str(chromosome[0][0]))
        # print(chromosome)

print("\n\nBest cost of initial population: " + str(original))
print("\n\nlo and behold, The final result after training is: ")
print(chromosome[0][0])
# print(chromosome)
# print(chromosome[0][1])
path = []
for i in range(0, int(cityAmount+1)):
    path.append(chromosome[0][1][i][0])
print("\n\nwith the path of: \n")
print(path)
print(len(chromosome))
print(chromosome[len(chromosome)-1])
print("\n\ngoijgapoijfg")
# print(chromosome)
drawMap(city, chromosome[0])

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