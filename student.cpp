#include "myclasses.h"
#include <sstream>
#include <utility>
#include <fstream>

Student::Student(string firstName, string lastName, string email, string dateOfBirth, string enrollmentDate) {
    this->firstName = std::move(firstName);
    this->lastName = std::move(lastName);
    this->email = std::move(email);
    this->dateOfBirth = std::move(dateOfBirth);
    this->enrollmentDate = std::move(enrollmentDate);
}

void Student::displayStudentData() {
    cout << "Student: " << firstName << " " << lastName << "\nEmail: " << email
         << "\nDate of Birth: " << dateOfBirth << "\nEnrollment Date: " << enrollmentDate << endl;
}

Student inputStudentData() {
    string inputLine;
    cout << "name/surname/email/date-of-birth/enrollment-date" << endl;

    getline(cin, inputLine);

    stringstream ss(inputLine);
    string firstName, lastName, email, dateOfBirth, enrollmentDate;

    if (getline(ss, firstName, '/') && getline(ss, lastName, '/') &&
        getline(ss, email, '/') && getline(ss, dateOfBirth, '/') &&
        getline(ss, enrollmentDate, '/')) {

        return {firstName, lastName, email, dateOfBirth, enrollmentDate};
    } else {
        cerr << "Try again." << endl;
        return {"", "", "", "", ""};
    }
}

void logOperation(const string& operation) {
    ofstream logFile("operations.log", ios::app);
    if (logFile.is_open()) {
        logFile << operation << endl;
        logFile.close();
    }
}

/*
void studentManagement::displayAllStudents() {
    for(int i = 0; i < nr_of_students; i++){
        list_of_students[i].displayStudentData();
    }
}
 */
