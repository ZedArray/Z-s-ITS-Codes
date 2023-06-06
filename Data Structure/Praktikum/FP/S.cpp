#include <bits/stdc++.h>
using namespace std;

int concat(int a, int b)
{
  
    // Convert both the integers to string
    string s1 = to_string(a);
    string s2 = to_string(b);
  
    // Concatenate both strings
    string s = s1 + s2;
  
    // Convert the concatenated string
    // to integer
    int c = stoi(s);
  
    // return the formed integer
    return c;
}

int main(){
    int n, divider;
    int counter = 0;
    int temp;
    deque<int> dq;
    deque<int> total;
    cin >> n >> divider;
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        dq.push_back(input);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            temp = 0;
            if(dq[i] != dq[j]){
                temp = concat(dq[i], dq[j]);
            }
            else{
                continue;
            }
            if(temp % divider == 0){
                counter++;
            }
        }
    }
    // for(int i = n; i > 0; i--){
    //     for(int j = i - 1; j > 0; j--){
    //         if(dq[i] != dq[j])
    //             total.push_back(concat(dq[i], dq[j]));
    //     }
    // }
    // for(int i = 0; i < total.size(); i++){
    //     if(total[i] % 11 == 0){
    //         counter++;
    //     }
    //     // cout << total[i] << endl;
    // }
    cout << counter << endl;
}