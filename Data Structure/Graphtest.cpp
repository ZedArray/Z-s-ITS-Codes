#include <bits/stdc++.h>
using namespace std;
#define lli long long int
struct graph{
    vector<int> *adjacencies;
    
    void init(int n){
        adjacencies = new vector<int>[n];
    }

    void addEdge(int src, int dst){
        adjacencies[src].push_back(dst);
        adjacencies[dst].push_back(src);
    }
    
    void print(int n){
        for(int i = 0; i < n; i++){
            for(int destination : adjacencies[i]){
                cout << adjacencies[i].at(i) << " " << destination << endl;
            }
        }
    }
};

int main(){
    graph graph;
    int amountOfNodes = 6;
    graph.init(amountOfNodes);
    //cin >> amountOfNodes;
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);
    graph.print(amountOfNodes);
}