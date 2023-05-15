#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    int graph[n][n] = {0};
    for(int i = 0; i < q; i++){
        int cmd;
        cin >> cmd;
        if(cmd == 1){
            int a, b;
            cin >> a >> b;
            graph[a][b] = 1;
            graph[b][a] = 1;
        }
        if(cmd == 2){
            int a, b;
            cin >> a >> b;
            if(graph[a][b] == 1){
                cout << "Y" << endl;
            }
            // else if(graph[a][b] == 0){
            //     cout << graph[a][b] << "T" << endl;
            // }
            else{
                cout << "T" << endl;
            }
        }
    }
}

/* 5 7
1 1 4
2 1 2
1 1 2
2 1 2
1 3 5
1 2 3
2 1 5 */