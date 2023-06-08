#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int nAmount = 0;
        int biggest = -100;
        cin >> nAmount;
        int arr[nAmount];
        int numberlist;
        for(int i = 0; i < nAmount; i++){
            int input;
            cin >> input;
            if(input > biggest){
                biggest = input;
            }
            arr[i] = input;
        }
    }
}