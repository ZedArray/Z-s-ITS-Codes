#include <bits/stdc++.h>
using namespace std;

int main(){
    deque<int> thequeue;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string command;
        cin >> command;
        int input;
        if(command == "push_front"){
            cin >> input;
            thequeue.push_front(input);
        }
        else if(command == "push_back"){
            cin >> input;
            thequeue.push_back(input);
        }
        else if(command == "pop_front"){
            thequeue.pop_front();
        }
        else if(command == "pop_back"){
            thequeue.pop_back();
        }
    }
    while(thequeue.size() > 0){
        cout << thequeue.front() << endl;
        thequeue.pop_front();
    }
    return 0;
}