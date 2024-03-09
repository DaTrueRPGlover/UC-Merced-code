#include <iostream>

void createArray(int s, int*& d){
    int num1 = 0;
    int num2 = 1;
    int tempnum = 0;
    if (s <= 0){
        std::cout << "ERROR: size of array < 1" << std::endl;
    }
    else {
        d = new int[s];
        for (int i=0; i<s; i++){
            if(i == 0) {
                d[i] = num1;
            }

            if(i == 1) {
                d[i] = num2;
            }

            else {
                tempnum = num1 + num2;
                num1 = num2;
                num2 = tempnum;
                d[i] = tempnum;
            }
        }
    }
}

void printArray(int s, int* d){

    if (d == nullptr) {
        std::cout << "Invalid array." << std::endl << std::endl;
    } 
    else {
        for (int j = 0; j < s; j++) {
            std::cout << d[j] << " ";
        }
        std::cout << std::endl << std::endl;
        delete[] d;
    }
}