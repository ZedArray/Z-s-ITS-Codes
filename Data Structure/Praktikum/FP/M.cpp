#include <bits/stdc++.h>
using namespace std;

int main(){
    string input;
    stack<char> st;
    cin >> input;
    char temp;
    for(int i = 0; i < input.length(); i++){
        if(input.at(i) == '(' || input[i] == '{' || input[i] == '['){
            st.push(input.at(i));
            continue;
        }
        if(st.empty()){
            cout << "unvaldi" << endl;
            return 0;
        }
        if(input.at(i) == ')'){
            temp = st.top();
            st.pop();
            if(temp != '('){
                cout << "unvaldi" << endl;
                return 0;
            }
        }
        else if(input.at(i) == '}'){
            temp = st.top();
            st.pop();
            if(temp != '{'){
                cout << "unvaldi" << endl;
                return 0;
            }
        }
        else if(input.at(i) == ']'){
            temp = st.top();
            st.pop();
            if(temp != '['){
                cout << "unvaldi" << endl;
                return 0;
            }
        }
    }
    if(st.empty()){
        cout << "valdi" << endl;
    }
    // else{
    //     cout << "unvaldi" << endl;
    // }
}