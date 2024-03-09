#include <iostream>
using namespace std;

void MaxHeapify(int a[], int n, int i) {
    int largest = i; 
    int l = 2*i + 1; 
    int r = 2*i + 2; 
    
    if (l < n && a[l] > a[largest])
        largest = l;

    if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != i) {
        swap(a[i], a[largest]);

        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        MaxHeapify(a, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        MaxHeapify(a, i, 0);
    }
}

int main() {
    int num;
    cin >> num;
    int arr[num];
    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }

    heapSort(arr, num);

    for (int i = 0; i < num; ++i) {
        cout << arr[i] << ";";
    }
    return 0;
}