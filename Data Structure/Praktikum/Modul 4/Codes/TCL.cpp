#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        deque<int> queue;
        list<int> list;
        priority_queue<int> end;
        // if(n == EOF){
        //     break;
        // }
        for(int i = 0; i < n; i++){
            int input;
            cin >> input;
            queue.push_back(input);
        }
        for(int i = 0; i < n; i++){
            int adder = 0;
            for(int j = i; j < n; j++){
                if(queue.at(i) <= queue.at(j)){
                    // cout << queue.at(i) << endl;
                    adder += queue.at(i);
                }
                else break;
            }
            for(int j = i - 1; j >= 0; j--){
                if(queue.at(i) <= queue.at(j)){
                    // cout << queue.at(i) << endl;
                    adder += queue.at(i);
                }
                else break;
            }
            //cout << adder << endl;
            // list.push_back(adder);
            end.push(adder);
        }
        //cout << endl;
        //list.sort();
        cout << end.top() << endl;
        // int size = end.size();
        // for(int i = 0; i < size; i++){
        //     cout << end.top() << endl;
        //     end.pop();
        // } 
    }
    // int n;
    // cin >> n;
    // for(int i = 0; i < n; i++){
    //     int input;
    //     cin >> input;
    //     queue.push_back(input);
    // }
    // for(int i = 0; i < n; i++){
    //     int adder = 0;
    //     for(int j = i; j < n; j++){
    //         if(queue.at(i) <= queue.at(j)){
    //             // cout << queue.at(i) << endl;
    //             adder += queue.at(i);
    //         }
    //         else break;
    //     }
    //     for(int j = i - 1; j >= 0; j--){
    //         if(queue.at(i) <= queue.at(j)){
    //             // cout << queue.at(i) << endl;
    //             adder += queue.at(i);
    //         }
    //         else break;
    //     }
    //     //cout << adder << endl;
    //     // list.push_back(adder);
    //     end.push(adder);
    // }
    // //cout << endl;
    // //list.sort();
    // cout << end.top() << endl;
    // // int size = end.size();
    // // for(int i = 0; i < size; i++){
    // //     cout << end.top() << endl;
    // //     end.pop();
    // // }
}