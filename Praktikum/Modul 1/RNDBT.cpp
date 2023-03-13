#include <bits/stdc++.h>
using namespace std;

int main(){
    deque<int> chamber;
    deque<int> out;
    for(int i = 0; i < 6 ; i++){
        int input;
        cin >> input;
        chamber.push_back(input);
    }
    for(int i = 0; ; i++){
        int command;
        cin >> command;
        if(command == 0){
            chamber.push_back(chamber.front());
            chamber.pop_front();
        }
        else if(command == -1){
            break;
        }
        else if(command == 1){
            int input;
            cin >> input;
            for(int j = 0; j < 2 ; j++){
                chamber.push_back(chamber.front());
                chamber.pop_front();
            }
            out.push_back(chamber.front());
            chamber.pop_front();
            for(int j = 0; j < 2 ; j++){
                chamber.push_front(chamber.back());
                chamber.pop_back();
            }
            chamber.push_back(input);
        }
    }
    if(out.size() > 0){
        cout << "Cars left the Roundabout: ";
        int size = out.size();
        for(int i = 0; i < size; i++){
            cout << out.front() << " ";
            out.pop_front();
        }
    }
    else{
        cout << "No Cars left the Roundabout" << endl;
    }
    //this is just a test for github stuff
}