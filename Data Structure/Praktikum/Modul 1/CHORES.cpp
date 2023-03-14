#include <bits/stdc++.h>
using namespace std;

int main(){
    int e, n;
    int indicator = 0;
    list<int> energy;
    list<int> sortedE;
    list<string> tasks;
    cin >> e;
    cin >> n;
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        energy.push_back(input);
        sortedE.push_back(input);
        string task;
        cin >> task;
        tasks.push_back(task);
    }
    sortedE.sort();
    for(int i = 0; i < n; i++){
        e -= sortedE.front();
        if(e >= 0){
            for(int j = 0; j < n ; j++){
                if(sortedE.front() == energy.front()){
                    cout << tasks.front() << endl;
                    break;
                }
                energy.push_back(energy.front());
                energy.pop_front();
                tasks.push_back(tasks.front());
                tasks.pop_front();
            }
            indicator = 1;
        }
        else if(e < 0){
            if(indicator == 0){
                cout << "Pak Aya will do the rest" << endl;
            }
            break;
        }
        //sortedE.push_back(sortedE.front());
        sortedE.pop_front();
    }
}