#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, cmds;
    deque<int> cont;
    cin >> n;
    cin >> cmds;
    int unchanged[n];
    if(cmds < 1 ||n < 1){
        cout << "Input Not Valid" << endl;
    }
    else{    
        for(int i = 0; i < n; i++){
            int input;
            cin >> input;
            cont.push_back(input);
            unchanged[i] = input;
        }
        for(int i = 0; i < cmds; i++){
            if(i != 0){
                cont.clear();
                for(int j = 0; j < n; j++){
                    cont.push_back(unchanged[j]);
                }
            }
            int biggest = cont.front();
            cont.pop_front();
            int commands;
            cin >> commands;
            for(int j = 1; j < commands ; j++){
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