#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> arr, int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << ";";
  }
  cout << endl;
}

void insertionSort(vector<int> arr, int size) {
  for (int i = 1; i < size; i++) {
    int temp = arr[i];
    int j = i - 1;

    if (i != 1) {
        printArray(arr, i);
    }

    while (temp < arr[j] && j >= 0) {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = temp;
  }
  printArray(arr, size);
}

int main() {
    int i;
    int x;
    int y;
    vector<int> data;
    cin >> x;
    for (i = 0; i < x; i++) {
        cin >> y;
        data.push_back(y);
    }
    insertionSort(data, x);
}