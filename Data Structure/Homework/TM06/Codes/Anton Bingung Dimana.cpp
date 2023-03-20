#include <bits/stdc++.h>
using namespace std;

int main(){
    deque<string> locs;
    locs.push_back("home");
    locs.push_back("anton");
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string command;
        cin >> command;
        if(command == "goto"){
            string input;
            cin >> input;
            locs.push_back(input);
        }
        else if(command == "goback"){
            int size = locs.size();
            if(size == 0){
                cout << "cannot go back";
            }
            else{
                locs.pop_back();
            }
        }
        else if(command == "whereami"){
            int size = locs.size();
            if(size == 0){
                cout << "i am nowhere";
            }
            else{
                for(int i = 0; i < size; i++){
                    cout << locs.at(i);
                    if(i != size - 1){
                        cout << "/";
                    }
                }
            }
            cout << endl;
        }
    }
}