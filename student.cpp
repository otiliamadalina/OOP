#include "universityDB.h"

void Student::addStudentData() {
    cout << "Enter student ID: ";
    getline(cin, ID);

    cout << "Enter faculty abbreviation: ";
    getline(cin, facultyAbbreviation);

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
}

void Student::displayStudentData() {
    cout << endl;
    cout << "\nID: " << ID
         << "\nFaculty: " << facultyAbbreviation
         << "\nFirst name: " << firstName
         << "\nLast name: " << lastName
         << "\nEmail: " << email
         << "\nEnrollment date: " << enrollmentDate
         << "\nDate of birth: " << dateOfBirth
         << endl;
}

void Student::retrieveStudentByID() {
    string uniqueID;
    cout << "Enter ID: ";
    getline(cin, uniqueID);

    string enrolledStudents = "D:\\UTM\\OOP\\laboratories_TEST\\enrolledStudents.txt";
    fstream file(enrolledStudents);
    if (!file) {
        cerr << "Failed to open the students file\n";
        return;
    }

    string line;
    bool found = false;

    while (getline(file, line)) {
        stringstream ss(line);
        Student student;

        getline(ss, student.ID, '/');
        getline(ss, student.facultyAbbreviation, '/');
        getline(ss, student.lastName, '/');
        getline(ss, student.firstName, '/');
        getline(ss, student.email, '/');
        getline(ss, student.enrollmentDate, '/');
        getline(ss, student.dateOfBirth, '\n');

        if (student.ID == uniqueID) {
            cout << "Student found: \n"
                 << "ID: " << student.ID << "\n"
                 << "Faculty: " << student.facultyAbbreviation << "\n"
                 << "Name: " << student.firstName << " " << student.lastName << "\n"
                 << "Email: " << student.email << "\n"
                 << "Enrollment Date: " << student.enrollmentDate << "\n"
                 << "Date of Birth: " << student.dateOfBirth << "\n";
            found = true;
            break;
        }
    }
    file.close();

    if (!found) {
        cout << "No student found" << endl;
    }
}

void Student::deleteAStudentByID() {
    string enrolledFilePath = "D:\\UTM\\OOP\\laboratories_TEST\\enrolledStudents.txt";
    string graduatedFilePath = "D:\\UTM\\OOP\\laboratories_TEST\\graduatedStudents.txt";
    string deleteID;

    cout << "Enter the ID: ";
    getline(cin, deleteID);

    bool foundInEnrolled = false, foundInGraduated = false;

    vector<string> enrolledStudents;
    fstream enrolledFile(enrolledFilePath);
    if (!enrolledFile) {
        cerr << "Failed to open the file enrolled st" << endl;
        return;
    }

    string line;
    while (
            getline(enrolledFile, line)) {
        stringstream ss(line);
        string currentID;
        getline(ss, currentID, '/');

        if (currentID != deleteID) {
            enrolledStudents.
                    push_back(line);
        } else {
            foundInEnrolled = true;
        }
    }
    enrolledFile.close();

    ofstream outEnrolledFile(enrolledFilePath);
    if (!outEnrolledFile) {
        cerr << "Failed to open the file enrolled st" << endl;
        return;
    }

    for (size_t i = 0; i < enrolledStudents.size(); ++i) {
        outEnrolledFile << enrolledStudents[i];
        if (i < enrolledStudents.size() - 1) {
            outEnrolledFile << '\n';
        }
    }
    outEnrolledFile.close();

    vector<string> graduatedStudents;
    fstream graduatedFile(graduatedFilePath);
    if (!graduatedFile) {
        cerr << "Failed to open the file" << endl;
        return;
    }

    while (getline(graduatedFile, line)) {
        stringstream ss(line);
        string currentID;
        getline(ss, currentID, '/');

        if (currentID != deleteID) {
            graduatedStudents.
                    push_back(line);
        } else {
            foundInGraduated = true;
        }
    }
    graduatedFile.close();

    ofstream outGraduatedFile(graduatedFilePath);
    if (!outGraduatedFile) {
        cerr << "Failed to open the file graduated st" << endl;
        return;
    }

    for (size_t i = 0; i < graduatedStudents.size(); ++i) {
        outGraduatedFile << graduatedStudents[i];
        if (i < graduatedStudents.size() - 1) {
            outGraduatedFile << '\n';
        }
    }
    outGraduatedFile.close();

    if (foundInEnrolled) {
        cout << "Student with ID " << deleteID << " has been deleted successfully from enrolled students!\n";
    } else if (foundInGraduated) {
        cout << "Student with ID " << deleteID << " has been deleted successfully from graduated students!\n";
    } else {
        cout << "No student found" << "\n";
    }
}