#include <iostream>
#include <string>

using std::string;

// OOP BASICS - CLASSES, OBJECTS, METHODS, ACCESS MODIFIERS, STATIC
// Problem 13: Write a BankAccount class and a small demo program in main.
//
// The BankAccount class must have:
//   - A private std::string owner
//   - A private double balance
//   - A private static int totalAccounts (shared by ALL accounts)
//   - A constructor taking (owner, openingBalance) - if openingBalance is
//     negative, print "Opening balance cannot be negative" and set it to 0
//   - deposit(double amount) - reject amounts <= 0 with "Invalid amount";
//     otherwise add and print "New balance: X"
//   - withdraw(double amount) - reject amounts <= 0 with "Invalid amount";
//     reject amounts > balance with "Insufficient funds"; otherwise subtract
//     and print "New balance: X"
//   - getBalance() and getOwner() getters
//   - A static method getTotalAccounts() returning the static counter
//   - The constructor increments totalAccounts; there is no destructor needed
//
// In main:
//   - Create at least two BankAccount objects with different owners
//   - Perform some deposits and withdrawals on each (including at least one
//     invalid deposit, one overdraft attempt, and one negative opening balance)
//   - Print each owner's final balance
//   - Print "Total accounts: N" using the static method
//
// Requirements:
//   - main must NEVER touch .balance or .owner directly - only via methods
//   - The static counter must be defined and work across all objects
//   - Class declaration in this file is fine for now; splitting into .h/.cpp
//     comes with the pillars phase
class BankAccount {
    private:
    double balance{0.0};
    string owner;

    static int totalCounts;

    public:
    BankAccount(string ownerName, double openingBalance) {
        owner = ownerName;
        totalCounts++;

        if (openingBalance < 0) {
            std::cout << "Opening balance cannot be negative" << std::endl;
            balance = 0;
            return;
        }

        balance = openingBalance;
    }

    void getBalance() {
        std::cout << "Account balance for " << owner << " is $" << balance << std::endl;
    }

    void getOwner() {
        std::cout << "Owner: " << owner << std::endl;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            std::cout << "Invalid amount" << std::endl;
            return;
        }

        balance += amount;
        std::cout << "You have successfully deposited $" << amount << " to your account. Your new balance is $" << balance << std::endl;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            std::cout << "Invalid amount" << std::endl;
            return;
        }

        if (amount > balance) {
            std::cout << "Insufficient balance" << std::endl;
            return;
        }

        balance -= amount;
        std::cout << "Your successfully withdrawn $" << amount << " from your account. Your new balance is $" << balance << std::endl;
    
    }

    static int getTotalCounts() {
        return totalCounts;
    }

};

int BankAccount::totalCounts = 0;

int main() {
    std::cout << "Hello to the Object Oriented Design in C++" << std::endl;

    BankAccount firstAccount("dennis", -1);
    firstAccount.deposit(1000);
    firstAccount.getBalance();
    firstAccount.withdraw(7000);
    firstAccount.getOwner();

    std::cout << "------------------------------------------------------" << std::endl;

    BankAccount secondAccount("hope", 1000);
    secondAccount.deposit(1000);
    secondAccount.getBalance();
    secondAccount.withdraw(7000);
    secondAccount.getOwner();

    std::cout << "------------------------------------------------------" << std::endl;

    BankAccount thirdAccount("mary", 500);
    thirdAccount.deposit(1000);
    thirdAccount.getBalance();
    thirdAccount.withdraw(7000);
    thirdAccount.getOwner();

    std::cout << "------------------------------------------------------" << std::endl;

    BankAccount forthAccount("sandra", 7000);
    forthAccount.deposit(1000);
    forthAccount.getBalance();
    forthAccount.withdraw(7000);
    forthAccount.getOwner();

    std::cout << "------------------------------------------------------" << std::endl;

    BankAccount fifthAccount("trevor", 300);
    fifthAccount.deposit(1000);
    fifthAccount.getBalance();
    fifthAccount.withdraw(7000);
    fifthAccount.getOwner();

    std::cout << "------------------------------------------------------" << std::endl;

    std::cout << "Total Counts: " << BankAccount::getTotalCounts() << std::endl;

    return EXIT_SUCCESS;
}