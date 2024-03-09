
#include <stdio.h>
#include <stdlib.h>

int** matMult(int **a, int **b, int size) {
	// (4) Implement your matrix multiplication here. You will need to create a new matrix to store the product.
	int **matC = (int**)malloc(size * sizeof(int*));
	int i, j, k;

	for (i = 0; i < size; i++) {
		*(matC + i) = (int*)malloc(size * sizeof(int));
	}

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			*(*(matC + i) + j) = 0;
		}
	}

	for (i = 0; i < size; i++){
		for (j = 0; j < size; j++){
			for (k = 0; k < size; k++){
				*(*(matC + i) + j) +=  (* (*(a + i) + k))* (* (*(b + i) + k));
			}
		}
	}
	return matC;
}

void printArray(int **arr, int n) {
	// (2) Implement your printArray function here
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++) {
		if (i != 0) {
			printf("\n");
		}
		for (j = 0; j < n; j++) {
			printf("%d ", *(*(arr + i) + j));
		}
	}
	printf("\n");
}

int main() {
	int n = 3;
	int i = 0;
	int j = 0;
	int **matA, **matB, **matC;
	// (1) Define 2 (n x n) arrays (matrices). 
	matA = (int**)malloc(n * sizeof(int*));
	matB = (int**)malloc(n * sizeof(int*));

	for (i = 0; i < n; i++) {
		*(matA + i) = (int*)malloc(n * sizeof(int));
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			*(*(matA + i) + j) = 5;
		}
	}

	for (i = 0; i < n; i++) {
		*(matB + i) = (int*)malloc(n * sizeof(int));
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			*(*(matB + i) + j) = 2;
		}
	}

	// (3) Call printArray to print out the 2 arrays here.
	printArray(matA, n);
	printArray(matB, n);
	
	// (5) Call matMult to multiply the 2 arrays here.
	matC = matMult(matA, matB, n);
	
	// (6) Call printArray to print out resulting array here.
	printArray(matC, n);

    return 0;
}