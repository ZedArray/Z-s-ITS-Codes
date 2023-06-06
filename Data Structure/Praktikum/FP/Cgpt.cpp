#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        deque<int> items;
        int iAmount;
        cin >> iAmount;

        for (int j = 0; j < iAmount; j++) {
            int input;
            cin >> input;
            items.push_back(input);
        }

        bool removed = true;
        while (removed) {
            removed = false;
            for (int j = 0; j < iAmount - 1; j++) {
                if (items[j] != items[j + 1]) {
                    items.erase(items.begin() + j, items.begin() + j + 2);
                    iAmount -= 2;
                    j--;
                    removed = true;
                }
            }
        }

        cout << items.size() << endl;
    }

    return 0;
}
