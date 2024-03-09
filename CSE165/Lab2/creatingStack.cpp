#include <iostream>
#include "Stack.h"

int main() {
    Stack stack;
    stack.initialize();

    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        double num;
        std::cin >> num;
        stack.push(new double(num));
    }

    std::cout << "Numbers in the stack (in reverse order): ";
    while (void* num = stack.pop()) {
        std::cout << *((double*)num) << " ";
        delete (double*)num;
    }
    std::cout << std::endl;

    stack.cleanup();

    return 0;
}