#include <bits/stdc++.h>
using namespace std;

int main(){
    list<int> mainList;
    list<int> sortedList;
    int n;
    int counter = 0;
    cin >> n;
    //int sorted[n];
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        mainList.push_back(input);
        sortedList.push_back(input);
    }
    sortedList.sort();
    int sortedArray[sortedList.size()];
    int sortSize = sortedList.size();
    for(int i = 0; i < sortSize; i++){
        sortedArray[i] = sortedList.front();
        //cout << sortedArray[i] << endl;
        sortedList.pop_front();
    }
    
    //int mainSize = mainList.size();
    for(int i = 0; i < sortSize - 1; i++){
        int tempArray[n];
        int currentSize = mainList.size();
        for(int j = 0; j < currentSize; j++){
            tempArray[j] = mainList.front();
            mainList.pop_front();
            //cout << tempArray[j] << endl;
        }
        for(int j = 0; j < currentSize; j++){
            //cout << j << endl << tempArray[j] << endl << sortedArray[j] << endl << endl;
            if(tempArray[j] == sortedArray[i]){
                //cout << "bruh" << endl;
                if(j == 0){
                    counter += tempArray[j + 1];
                }
                else if (j == currentSize-1){
                    counter += tempArray[j - 1];
                }
                else if(tempArray[j - 1] < tempArray[j + 1]){
                    counter += tempArray[j - 1];
                }
                else if(tempArray[j - 1] > tempArray[j + 1]){
                    counter += tempArray[j + 1];
                }
                else{
                    counter += tempArray[j + 1];
                }
                //cout << "counter" << counter << endl << endl;
                for(int k = 0; k < currentSize; k++){
                    if(k == j){
                        continue;
                    }
                    else{
                        //cout << tempArray[k]<< endl;
                        mainList.push_back(tempArray[k]);
                    }
                }
            }
        }
    }
    // for(int i = 0; i < n - 1; i++){
    //     if (sorted[i] == inputs[i]){
    //         sorted
    //     }
    // }
    // cout << endl;
    // for(int i = 0; i < n; i++){
    //     cout << inputs[i] << endl;
    // }
    cout << counter << endl;
}