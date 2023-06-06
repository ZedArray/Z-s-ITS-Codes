#include <iostream>
#include <deque>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    deque<int> items;
    int n, iAmount, input, first, second;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> iAmount;
        for(int j = 0; j < iAmount; j++){
            cin >> input;
            items.push_back(input);
        }
        for(int j = 0; j < iAmount - 1; j++){
            first = items.front();
            second = items[1];
            if(first != second){
                items.pop_front();
                items.pop_front();
            }
            else if(first == second){
                items.push_back(items.front());
                items.pop_front();
                j--;
            }
            if(items.size() < 2){
                break;
            }
        }
        cout << items.size() << endl;
        items.clear();
    }
}