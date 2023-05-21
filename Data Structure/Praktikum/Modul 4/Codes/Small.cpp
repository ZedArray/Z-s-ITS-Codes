#include <bits/stdc++.h>
#include <vector>
using namespace std;
struct graph{
    vector<int> adjacentEdges;
};
/* 
Make an adjacency list for each coordinate
ex:
    adjacencyList[0][0] = {0, 1}, {1, 1}, {1, 0}
    adjacencyList[1][0] = {2, 0}, {2, 1}, {1, 1}, {1, 0}, {0, 0}
    adjacencyList[2][0] = {3, 0}, {2, 1}, {1, 1}, {1, 0}
*/

int main(){
    vector<int> adjacent[10];
    vector<int> adjacentEdges[10];
    deque<int> counter;
    for(int i = 0 ; i < 10 ; i++){
        for(int j = 0 ; j < 10 ; j++){
            int input;
            cin >> input;
            adjacent[i].push_back(input);
        }
    }
    for(int i = 0 ; i < 10 ; i++){
        for(int j = 0 ; j < 10 ; j++){
            if(adjacent[i].at(j) == 1){
                adjacentEdges[i].push_back(j);
            }
        }
    }
    for(int i = 0 ; i < 10 ; i++){
        for(int j = 0 ; j < 10 ; j++){
            cout << adjacent[i].at(j) << " ";
        }
        cout << endl;
    }
    // for(int i = 0 ; ; ){
    //     counter.push_back(0);
    //     for(int j = 0 ; j < adjacentEdges[i].size() ; j++){
    //         if(i = 0){
    //             counter.at(i)++;
    //         }
    //         else{
    //             if(adjacentEdges[i].at(0) - adjacentEdges[i - 1].at(0) > 1){
    //                 i++;
    //             }
    //             else{
    //                 counter.at(i)++;
    //             }
    //         }
    //     }
    //     cout << endl;
    //}
    for(int i = 0 ; i < 10 ; i++){
        for(int j = 0 ; j < adjacentEdges[i].size() ; j++){
            cout << adjacentEdges[i].at(j) << " ";
        }
        cout << endl;
    }
    for(int i = 0 ; i < counter.size() ; i++){
        cout << counter[i] << " ";
    }

}
/* 
1 1 1 1 1 0 0 0 0 0
1 1 1 0 0 1 0 0 0 0
1 1 1 0 0 0 0 0 0 0
1 1 0 0 0 0 0 0 0 0
0 0 0 0 1 1 0 0 0 0
0 0 0 1 1 0 1 0 0 0
0 0 0 1 1 1 0 0 0 1
0 0 0 0 0 0 0 0 1 1
0 0 0 0 0 0 0 1 1 1
0 0 0 0 0 1 1 1 1 1
 */