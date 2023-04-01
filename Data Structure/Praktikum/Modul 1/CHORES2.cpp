#include <bits/stdc++.h>
using namespace std;

int main(){
    int e, n;
    deque<int> energy;
    list<int> sortedE;
    deque<string> tasks;
    deque<string> bout;
    deque<string> pout;
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
            int size = energy.size();
            for(int j = 0; j < size ; j++){
                if(sortedE.front() == energy.at(j)){
                    //cout << tasks.at(j) << endl;
                    bout.push_back(tasks.at(j));
                    energy.erase(energy.begin() + j);
                    tasks.erase(tasks.begin() + j);
                    // for(int k = 0; k < energy.size(); k++){
                    //     cout << "EG: " << energy.at(k) << endl;
                    //     cout << "TS: " << tasks.at(k) << endl;
                    // }
                    // cout << "but" << bout.at(i) << endl;
                    sortedE.pop_front();
                    break;
                }
                // energy.push_back(energy.front());
                // energy.pop_front();
                // tasks.push_back(tasks.front());
                // tasks.pop_front();
            }
        }
        else if(e < 0){
            int size = energy.size();
            for(int j = 0; j < size ; j++){
                if(sortedE.front() == energy.at(j)){
                    pout.push_back(tasks.at(j));
                    energy.erase(energy.begin() + j);
                    tasks.erase(tasks.begin() + j);
                    sortedE.pop_front();
                    break;
                }
            }
        }
    }
    int bsize = bout.size();
    int psize = pout.size();
    if(bsize > 0){
        cout << "Bu Aya will do " << bsize << " jobs." << endl;
        for(int i = 0; i < bsize; i++){
            cout << bout.at(i) << endl;
        }
        cout << "Then, Pak Aya will do " << psize << " jobs." << endl;
        for(int i = 0; i < psize; i++){
            cout << pout.at(i) << endl;
        }
    }
    else{
        cout << "Pak Aya will do " << psize << " jobs." << endl;
        for(int i = 0; i < psize; i++){
            cout << pout.at(i) << endl;
        }
    }
}