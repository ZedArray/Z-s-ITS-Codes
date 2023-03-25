#include <bits/stdc++.h>
using namespace std;

int main(){
    deque<int> dq;
    int n;
    int counter = 0; 
    cin >> n;
    for(int i = 0; i < n; i++){
        int input;
        //cout << "input: ";
        cin >> input;
        //cout << endl;
        dq.push_back(input);
        int size = dq.size();
        for(int j = 0; j < size - 1; j++){
            if(dq.at(j) == dq.at(j + 1)){
                counter++;
            }
            else if(dq.at(j) != dq.at(j + 1)){
                counter = 0;
            }
            if(counter == dq.at(j) - 1){
                for(int k = 0; k <= counter; k++){
                    dq.pop_back();
                }
                counter = 0;
                break;
            }
        }
        size = dq.size();
        cout << size << endl;
    }
}