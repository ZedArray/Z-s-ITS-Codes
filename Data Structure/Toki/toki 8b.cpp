#include <bits/stdc++.h>
using namespace std;

int main(){
    deque<int> theQueue;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x, y;
        string cmd;
        cin >> cmd;
        if(cmd == "add"){
            cin >> x;
            cin >> y;
            for(int i = 0; i < y ; i++){
                theQueue.push_back(x);
            }
            cout << theQueue.size() << endl;
        }
        else if (cmd == "del"){
            cin >> y;
            for (int i = 0; i < y ; i++){
                if (i == 0) {
                    cout << theQueue.front() << endl;
                }
                theQueue.pop_front();
            }
        }
        else if (cmd == "rev") {
            reverse(theQueue.begin(), theQueue.end());
        }
    }
}