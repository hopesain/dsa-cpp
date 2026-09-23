#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <map>
#include <set>

using std::string;
using std::array;
using std::vector;
using std::map;
using std::set;

// Function Prototypes (Declarations)
string greetUser(string name);
string discountEligibility(int age, bool hasStudentID);

void displayMenu();
string selectItemFromMenu(int number);

void fizzBuzz(int maxValue);

// ARRAYS
int validateScore(int score);
array<int, 5> enterScores();
void displayTestScores(array<int, 5> testScores);
double findArrayAverageScore(array<int, 5> testScores);
int findArrayLowestScore(array<int, 5> testScores);
int findArrayHighestScore(array<int, 5> testScores);

// VECTORS
vector<string> addItems();
void displayItems(vector<string> items);

// MAPS
map<string, int> enterWords();
void displayWords(map<string, int> words);

int main() {
    // // Functions
    // string userName;
    // std::cout << "Please enter your name: ";
    // std::cin >> userName;
    // std::cout << greetUser(userName) << std::endl;

    // // Logical Operations
    // int age;
    // std::cout << "Please enter your age: ";
    // std::cin >> age;

    // string hasStudentID;
    // std::cout << "Do you have a student ID? ";
    // std::cin >> hasStudentID;

    // string message;
    // if (hasStudentID == "y") {
    //     message = discountEligibility(age, true);
    // } else if (hasStudentID == "n") {
    //     message = discountEligibility(age, false);
    // } else {
    //     message = "invalid input for student ID";
    // }

    // std::cout << message << std::endl;

    // // Switch Statement
    // displayMenu();
    // int selectedItem;
    // std::cout << "Please select an item from the displayed menu: ";
    // std::cin >> selectedItem;
    // message = selectItemFromMenu(selectedItem);
    // std::cout << message << std::endl;

    // // LOOPS
    // int maxValue;
    // std::cout << "Please enter the maximum value: ";
    // std::cin >> maxValue;
    // fizzBuzz(maxValue);

    // ARRAYS
    array<int, 5> testScores = enterScores();

    displayTestScores(testScores);

    double average = findArrayAverageScore(testScores);
    std::cout << "Average Score: " << average << std::endl;

    double lowestScore = findArrayLowestScore(testScores);
    std::cout << "Lowest Score: " << lowestScore << std::endl;
    
    double highestScore = findArrayHighestScore(testScores);
    std::cout << "Highest Score: " << highestScore << std::endl;

    // VECTORS
    vector<string> items = addItems();
    displayItems(items);

    // MAPS
    map<string, int> words = enterWords();
    displayWords(words);

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
// Problem 2: Display a menu to the user:
//   1. Greet
//   2. Farewell
//   3. Repeat name
//   4. Quit
//
// The user enters a number (1-4). Use a switch statement to:
//   - 1 -> print "Hello!"
//   - 2 -> print "Goodbye!"
//   - 3 -> ask the user for their name first, then print "Nice to meet you, <name>!"
//   - 4 -> print "Exiting..."
//   - Any other number -> print "Invalid choice"
//
// Requirements:
//   - Use a switch with case, break, and a default case
//   - For case 3, the name input must be read inside that case block
//   - Don't use if/else for the menu selection itself
void displayMenu() {
    std::cout << "1. Greet" << std::endl;
    std::cout << "2. Farewell" << std::endl;
    std::cout << "3. Repeat name" << std::endl;
    std::cout << "4. Quit" << std::endl;
}

string selectItemFromMenu(int number) {
    string message;
    string name;
    switch (number) {
        case 1:
            message = "Hello!";
            break;
        case 2:
            message = "Goodbye!";
            break;
        case 3:
            std::cout << "Please enter your name: ";
            std::cin >> name;
            message = "Nice to meet you, " + name + "!";
            break;
        case 4:
            message = "Exiting...";
            break;
        default:
            message = "Invalid choice";
            break;
    }

    return message;
}

// LOOPS
// Problem 3: Write a program that asks the user for a positive integer n.
//
// Part A (for loop): FizzBuzz. Print all numbers from 1 to n, each on its
//   own line, with these rules:
//   - If the number is a multiple of both 3 AND 5, print "FizzBuzz"
//   - Otherwise, if it is a multiple of 3, print "Fizz"
//   - Otherwise, if it is a multiple of 5, print "Buzz"
//   - Otherwise, print the number itself
//   Example for n = 5:
//     1
//     2
//     Fizz
//     4
//     Buzz
//
// Part B (while loop): Then count down from n to 1 on a single line,
//   separated by spaces, e.g. "5 4 3 2 1".
//
// Requirements:
//   - Part A must use a for loop, Part B must use a while loop
//   - If n is less than 1, print "Invalid number" and run neither loop

void fizzBuzz(int maxValue) {
    if (maxValue < 1) {
        std::cout << "invalid number" << std::endl;
        return;
    }

    int number = 1;

    for (; number <= maxValue; number++) {
        if (number % 3 == 0 && number % 5 == 0) {
            std::cout << "FizzBuzz" << std::endl;
        } else if (number % 3 == 0) {
            std::cout << "Fizz" << std::endl;
        } else if (number % 5 == 0) {
            std::cout << "Buzz" << std::endl;
        } else {
            std::cout << number << std::endl;
        }
    }

    number = maxValue;
    while (number >= 1) {
        std::cout << number << std::endl;
        number--;
    }
}

// ARRAYS
// Problem 4: Write a program that asks the user for exactly 5 test scores
// (integers between 0 and 100), stores them in a fixed-size array, and then
// prints a report:
//
//   - Each score on its own line, numbered: "1. 78"
//   - The average as "Average: 81.2"
//   - The highest score as "Highest: 95"
//   - The lowest score as "Lowest: 60"
//
// Requirements:
//   - Must use a fixed-size array (e.g. int scores[5];) - no vectors
//   - Must use loops to fill the array and compute the results, no unrolling
//   - If a score is outside 0-100, print "Invalid score" and ask again for
//     that same position (the array must still end up with 5 valid scores)
array<int, 5> enterScores() {
    array<int, 5> testScores;

    for (size_t i = 0; i < testScores.size(); ++i) {
        int score;
        std::cout << "Enter score #" << (i + 1) << ": ";
        std::cin >> score;
        testScores[i] = validateScore(score);
    }

    return testScores;
}

int validateScore(int score) {
    while (score < 0 || score > 100) {
        std::cout << "Score cannot be less than 0 or greater than 100" << std::endl;
        std::cout << "Re-enter the score: ";
        std::cin >> score;
    }

    return score;
}

void displayTestScores(array<int, 5> testScores) {
    int index = 1;
    for(const int score:testScores) {
        std::cout << index << ". " << score << std::endl;
        index++;
    }
}

double findArrayAverageScore(array<int, 5> testScores) {
    double total = 0;

    for (const int score:testScores) {
        total += score;
    }

    return total / testScores.size();
}

int findArrayLowestScore(array<int, 5> testScores) {
    int lowestScore = testScores[0];

    for (const int score:testScores) {
        if (score < lowestScore) {
            lowestScore = score;
        }
    }

    return lowestScore;
}

int findArrayHighestScore(array<int, 5> testScores) {
    int highestScore = testScores[0];

    for (const int score:testScores) {
        if (score > highestScore) {
            highestScore = score;
        }
    }

    return highestScore;
}

// VECTORS
// Problem 5: Write a program that lets the user build a shopping list.
//
// - Repeatedly ask the user to enter an item name
// - Add each item to a std::vector<string>
// - When the user enters "done", stop asking
// - Then print the list as a numbered list:
//     1. apples
//     2. bread
//     3. milk
// - Finally, print the total: "Total items: 3"
//
// Requirements:
//   - Must use std::vector<string> and push_back()
//   - Must use a loop to print the numbered list
//   - If the user enters "done" as the very first input, print "List is empty"
//     instead of the numbered list
//   - No arrays allowed
vector<string> addItems() {
    vector<string> items;
    string addedItem;

    std::cout << "Add Items: ";
    std::cin >> addedItem;

    while (addedItem != "done") {
        items.push_back(addedItem);
        
        std::cout << "Add More Items: ";
        std::cin >> addedItem;
    }

    return items;
}

void displayItems(vector<string> items) {
    if (items.size() == 0) {
        std::cout << "List is empty" << std::endl;
        return;
    }

    size_t i = 0;
    for (const auto& item : items) {
        i = i + 1;
        std::cout << i << ". " << item << std::endl;
    }
}

// MAPS
// Problem 6: Write a program that counts how many times each word appears
// in a list of words entered by the user.
//
// - Repeatedly ask the user to enter a word
// - When the user enters "done", stop asking
// - Then print each word followed by its count, alphabetically ordered:
//     apple: 2
//     banana: 1
//     mango: 3
//
// Requirements:
//   - Must use std::map<string, int>
//   - Must use a loop to print the results
//   - If no words were entered (user typed "done" immediately), print
//     "No words entered"
map<string, int> enterWords() {
    string word;
    map<string, int> words;

    std::cout << "enter a word: ";
    std::cin >> word;

    while (word != "done") {
        if (words.count(word) > 0) {
            words[word] = words[word] + 1;
        } else {
            words[word] = 1;
        }

        std::cout << "enter a word: ";
        std::cin >> word;
    }

    return words;
}

void displayWords(map<string, int> words) {
    if (words.size() == 0 ) {
        std::cout << "No words entered" << std::endl;
        return;
    }
    
    for (const auto& word : words) {
        std::cout << word.first << ": " << word.second << std::endl;
    }

}


// SETS
// Problem 7: Write a program that builds a list of unique student IDs.
//
// - Repeatedly ask the user to enter a student ID (an integer)
// - When the user enters -1, stop asking
// - Then print the unique IDs in ascending order, one per line
// - If a duplicate ID is entered, do NOT add it again (and the final
//   output must contain each ID exactly once)
//
// Requirements:
//   - Must use std::set<int>
//   - Must NOT check for duplicates manually with loops - that's what the
//     set is for
//   - If no IDs were entered (user entered -1 immediately), print "No IDs entered"
void displayStudentIDs() {

}

// References

// Pointers

// Structures, Union & Enums


