#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        int output = pow(2, 0.5 * (input - 1) * input);
        cout << "Zodiak found: " << output << " signs" << endl;
    }
    
}