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
    deque<int> output;
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
    if(y > x){
        swap(input1, input2);
    }
    int excess = 0;
    int i1 = input1.size();
    int i2 = input2.size();
    for(int i = 0; i < i1; i++){
        if(i > i2 - 1){
            //cout << "bigger" << input1.back() + excess << endl;
            output.push_front(input1.back() + excess);
            input1.pop_back();
            excess = 0;
        }
        else{
            int input = input1.back() + input2.back() + excess;
            if(input > 9){
                input -= 10;
                excess = 1;
            }
            else{
                excess = 0;
            }
            //cout << "smaller" << input << endl;
            output.push_front(input);
            input1.pop_back();
            input2.pop_back();
        }
    }
    int size = output.size();
    for(int i = 0; i < size; i++){
        cout << output.at(i);
    }
}