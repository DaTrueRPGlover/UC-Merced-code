#include <iostream>
#include <climits>

using namespace std;

int max(int a, int b) { 
    return (a > b)? a : b; 
}
int max(int a, int b, int c) {
    return max(max(a, b), c); 
}

int maxCrossingSum(int arr[], int low, int mid, int high){
    int left_sum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; i--){
        sum = sum + arr[i];
        if (sum > left_sum) {
            left_sum = sum;
        }
    }
 
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = mid+1; i <= high; i++){
        sum = sum + arr[i];
        if (sum > right_sum)
          right_sum = sum;
    }
 
    return left_sum + right_sum;
}
 
int maxSubArraySum(int arr[], int low, int high){
    if (low == high) {
        return arr[low];
    }

    int mid = (low + high)/2;
 
    return max(maxSubArraySum(arr, low, mid),
              maxSubArraySum(arr, mid+1, high),
              maxCrossingSum(arr, low, mid, high));
}
 
int main(){
    int index;
    int data;
    cin >> index;
    int arr[index];
    for (int i = 0; i < index; i++) {
        cin >> data;
        arr[i] = data;
    }
   int max_sum = maxSubArraySum(arr, 0, index-1);
   cout << max_sum;
   return 0;
} 