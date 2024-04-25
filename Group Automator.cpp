#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            cout << i << " " << j << endl;
            count++;
        }
    }
    cout << count << endl;
}