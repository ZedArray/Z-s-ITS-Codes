#include <bits/stdc++.h>
using namespace std;

struct Graph {
private:
    int** adjMatrix;
    int numVertices;

public:
  // Initialize the matrix to zero
    Graph(int numVertices) {
        this->numVertices = numVertices;
        adjMatrix = new int*[numVertices];
        for (int i = 0; i < numVertices; i++) {
        adjMatrix[i] = new int[numVertices];
        for (int j = 0; j < numVertices; j++)
            adjMatrix[i][j] = false;
        }
    }

  // Add edges
    void addEdge(int i, int j, int input) {
        adjMatrix[i][j] = input;
        adjMatrix[j][i] = input;
    }

  // Remove edges
    void removeEdge(int i, int j) {
        adjMatrix[i][j] = false;
        adjMatrix[j][i] = false;
    }

  // Print the martix
    void toString() {
        for (int i = 0; i < numVertices; i++) {
        cout << i << " : ";
        for (int j = 0; j < numVertices; j++)
            cout << adjMatrix[i][j] << " ";
        cout << "\n";
        }
    }

    ~Graph() {
        for (int i = 0; i < numVertices; i++)
        delete[] adjMatrix[i];
        delete[] adjMatrix;
    }
};

int main(){
    int h, l;
    cin >> h >> l;
    Graph graph(max(h, l));
    
    for(int i = 0; i < h; i++){
        for(int j = 0; j < l; j++){
            int in;
            cin >> in;
            g.addEdge(i, j, in);
        }
    }
    // deque<int> dq[h];
    // for(int i = 0; i < h; i){
    //     for(int j = 0; j < l; j++){
    //         int input;
    //         cin >> input;
    //         dq[i].push_back(input);
    //     }
    // }
    // int y, x;
    // cin >> y >> x;
    // dq[y].at(x);

}