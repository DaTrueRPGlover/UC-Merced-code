#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int size; // Variable to record size of original array arr
int evenCount = 0, oddCount = 0; // Variables to record sizes of new arrays arr_even and arr_odd
int input = 0;
int *arr; // Dynamically allocated original array with #elements = size
int *arr_even;  // Dynamically allocated array with #elements = #even elements in arr (evenCount)
int *arr_odd;   // Dynamically allocated array with #elements = #odd elements in arr (oddCount)
char *str1 = "Original array's contents: ";
char *str2 = "Contents of new array containing even elements from original: ";
char *str3 = "Contents of new array containing odd elements from original: ";

// DO NOT change the definition of the printArr function when it comes to 
// adding/removing/modifying the function parameters, or changing its return 
// type. 
void printArr(int *a, int size, char *prompt){
    if (size <= 0) {
        printf("%sempty\n", prompt);
        //printf("%sempty\n", str2);
        //printf("%sempty\n", str3);
    }
    if (size > 0) {
        printf("%s", prompt);
        for (int i = 0; i < size; i++) {
            printf("%d ", *(a + i));
        }
        printf("\n");
    }
}

// DO NOT change the definition of the arrCopy function when it comes to 
// adding/removing/modifying the function parameters, or changing its return 
// type. 
void arrCopy(){
    int evenn = 0;
    int oddn = 0;
    for (int i = 0; i < size; i++) {
        //arr + i - 1;
        if (*(arr + i) % 2 == 0) {
            *(arr_even + evenn) = *(arr + i);
            evenn++;
            //*arr_even = *arr;
            //arr_even++;
            //arr_even + i - 1;
            //*arr_even = *arr;
            //arr_even - i + 1;            
        }
        else if (*arr % 2 == 1) {
            *(arr_odd + oddn) = *(arr + i);
            oddn++;
            //*arr_odd = *arr;
            //arr_odd++;
            //arr_odd + i - 1;
            //*arr_odd = *arr;
            //arr_odd - i + 1;
        }

        //arr - i + 1;
        
    }
}

int main(){
    printf("Enter the size of array you wish to create: ");
    scanf("%d", &size);

    // Dynamically allocate memory for arr (of appropriate size)
    if (size > 0) { 
        arr = malloc(size * sizeof(int)); 
    }

    // Ask user to input content of arr and compute evenCount and oddCount
    for (int i = 1; i < size + 1; i++) {
        arr = arr + i - 1;
        printf("Enter array element #%d: ", i);
        scanf("%d", &input);
        if (input % 2 == 0) {
            evenCount++;
            *arr = input;
            //arr++;
        }
        else if (input % 2 == 1) {
            oddCount++;
            *arr = input;
            //arr++;
        }
        arr = arr - i + 1;
    }

    // Dynamically allocate memory for arr_even and arr_odd (of appropriate size)
    arr_even = (int*)malloc(evenCount * sizeof(int));
    arr_odd = (int*)malloc(oddCount * sizeof(int));
/*************** YOU MUST NOT MAKE CHANGES BEYOND THIS LINE! ***********/
	
	// Print original array
    printArr(arr, size, str1);

	/// Copy even elements of arr into arr_even and odd elements into arr_odd
    arrCopy();

    // Print new array containing even elements from arr
    printArr(arr_even, evenCount, str2);

    // Print new array containing odd elements from arr
    printArr(arr_odd, oddCount, str3);

    printf("\n");

    return 0;
}