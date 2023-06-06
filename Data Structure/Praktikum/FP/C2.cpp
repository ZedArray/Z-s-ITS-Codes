    #include <iostream>
    #include <deque>
    using namespace std;

    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        deque<int> items;
        int n, iAmount, input, first, second, counter = 0;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> iAmount;
            for(int j = 0; j < iAmount; j++){
                cin >> input;
                items.push_back(input);
            }
            for(int j = 0; ; j++){
                for(int k = 0; k < items.size(); k++){
                    cout << items[k] << " ";
                }
                cout << endl;
                for(int k = 0; k < iAmount - 1; k++){
                    //cout << k << endl;
                    //cout << "Deletor" << endl;
                    if(items[k] != items [k+1]){
                        //cout << k << endl;
                        //cout << "deleted" << endl;
                        items.erase(items.begin() + k);
                        items.erase(items.begin() + k);
                        iAmount -= 2;
                        k--;
                    }
                    // cout << "damage" << endl;
                    // for(int k = 0; k < items.size(); k++){
                    //     cout << items[k] << " ";
                    // }
                    // cout << endl;
                    // cout << "amount" << iAmount << endl;
                }
                
                // if(items.size() >= 2){
                //     j = 0;
                // }
                    //cout << endl;
                    //cout << "amount" << iAmount << endl;
                if (items.size() < 2){
                    break;
                }
                /* first = items.front();
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
                } */
            }
            cout << items.size() << endl;
            items.clear();
        }
    }