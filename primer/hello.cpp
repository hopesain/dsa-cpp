#include <iostream>
#include <string>

int main() {
    int a = 1;
    int b = 2;

    int c = a;

    a = b;
    b = c;
    
    std::string userName = "Hope Sain";
    userName = "aa";
    std::cout << b;
    std::cout << userName;
    
    // Character In
    std::cout << "Enter a value: ";
    int value;
    std::cin >> value;
    std::cout << "You entered: " << value;
    return 0;
}

void printValue() {
    const double PI = 3.14;
    std::cout << "PI Value: " << PI;
}

int increment(int initialValue) {
    int value = initialValue++;
    return value;
}