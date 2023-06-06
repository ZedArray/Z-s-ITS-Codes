#include <bits/stdc++.h>

using namespace std;

struct GraphNode{
    int numVertices;
    list<int>* adjLists;
    bool* visited;
};
vector<int> path;

struct Graph{
    GraphNode *_root;

    void init(int vertices) {
        _root = new GraphNode();
        _root->numVertices = vertices;
        _root->adjLists = new list<int>[vertices];
        _root->visited = new bool[vertices];
    }

    void addEdge(int src, int dest) {
        _root->adjLists[src].push_back(dest);
        _root->adjLists[dest].push_back(src);
    }


    bool BFS(int startVertex, int target) {
        _root->visited = new bool[_root->numVertices];
        for (int i = 0; i < _root->numVertices; i++) {
            _root->visited[i] = false;
        }

        list<int> queue;

        _root->visited[startVertex] = true;
        queue.push_back(startVertex);

        list<int>::iterator i;
        while (!queue.empty()) {
            int currVertex = queue.front();
            //cout << currVertex << endl;
            //cout << "Visited " << currVertex << endl;
            if(currVertex == target){
                return true;
            }
            queue.pop_front();

            for (i = _root->adjLists[currVertex].begin(); i != _root->adjLists[currVertex].end(); ++i) {
                int adjVertex = *i;
                if (!_root->visited[adjVertex]) {
                    _root->visited[adjVertex] = true;
                    queue.push_back(adjVertex);
                }
            }
        }
        return false;
    }


    bool DFS(int startVertex, int target) {
        _root->visited = new bool[_root->numVertices];
        for (int i = 0; i < _root->numVertices; i++) {
            _root->visited[i] = false;
        }

        list<int> stack;

        _root->visited[startVertex] = true;
        stack.push_back(startVertex);

        list<int>::iterator i;
        while (!stack.empty()) {
            int currVertex = stack.back();
            cout << currVertex << endl;
            if (currVertex == target){
                return true;
            }
            //cout << "Visited " << currVertex << endl;
            stack.pop_back();
            for (i = _root->adjLists[currVertex].begin(); i != _root->adjLists[currVertex].end(); ++i) {
                int adjVertex = *i;
                if (!_root->visited[adjVertex]) {
                    _root->visited[adjVertex] = true;
                    stack.push_back(adjVertex);
                }
            }

        }
        return false;
    }
    //RECURSIVE DFS
    // void DFS(int vertex) {
    //     _root->visited[vertex] = true;
    //     list<int> adjList = _root->adjLists[vertex];

    //     cout << "Visited " << vertex << endl;

    //     list<int>::iterator i;
    //     for (i = adjList.begin(); i != adjList.end(); ++i)
    //         if (!_root->visited[*i])
    //             DFS(*i);
    // }
};


int main() {
    int n, q;
    cin >> n >> q;
    Graph g;
    g.init(n+1);
    list<int> bruh;
    for(int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;
        g.addEdge(a, b);
        bruh.push_back(a);
        bruh.push_back(b);
    }
    bruh.sort();
    //g.BFS(1, bruh.back());
    g.DFS(1, bruh.back());
    // for(int i = 0; i < q; i++){
    //     int cmd;
    //     cin >> cmd;
    //     int a, b;
    //     if(cmd == 1){
    //         cin >> a >> b;
    //         g.addEdge(a, b);
    //     }
    //     else if(cmd == 2){
    //         cin >> a >> b;
    //         if(g.BFS(a, b) == true){
    //             cout << "Y" << endl;
    //         }
    //         else{
    //             cout << "T" << endl;
    //         }
    //     }
    // }
    // g.addEdge(0, 1);
    // g.addEdge(0, 2);
    // g.addEdge(0, 3);
    // g.addEdge(1, 2);
    // g.addEdge(2, 4);

    // g.BFS(0);
    // cout << endl;
    // g.DFS(0);

    return 0;
}