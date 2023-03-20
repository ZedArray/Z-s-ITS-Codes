#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int indicator = 0;
        int input;
        cin >> input;
        while(input >= 15){
            if(input % 15 == 0){
                indicator = 1;
                break;
            }
            else if(input % 11 == 0){
                indicator = 1;
                break;
            }
            else{
                input -= 11;
            }
        }
        if(indicator == 1){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}