#include <iostream>
#include <string>

using std::string;

// Function Prototypes (Declarations)
string greetUser(string name);
string discountEligibility(int age, bool hasStudentID);

int main() {
    // Functions
    string userName;
    std::cout << "Please enter your name: ";
    std::cin >> userName;
    std::cout << greetUser(userName) << std::endl;

    // Logical Operations
    int age;
    std::cout << "Please enter your age: ";
    std::cin >> age;

    string hasStudentID;
    std::cout << "Do you have a student ID? ";
    std::cin >> hasStudentID;

    string message;
    if (hasStudentID == "y") {
        message = discountEligibility(age, true);
    } else if (hasStudentID == "n") {
        message = discountEligibility(age, false);
    } else {
        message = "invalid input for student ID";
    }

    std::cout << message << std::endl;

    return EXIT_SUCCESS;
}

// For all exercises, I am using kimi.ai, however, for the implemantion is zero token architecture.

// Functions
string greetUser(string name) {
    return "Good morning " + name;
}

// LOGICAL OPERATIONS
// Problem 1: Write a program that asks the user for their age and whether they have
// a student ID (y or n).
//
// Print exactly one of these messages:
//   - If the age is 65 or older -> "Senior discount applied"
//   - Otherwise, if the age is under 25 AND they have a student ID -> "Student discount applied"
//   - Otherwise -> "No discount"
//
// Requirements:
//   - Use std::cin for both inputs
//   - Use nested/combined if, else if, else statements (no switch allowed here)
//   - Handle invalid age input (e.g., a negative number) by printing "Invalid age"
string discountEligibility(int age, bool hasStudentID) {
    if (age < 0) {
        return "invalid age";
    } else if (age < 25 && hasStudentID) {
        return "student discount applied";
    } else if (age >= 65) {
        return "senior discount applied";
    } else {
        return "no discount applied";
    }
}

// SWITCH STATEMENTS


// Loops

// Arrays

// Vectors

// Maps

// Sets 

// Pointers


