#include <bits/stdc++.h>
using namespace std;

int main(){
    deque<int> clues;
    int n;
    int counter = 0;
    cin >> n;
    // int tempcount = 0;
    string tempstring;
    for(int i = 0; i < n; i++){
        // char clue[10];
        // cin.getline(clue, 10);
        string clue;
        cin >> clue;
        //cout << "bruh" << clue << endl;
        if (clue == "Clue"){
            // if(tempcount == 1){
            //     tempcount = 0;
            //     n++;
            //     continue;
            // }
            clues.push_back(1);
            counter++;
            //cout << "test1" << clue << endl;
            // tempcount = 0;
        }
        else if (clue == "No"){
            cin >> tempstring;
            clues.push_back(0);
            //cout << "test2" << clue << endl;
            // tempcount = 1;
        }
    }
    // int cluesize = clues.size();
    // for(int i=0; i < cluesize; i++){
    //     cout << clues.back() << endl;
    //     clues.pop_back();
    // }
    int inputs;
    cin >> inputs;
    for (int i = 0; i < inputs; i++){
        string command;
        cin >> command;
        // if (command == "them"){
        //     //tempcount = 0;
        //     inputs++;
        //     continue;
        // }
        if (command == "Out"){
            // if(tempcount == 1){
            //     tempcount = 0;
            //     inputs++;
            //     continue;
            // }
            if(clues.back() == 1){
                cout << "I'm going crazy, right?" << endl;
                counter--;
            }
            clues.pop_back();
        }
        else if(command == "Count"){
            cin >> tempstring;
            if(counter >= 5){
                cout << "He's the one that's living in my system" << endl;
            }
            else{
                cout << "They keep on asking me, \"Who is he?\"" << endl;
            }
        }
    }
}