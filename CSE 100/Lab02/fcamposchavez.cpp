#include<iostream>
#include<vector>
using namespace std;

void MSParts(vector<int>& arr, int start, int mid, int end) {
	vector<int> temp;

	int i, j;
	i = start;
	j = mid + 1;

	while (i <= mid && j <= end) {

		if (arr[i] <= arr[j]) {
			temp.push_back(arr[i]);
			++i;
		}
		else {
			temp.push_back(arr[j]);
			++j;
		}

	}

	while (i <= mid) {
		temp.push_back(arr[i]);
		++i;
	}

	while (j <= end) {
		temp.push_back(arr[j]);
		++j;
	}

	for (int i = start; i <= end; ++i)
		arr[i] = temp[i - start];

}

void MS(vector<int>& arr, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		MS(arr, start, mid);
		MS(arr, mid + 1, end);
		MSParts(arr, start, mid, end);
	}
}

int main() {
	int limit;
	vector<int> arr;
	cin >> limit;
	arr = vector<int>(limit);
	for (int i = 0; i < limit; ++i) {
		cin >> arr[i];
	}

	MS(arr, 0, limit - 1);

	for (int i = 0; i < limit; ++i) {
		cout << arr[i] << ';';
	}

}