import numpy as np

# Define the city coordinates as a NumPy array
cities = np.array([
    (0, 0),
    (1, 3),
    (2, 2),
    (3, 4),
    (4, 1)
])

# Define the parameters for the genetic algorithm
population_size = 100
mutation_rate = 0.01
num_generations = 1000

# Calculate the Euclidean distance between two cities
def distance(city1, city2):
    return np.sqrt(np.sum((city1 - city2) ** 2))

# Calculate the total distance of a tour
def total_distance(tour):
    dist = 0
    for i in range(len(tour) - 1):
        dist += distance(cities[tour[i]], cities[tour[i + 1]])
    dist += distance(cities[tour[-1]], cities[tour[0]])
    return dist

# Create an initial population of random tours
def create_population(size):
    city_indices = list(range(len(cities)))
    return [list(np.random.permutation(city_indices)) for _ in range(size)]

# Perform order crossover (OX1) on two parent tours to create two offspring tours
def crossover(parent1, parent2):
    start, end = sorted(np.random.choice(len(parent1), 2, replace=False))
    child1 = [-1] * len(parent1)
    child2 = [-1] * len(parent1)
    for i in range(start, end + 1):
        child1[i] = parent1[i]
        child2[i] = parent2[i]

    for i in range(len(parent1)):
        if child1[i] == -1:
            for gene in parent2:
                if gene not in child1:
                    child1[i] = gene
                    break
        if child2[i] == -1:
            for gene in parent1:
                if gene not in child2:
                    child2[i] = gene
                    break

    return child1, child2

# Perform mutation by swapping two random cities in a tour
def mutate(tour):
    if np.random.rand() < mutation_rate:
        idx1, idx2 = np.random.choice(len(tour), 2, replace=False)
        tour[idx1], tour[idx2] = tour[idx2], tour[idx1]

# Main genetic algorithm loop
def genetic_algorithm():
    population = create_population(population_size)

    for generation in range(num_generations):
        population = sorted(population, key=lambda x: total_distance(x))
        best_tour = population[0]
        print(f"Generation {generation}: Best Distance = {total_distance(best_tour)}")
        
        new_population = [best_tour]  # Preserve the best tour
        
        while len(new_population) < population_size:
            parent1, parent2 = np.random.choice(population[:10], 2, replace=False)
            child1, child2 = crossover(parent1, parent2)
            mutate(child1)
            mutate(child2)
            new_population.extend([child1, child2])

        population = new_population

    print(f"Best Tour: {best_tour}")
    print(f"Best Distance: {total_distance(best_tour)}")

if __name__ == "__main__":
    genetic_algorithm()
