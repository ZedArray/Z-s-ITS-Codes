// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     int x, y;
//     cin >> x;
//     cin >> y;
//     int num1 = 0;
//     int num2 = 0;
//     for(int i = 0; i < x; i++){
//         int input;
//         cin >> input;
//         num1 += input * pow(10, x - i - 1);
//         cout << num1 << endl;
//     }
//     for(int i = 0; i < y; i++){
//         int input;
//         cin >> input;
//         num2 += input * pow(10, y - i - 1);
//         cout << num2 << endl;
//     }
//     int result = num1 + num2;
//     cout << result << endl;
// }

#include <bits/stdc++.h>
using namespace std;
int main(){
    deque<int> input1;
    deque<int> input2;
    int x, y;
    cin >> x;
    cin >> y;
    for(int i = 0; i < x; i++){
        int input;
        cin >> input;
        input1.push_back(input);
    }
    for(int i = 0; i < y; i++){
        int input;
        cin >> input;
        input2.push_back(input);
    }
    
}