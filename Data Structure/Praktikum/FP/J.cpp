#include <bits/stdc++.h>
#define lli unsigned long long int
using namespace std;

int main(){
    lli n;
    cin >> n;
    for(lli i = 0; i < n; i++){
        lli input;
        cin >> input;
        //cout << input << endl;
        lli limit = (0.5*(input - 1) * input);
        //cout << limit <<endl;
        lli output = 1;
        for(lli j = 0; j < limit; j++){
            //cout << limit << endl;
            output = (2 * output) % 1000000009;
            //break;
        }
        cout << "Zodiak found: " << output << " signs" << endl;
    }
    
}