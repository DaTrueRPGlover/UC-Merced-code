#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

vector<vector<int>> counting_sort(vector<vector<int>> a) {
    int count = 9;
    while (count >= 0) {
        for (int i = 0; i < a.size() - 1; i++) {
            for (int j = 0; j < a.size() - i - 1; j++) {
                if (a[j][count] > a[j + 1][count]) {
                    a[j].swap(a[j + 1]);
                }
            }
        }
        count--;
    }
    return a;
}

int main(){
    int rows;
    cin >> rows;
    vector<vector<int>> full;

    for (int i = 0; i < rows; i++) {
        vector<int> curr_row;

        for (int j = 0; j <= 9; j++) {
            int data;
            cin >> data;
            curr_row.push_back(data);
        }
        full.push_back(curr_row);
    }

    full = counting_sort(full);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <= 9; j++) {
            cout << full[i][j] << ";";
        }
        cout << endl;
    }
    return 0;
}