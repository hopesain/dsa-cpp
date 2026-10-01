// ENCAPSULATION
// Problem 14: Write a Student class where a Student object is ALWAYS in a
// valid state - invalid data can never get in from outside.
//
// class Student:
//   - private members ONLY: name (string), studentID (string), grade (int)
//   - constructor(name, studentID, grade) - if grade is outside 0-100,
//     print "Invalid grade" and store 0 instead
//   - setGrade(int) - only changes the grade if it is within 0-100;
//     otherwise print "Grade must be between 0 and 100" and leave the
//     current grade UNCHANGED
//   - getName(), getStudentID(), getGrade() - all RETURN their values
//     (do not print inside them)
//   - isPassing() - returns true if grade >= 50
//
// In main:
//   - Create a Student with valid data, print all fields via getters
//   - Attempt setGrade(-5) and setGrade(101), printing the grade after
//     each attempt to prove it was rejected
//   - Set a valid grade, then print whether the student is passing
//
// Requirements:
//   - Not one public data member - all access through methods
//   - Getters return values; main does the printing
//   - The class itself must be impossible to put into an invalid state
//     from outside (try to break it from main - you should fail)

#include <iostream>
#include <string>

using std::string;

class Student{
    private:
    string name;
    string studentID;
    int grade;

    public:
    Student(string studentName, string sStudentID, int studentGrade) {
        name = studentName;
        studentID = sStudentID;

        if (studentGrade < 0 || studentGrade > 100) {
            std::cout << "Invalid grade" << std::endl;
            grade = 0;
            return;
        }

        grade = studentGrade;

    }

    void setGrade(int studentGrade) {
        if (studentGrade < 0 || studentGrade > 100) {
            std::cout << "Grade must be between 0 and 100" << std::endl;
            return;
        }
        grade = studentGrade;
    }

    string getName() {
        return name;
    }

    string getStudentID() {
        return studentID;
    }

    int getGrade() {
        return grade;
    }

    bool isPassing() {
        if (grade < 50) {
            return false;
        }

        return true;
    }

};

int main() {
    Student firstStudent("hope", "one", 50);
    std::cout << "Student Name: " << firstStudent.getName() << std::endl;
    std::cout << "Student ID: " << firstStudent.getStudentID() << std::endl;
    std::cout << "Student Grade: " << firstStudent.getGrade() << std::endl;

    firstStudent.setGrade(-4);
    firstStudent.setGrade(101);

    firstStudent.setGrade(80);

    string passingStatus = firstStudent.isPassing() ? "Yes" : "No";
    std::cout << "Is student passing? " << passingStatus << std::endl;

    std::cout << "Student Name: " << firstStudent.getName() << std::endl;
    std::cout << "Student ID: " << firstStudent.getStudentID() << std::endl;
    std::cout << "Student Grade: " << firstStudent.getGrade() << std::endl;

    return EXIT_SUCCESS;
}