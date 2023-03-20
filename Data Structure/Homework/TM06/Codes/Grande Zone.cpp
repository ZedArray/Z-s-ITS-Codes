#include <bits/stdc++.h>
using namespace std;

int main(){
    deque<int> queue;
    list<int> list;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        queue.push_back(input);
    }
    for(int i = 0; i < n; i++){
        int adder = 0;
        for(int j = i; j < n; j++){
            if(queue.at(i) <= queue.at(j)){
                adder += queue.at(i);
            }
            else break;
        }
        for(int j = i - 1; j >= 0; j--){
            if(queue.at(i) <= queue.at(j)){
                adder += queue.at(i);
            }
            else break;
        }
        //cout << adder << endl;
        list.push_back(adder);
    }
    list.sort();
    cout << list.back() << endl;
}