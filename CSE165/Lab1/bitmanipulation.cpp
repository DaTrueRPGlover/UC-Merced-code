#include <iostream>
#include <bitset>

int getBit(int n, int index) {
    return (n >> index) & 1;
}

int setBit(int n, int index) {
    return n | (1 << index);
}

int clearBit(int n, int index) {
    return n & ~(1 << index);
}

int main() {
    int number, index;

    std::cout << "Enter a decimal number: ";
    std::cin >> number;
    std::cout << "Enter the position of the bit (0-indexed): ";
    std::cin >> index;
    
    std::bitset<sizeof(int)*8> binary(number);
    std::string binaryStr = binary.to_string();

    size_t firstOne = binaryStr.find('1');
    if (firstOne != std::string::npos) {
        std::cout << "Binary representation of " << number << " is " << binaryStr.substr(firstOne) << std::endl;
    } else {
        std::cout << "Binary representation of " << number << " is 0" << std::endl;
    }
    
    std::cout << "Get bit at index " << index << ": " << getBit(number, index) << std::endl;
    
    int numberAfterSet = setBit(number, index);
    std::bitset<sizeof(int)*8> binaryAfterSet(numberAfterSet);
    std::cout << "Binary number after setting bit at index " << index << ": " << binaryAfterSet.to_string().substr(firstOne) << std::endl;
    
    int numberAfterClear = clearBit(number, index);
    std::bitset<sizeof(int)*8> binaryAfterClear(numberAfterClear);
    std::cout << "Binary number after clearing bit at index " << index << ": " << binaryAfterClear.to_string().substr(firstOne) << std::endl;
    
    return 0;
}
