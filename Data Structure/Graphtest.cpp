#include <bits/stdc++.h>
using namespace std;
#define lli long long int

struct graph{
    vector<int> *adjacencies;
    int size;
    vector<bool> *visited;
    
    void init(int n){
        adjacencies = new vector<int>[n];
        size = n;
        visited = new vector<bool>(n, false);
    }

    void addEdge(int src, int dst){
        adjacencies[src].push_back(dst);
        adjacencies[dst].push_back(src);
    }
    
    void printAll(){
        // cout << "limit" << n;
        for(int source = 0; source < size; source++){
            cout << "Adjacency list of " << source << ": ";
            for(int destination : adjacencies[source]){
                cout << destination << ", ";
            }
            cout << endl;
        }
    }
    void dfs(/* vector<bool> &visited ,*/ int currentNode){
        //visited = true;
        visited[currentNode] = true;
        for(int neighbor : adjacencies[currentNode]){
            //dfs(graph, visited, neighbor);
        }
    }
};

int main(){
    graph graph;
    int amountOfNodes = 7;
    graph.init(amountOfNodes);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);
    graph.printAll();

    vector<bool> visited[amountOfNodes];


}