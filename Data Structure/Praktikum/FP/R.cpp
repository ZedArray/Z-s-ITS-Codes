#include <bits/stdc++.h>
using namespace std;

int main(){
    int lim1, lim2;
    cin >> lim1 >> lim2;
    int num1 = 0, num2 = 0;
    for(int i = lim1; i > 0; i--){
        int input;
        cin >> input;
        num1 += input*pow(10, i - 1);
    }
    for(int i = lim2; i > 0; i--){
        int input;
        cin >> input;
        num2 += input*pow(10, i - 1);
    }
    cout << num1+num2 <<endl;
}