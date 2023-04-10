#include <bits/stdc++.h>
using namespace std;

void dfs(map<int,int> graph, int start){
    stack<int> s;
    s.push(start);
    while(!s.empty()){
        start = s.top();
        s.pop();
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    map<int, bool> graph[n];
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        graph[x].insert({y, false});
    }

}