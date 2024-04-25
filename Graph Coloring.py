import heapq


class nodeInfo:
	def __init__(self, sat, deg, vertex):
		self.sat = sat
		self.deg = deg
		self.vertex = vertex


class maxSat:
	def __call__(self, node):
		return (-node.sat, -node.deg, node.vertex)


class Graph:
	def __init__(self, numNodes):
		self.n = numNodes
		self.adj = [[] for i in range(numNodes)]

	def addEdge(self, u, v):
		self.adj[u].append(v)
		self.adj[v].append(u)

	def DSatur(self):
		used = [False] * self.n
		c = [-1] * self.n
		d = [len(self.adj[u]) for u in range(self.n)]
		adjCols = [set() for u in range(self.n)]
		Q = []

		for u in range(self.n):
			heapq.heappush(Q, (maxSat()(nodeInfo(0, d[u], u)), u))

		while Q:
			maxPtr, u = heapq.heappop(Q)
			while Q and maxPtr == Q[0][0]:
				_, v = heapq.heappop(Q)
				heapq.heappush(
					Q, (maxSat()(nodeInfo(len(adjCols[v]), d[v], v)), v))

			for v in self.adj[u]:
				if c[v] != -1:
					[used] = True
			for i in range(self.n):
				if not used[i]:
					break
			for v in self.adj[u]:
				if c[v] != -1:
					[used] = False
			c[u] = i
			for v in self.adj[u]:
				if c[v] == -1:
					heapq.heappush(
						Q, (maxSat()(nodeInfo(len(adjCols[v]), d[v], v)), v))
					adjCols[v].add(i)
					d[v] -= 1

		for u in range(self.n):
			print(f"Vertex {u} ---> Color {c[u]}")


# Driver Code
if __name__ == '__main__':
	G1 = Graph(5)
	G1.addEdge(0, 1)
	G1.addEdge(0, 2)
	G1.addEdge(1, 2)
	G1.addEdge(1, 3)
	G1.addEdge(2, 3)
	G1.addEdge(3, 4)
	print("Coloring of graph G1 ")
	G1.DSatur()

	G2 = Graph(5)
	G2.addEdge(0, 1)
	G2.addEdge(0, 2)
	G2.addEdge(1, 2)
	G2.addEdge(1, 4)
	G2.addEdge(2, 4)
	G2.addEdge(4, 3)
	print("\nColoring of graph G2 ")
	G2.DSatur()

	# This code is conytributed by Akash Jha
