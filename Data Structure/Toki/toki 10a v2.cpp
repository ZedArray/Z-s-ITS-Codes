#include <bits/stdc++.h>
using namespace std;
/* 
procedure DFS_iterative(G, v) is
    let S be a stack
    S.push(v)
    while S is not empty do
        v = S.pop()
        if v is not labeled as discovered then
            label v as discovered
            for all edges from v to w in G.adjacentEdges(v) do 
                S.push(w)
*/          
void DFS(int T, pair<int, bool> v){
    stack<pair<int, bool>> s;
    s.push(v);
    while(!s.empty()){
        v = s.top();
        s.pop();
        if(v.second == false){
            v.second = true;
        }
    }
}

int main(){
    int n, q;
    cin >> n >> q;
    deque<int> list[n];
    for(int i = 0; i < q; i++){
        int cmd, a, b;
        cin >> cmd;
        if(cmd == 1){
            cin >> a >> b;
            list[a].push_back(b);
            list[b].push_back(a);
        }
        else if(cmd == 2){
            int temp;
            cin >> a >> b;
            stack<int> S;
            S.push(a);
            while(!S.empty()){
                a = S.top();
                S.pop();
            }
            for(int i = 0; i < list[a].size(); i++){
                temp = a;
                if(a){
                    a = list[a].at(i);
                }
                else if(list[a].at(i) == b){
                    break;
                }
            }
        }
    }
}