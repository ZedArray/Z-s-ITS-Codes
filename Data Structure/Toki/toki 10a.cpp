#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    int graph[n][n] = {0};
    for(int i = 0; i < q; i++){
        int indicator = 0;
        int cmd;
        cin >> cmd;
        if(cmd == 1){
            int a, b;
            cin >> a >> b;
            graph[a][b] = 1;
            graph[b][a] = 1;
        }
        else if(cmd == 2){
            int a, b;
            cin >> a >> b;
            if(a > b){
                swap(a, b);
            }
            for(int i = 0; i < b; i++){
                if(graph[a][i] == 1){
                    a = i;
                }
                else if(graph[a][b] == 1){
                    indicator = 1;
                    break;
                }
            }
            if(indicator == 1){
                cout << "Y" << endl;
            }
            else if(indicator == 0){
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