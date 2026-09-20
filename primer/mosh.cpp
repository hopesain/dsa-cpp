#include <iostream>
#include <cmath>

double circleArea(double radius) {
    const double PI = 3.14;
    return PI * std::pow(radius, 2);
}

int main() {
    double radius;
    std::cout << "Please enter the value of a radius: ";
    std::cin >> radius;
    
    double area = circleArea(radius);
    std::cout << "The area of a circle is: " << area;

    return 0;
}