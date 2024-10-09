#include "universityDB.h"

void Student::inputData() {

    cout << "Enter faculty abbreviation: ";
    getline(cin, facultyAbbreviationStudentBelongs);

    cout << "Enter first name: ";
    getline(cin, firstName);

    cout << "Enter last name: ";
    getline(cin, lastName);

    cout << "Enter email: ";
    getline(cin, email);

    cout << "Enter enrollment date: ";
    getline(cin, enrollmentDate);

    cout << "Enter date of birth: ";
    getline(cin, dateOfBirth);

    string gradResponse;
    cout << "Is graduated? yes/no: ";
    getline(cin, gradResponse);

    isGraduate = (gradResponse == "yes");
    cout << "\nStudent added successfully!" << endl;
}

void Student::printData() const {
    cout << "Faculty: " << facultyAbbreviationStudentBelongs
         << "\nFirst name: " << firstName
         << "\nLast name: " << lastName
         << "\nEmail: " << email
         << "\nEnrollment date: " << enrollmentDate
         << "\nDate of birth: " << dateOfBirth
         << endl;
}

void Student::saveToFile(ofstream& ofs) const {
    ofs << facultyAbbreviationStudentBelongs << ","
        << firstName << ","
        << lastName << ","
        << email << ","
        << enrollmentDate << ","
        << dateOfBirth << ","
        << (isGraduate ? "yes" : "no") << endl;
}

void Student::loadFromFile(const string& line) {
    stringstream ss(line);
    getline(ss, facultyAbbreviationStudentBelongs, ',');
    getline(ss, firstName, ',');
    getline(ss, lastName, ',');
    getline(ss, email, ',');
    getline(ss, enrollmentDate, ',');
    getline(ss, dateOfBirth, ',');

    string gradResponse;
    getline(ss, gradResponse, ',');
    isGraduate = (gradResponse == "yes");
}

