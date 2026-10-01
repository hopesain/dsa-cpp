// ABSTRACTION
// Problem 15: Write a shape hierarchy where the base class is an INTERFACE -
// it declares WHAT shapes can do, but has no idea HOW.
//
// class Shape (abstract base):
//   - a pure virtual method: virtual double area() const = 0;
//   - a virtual destructor: virtual ~Shape() = default;
//     (required so derived objects can be safely deleted through a
//     Shape pointer - don't skip this, it bites silently later)
//   - no data members
//
// class Circle : public Shape:
//   - private double radius, set via constructor (reject radius <= 0 with
//     "Invalid radius", store 1.0)
//   - area() returns PI * radius * radius (use 3.14159)
//
// class Rectangle : public Shape:
//   - private double width, height, set via constructor (reject either <= 0
//     with "Invalid dimension", store 1.0 for the bad one)
//   - area() returns width * height
//
// In main:
//   - Try to create a Shape object directly. Watch the compiler refuse.
//     Leave that line commented out with a note about the error you saw.
//   - Create a Circle and a Rectangle via Shape pointers:
//       Shape* shapes[] = { new Circle(3.0), new Rectangle(4.0, 5.0) };
//   - Loop through the array calling area() on each - do NOT check the
//     concrete type anywhere.
//   - Print each result
//   - delete both objects through the base pointers
//
// Requirements:
//   - Shape must be abstract (pure virtual = 0)
//   - area() must be declared virtual in Shape and overridden with the
//     exact same signature in Circle and Rectangle
//   - main must never know which concrete shape it is holding - that's
//     the entire point

#include <iostream>

class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
private:
    double radius;
    static constexpr double PI = 3.14159;

public:
    Circle(double inputRadius) {
        if (inputRadius <= 0) {
            std::cout << "Invalid radius" << std::endl;
            radius = 1.0;
        } else {
            radius = inputRadius;
        }
    }

    double area() const override {
        return PI * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double rWidth, double rHeight) {
        if (rWidth <= 0) {
            std::cout << "Invalid dimension" << std::endl;
            width = 1.0;
        } else {
            width = rWidth;
        }

        if (rHeight <= 0) {
            std::cout << "Invalid dimension" << std::endl;
            height = 1.0;
        } else {
            height = rHeight;
        }
    }

    double area() const override {
        return width * height;
    }
};

int main() {
    // Shape s;

    Shape* shapes[] = { new Circle(3.0), new Rectangle(4.0, 5.0) };

    for (int i = 0; i < 2; ++i) {
        std::cout << "Area: " << shapes[i]->area() << std::endl;
    }

    delete shapes[0];
    delete shapes[1];

    return 0;
}