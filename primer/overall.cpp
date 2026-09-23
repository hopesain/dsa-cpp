// Create a function that takes in a name of the user then appends it to an array.

#include <iostream>
#include <string>

using std::string;

string addPatient(string patientName) {
    string message = "";

    if (patientName.length() == 0) {
        message = "failed to add a patient, the patientName cannot be empty";
        return message;
    }

    if (patientName.length() <= 2) {
        message = "failed to add patient: '" + patientName + "' name is too short, it has to be more than 2 characters ";
        return message;
    }

    return "patient added successfully";
}

int main() {
    string addPatientStatus = addPatient("Xi");

    std::cout << addPatientStatus << std::endl;
    
    return EXIT_SUCCESS;
}
