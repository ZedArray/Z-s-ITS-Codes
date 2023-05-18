#include <bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int> pq;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int cmd;
        cin >> cmd;
        if(cmd == 1){
            int input;
            cin >> input;
            pq.push(input);
        }
        if(cmd == 2){
            cout << pq.top() << endl;
        }
        if (cmd == 3){
            pq.pop();
        }
    }
}