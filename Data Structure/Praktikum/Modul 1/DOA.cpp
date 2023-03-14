#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, cmds, biggest = -1000, rotator = 1;
    deque<int> cont;
    cin >> n;
    cin >> cmds;
    if(cmds < 1 ||n < 1){
        cout << "Input Not Valid" << endl;
    }
    else{    
        for(int i = 0; i < n; i++){
            int input;
            cin >> input;
            cont.push_back(input);
        }
        biggest = cont.front();
        cont.pop_front();
        for(int i = 0; i < cmds; i++){
            int commands;
            cin >> commands;
            for(; rotator < commands; rotator++){
                if(biggest <= cont.front()){
                    cont.push_back(biggest);
                    biggest = cont.front();
                    cont.pop_front();
                }
                else{
                    cont.push_back(cont.front());
                    cont.pop_front();
                }
            }
            cout << biggest << " " << cont.front() << endl;
        }
    }
}