#include <bits/stdc++.h>
using namespace std;
int main(){
    deque<int> test;
    int n;
    cin  >> n;
    for(int i = 0; i < n; i++){
        test.push_back(i);
    }
    vector<int> days[5];
    while(!test.empty()){
        for(int i = 0; i < 5; i++){
            if (test.empty()){
                break;
            }
            days[i].push_back(test.front());
            test.pop_front();
        }
    }
    string day[5] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    for (int i = 0; i < 5; i++){
        cout << day[i] << endl;
        for (int j = 0; j < days[i].size(); j++){
            cout << days[i][j] << endl;
        }
    }
}