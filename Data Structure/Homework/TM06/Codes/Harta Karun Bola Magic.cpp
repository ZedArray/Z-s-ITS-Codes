#include <bits/stdc++.h>
using namespace std;

int main(){
    deque<int> dq;
    int n;
    int counter = 0; 
    cin >> n;
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        dq.push_back(input);
        int size = dq.size();
        for(int j = 0; j < size - 1; j++){
            if(counter == dq.at(j) - 1){
                for(int k = 0; k <= counter; k++){
                    dq.pop_back();
                }
                counter = 0;
            }
            if(dq.at(j) == dq.at(j + 1)){
                counter++;
            }
            else if(dq.at(j) != dq.at(j + 1)){
                counter = 0;
            }
        }
        size = dq.size();
        cout << size << endl;
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){

    //     }
    //     // if(i > 0){
    //     //     if(currentCheck == input){
    //     //         counter++;
    //     //     }
    //     //     else if(currentCheck != input){
    //     //         counter = 0;
    //     //     }
    //     //     if(counter == currentCheck - 1){
    //     //         for(int j = 0; j <= counter; j++){
    //     //             dq.pop_back();
    //     //         }
    //     //         counter = 0;
    //     //     }
    //     // }
    //     // if(i > 0){
    //     //     cout << "counter: " << counter << "||" << input << " " << dq.at(i - 1) << endl;
    //     //     if(input == dq.at(i - 1)){
    //     //         counter++;
    //     //     }
    //     //     else if(counter == dq.at(i - 1) - 1){
    //     //         for(int j = 0; j < dq.at(i - 1); j++){
    //     //             dq.pop_back();
    //     //         }
    //     //         counter = 0;
    //     //     }
    //     //     else{
    //     //         counter = 0;
    //     //     }
    //     // }
    //     currentCheck = input;
    //     int size = dq.size();
    //     cout << size << endl;
    // }
}