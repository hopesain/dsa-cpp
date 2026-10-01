// INHERITANCE
// Problem 16: Model two kinds of employees with an inheritance hierarchy
// that reuses what they genuinely share.
//
// class Employee (base):
//   - private: name (string), employeeID (string)
//   - constructor Employee(name, employeeID)
//   - getName(), getEmployeeID() getters (const)
//   - pure virtual: virtual double calculatePay() const = 0;
//   - virtual destructor
//
// class SalariedEmployee : public Employee:
//   - private: double monthlySalary (reject <= 0 in constructor,
//     store 1.0, print "Invalid salary")
//   - constructor SalariedEmployee(name, employeeID, monthlySalary) -
//     MUST call the base constructor via a member initializer list:
//       SalariedEmployee(...) : Employee(name, employeeID) { ... }
//   - calculatePay() returns monthlySalary
//
// class HourlyEmployee : public Employee:
//   - private: double hourlyRate, double hoursWorked
//     (reject <= 0 the same way, print "Invalid value")
//   - constructor passes name/id up to the base via initializer list
//   - calculatePay() returns hourlyRate * hoursWorked
//
// In main:
//   - Create one SalariedEmployee and one HourlyEmployee
//   - Through Employee pointers, print for each: name, ID, and pay
//   - Do NOT add name or ID fields or getters to the derived classes -
//     they come from the base, use them
//
// Requirements:
//   - Base constructors called via member initializer lists, never by
//     assigning in the body
//   - No duplicated name/ID storage anywhere in the derived classes
//   - The base class is abstract