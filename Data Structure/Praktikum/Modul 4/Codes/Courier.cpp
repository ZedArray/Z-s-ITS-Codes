#include <bits/stdc++.h>

using namespace std;

struct GraphNode{
    int numVertices;
    list<int>* adjLists;
    bool* visited;
};

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
        //_root->adjLists[dest].push_back(src);
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
};


int main() {
    int points, numOfRoads, startingPoint, numOfPackages;
    deque <int>pkg;
    deque<int> nonDelivered;
    cin >> points >> numOfRoads >> startingPoint >> numOfPackages;
    Graph g;
    g.init(numOfRoads+1);
    for(int i = 0; i < numOfRoads; i++) {
        int start, destination;
        cin >> start >> destination;
        g.addEdge(start, destination);
    }
    for(int i = 0; i < numOfPackages; i++) {
        int input;
        cin >> input;
        pkg.push_back(input);
    }
    for(int i = 0; i < pkg.size(); i++){
        if(!g.DFS(startingPoint, pkg.at(i))){
            nonDelivered.push_back(pkg.at(i));
        }
    }
    if(nonDelivered.empty()){
        cout << "All packages are delivered today!" << endl;
    }
    else{
        cout << "Packages to be delivered tomorrow: " << endl;
        for(int i = 0 ; i < nonDelivered.size() ; i++){
            cout << nonDelivered.at(i) << " " << endl;
        }
    }
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
/* 
10 11 1 3
1 2
2 3
3 6
4 3
5 3
5 8
6 7
7 8
7 9
9 10
10 6
4
8
10
 */