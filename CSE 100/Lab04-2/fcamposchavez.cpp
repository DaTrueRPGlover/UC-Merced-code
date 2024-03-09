#include <iostream>
#include <cstdlib>
using namespace std;

int partition(int a[], int l, int h){
	int pivot = a[h];
	int i = (l - 1);

	for (int j = l; j <= h - 1; j++){
		if (a[j] <= pivot) {
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[h]);
	return (i + 1);
}

void quickSort(int a[], int l, int h){
	if (l < h) {
		int part = partition(a, l, h);
		quickSort(a, l, part - 1);
		quickSort(a, part + 1, h);
	}
}

int main(){
	int num;
	cin >> num;

	int arr[num];
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}

	quickSort(arr, 0, num - 1);
	for (int i = 0; i < num; i++) {
		cout << arr[i] << ";";
	}

	return 0;
}