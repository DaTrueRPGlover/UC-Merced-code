#include <stdio.h> 
 
int main() { 
 	int x = 1, y = 2, *px, *py; 
    px = &x;
    py = &y;
 	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    printf("%d\n%d\n%p\n%p\n", x, y, &x, &y);
    printf("%p\n%p\n%d\n%d\n", px, py, *px, *py);

    for (int i = 0; i < 10; i++) {
        printf("%d ", *arr + i);
    }
    printf("\n%p\n%p\n", &arr[0], &arr);
 
 	return 0; 
}