#include "universityDB.h"

void Faculty::createFaculty() {
    FacultyInfo newFaculty;

    cout << "Enter faculty name: ";
    getline(cin, newFaculty.facultyName);

    cout << "Enter faculty abbreviation: ";
    getline(cin, newFaculty.facultyAbbreviation);

    cout << "\nSelect study field:\n";
    for (int i = 0; i < FIELD_COUNT; ++i) {
        cout << i + 1 << ". " << fieldNames[i] << endl;
    }
    int fieldChoice;
    cout << "Enter choice (1-" << FIELD_COUNT << "): ";
    cin >> fieldChoice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (fieldChoice >= 1 && fieldChoice <= FIELD_COUNT) {
        newFaculty.studyField = static_cast<StudyField>(fieldChoice - 1);
        faculties.push_back(newFaculty);
        cout << "Faculty created successfully!\n";
    } else {
        cout << "Invalid choice. Faculty not created.\n";
    }
}

void Faculty::displayFaculties() {
    cout << "\n" << endl;
    for (const auto &faculty: faculties) {
        cout << "Faculty Name: " << faculty.facultyName << endl;
        cout << "Abbreviation: " << faculty.facultyAbbreviation << endl;
        cout << "Study Field: " << fieldNames[faculty.studyField] << endl;
    }
}

void Faculty::displayAllFacultiesOfAField() {
    cout << "Select study field:\n";
    for (int i = 0; i < FIELD_COUNT; ++i) {
        cout << i + 1 << ". " << fieldNames[i] << endl;
    }

    int fieldChoice;
    cout << "Enter choice (1-" << FIELD_COUNT << "): ";
    cin >> fieldChoice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (fieldChoice >= 1 && fieldChoice <= FIELD_COUNT) {
        auto selectedField = static_cast<StudyField>(fieldChoice - 1);
        cout << "Faculties in the field of " << fieldNames[selectedField] << ":\n";

        bool found = false;
        for (const auto &faculty: faculties) {
            if (faculty.studyField == selectedField) {
                cout << "Faculty Name: " << faculty.facultyName
                     << ", Abbreviation: " << faculty.facultyAbbreviation << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No faculties found for the selected field." << endl;
        }
    } else {
        cout << "Invalid choice.\n";
    }
}

void Faculty::graduateStudentByEmail(const string &email) {
    cout << "List of graduated students: " << endl;
    for (int i = 0; i < nr_of_students; i++) {
        if (list_of_students[i].getEmail() == email) {
            list_of_students[i].setGraduationStatus(true);
            cout << "Student with email " << email << " has been marked as graduated.\n";
            return;
        }
    }
    cout << "No student found with the email: " << email << ".\n";
}

void Faculty::addStudentData() {
    if (nr_of_students < 500) {
        list_of_students[nr_of_students].inputData();
        nr_of_students++;
    } else {
        cout << "Maximum number of students reached." << endl;
    }
}

void Faculty::displayStudents() const {
    string facultyAbb;
    cout << "Enter faculty abbreviation to display enrolled students: ";
    getline(cin, facultyAbb);

    cout << "List of students in faculty " << facultyAbb << ": " << endl;
    bool foundEnrolled = false;

    for (int i = 0; i < nr_of_students; i++) {

        if (!list_of_students[i].isGraduated() &&
            list_of_students[i].facultyAbbreviationStudentBelongs == facultyAbb) {
            list_of_students[i].printData();
            foundEnrolled = true;
        }
    }
    if (!foundEnrolled) {
        cout << "No enrolled students found for faculty: " << facultyAbb << "." << endl;
    }
}

void Faculty::displayGraduatedStudents() const {
    string facultyAbb;
    cout << "Enter faculty abbreviation to display graduated students: ";
    getline(cin, facultyAbb);

    cout << "List of graduated students in faculty " << facultyAbb << ": " << endl;
    bool foundGraduated = false;

    cout << endl;
    for (int i = 0; i < nr_of_students; i++) {

        if (list_of_students[i].isGraduated() &&
            list_of_students[i].facultyAbbreviationStudentBelongs == facultyAbb) {
            list_of_students[i].printData();
            foundGraduated = true;
        }
    }
    if (!foundGraduated) {
        cout << "No graduated students found for faculty " << facultyAbb << "." << endl;
    }
}

void Faculty::searchStudent() const {

    string email;
    cout << "Enter email of the student to search: ";
    getline(cin, email);

    bool found = false;
    for (int i = 0; i < nr_of_students; i++) {
        if (list_of_students[i].getEmail() == email) {
            list_of_students[i].printData();
            cout << "Faculty: ";
            for (const auto &faculty: faculties) {
                if (faculty.facultyAbbreviation == list_of_students[i].facultyAbbreviationStudentBelongs) {
                    cout << faculty.facultyName << " (" << faculty.facultyAbbreviation << ")\n";
                    break;
                }
            }
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No student found with the email: " << email << endl;
    }
}

void Faculty::checkStudentBelongsFaculty(const string& facultyAbbreviation, const string& studentEmail) {

    for (int i = 0; i < nr_of_students; i++) {
        const auto& student = list_of_students[i];
        if (student.getEmail() == studentEmail) {
            if (student.isGraduated()) {
                cout << "Student " << student.getFirstName() << " " << student.getLastName()
                          << " graduated from the " << facultyAbbreviation << "Faculty." << endl;
            } else {
                cout << "Student " << student.getFirstName() << " " << student.getLastName()
                          << " belongs to " << facultyAbbreviation << "Faculty.\n";
            }
            return;
        }
    }
    cout << "Student with email " << studentEmail << " doesnt belong to any faculty" << facultyAbbreviation << ".\n";
}

void Faculty::saveToFile(ofstream &ofs) const {
    ofs << facultyName << "," << facultyAbbreviation << endl;
    for (int i = 0; i < nr_of_students; i++) {
        list_of_students[i].saveToFile(ofs);
    }
}

void Faculty::loadFromFile(const string &line) {
    stringstream ss(line);
    getline(ss, facultyName, ',');
    getline(ss, facultyAbbreviation, ',');

}

void Faculty::addStudent(const Student& student) {
    if (nr_of_students < 500) {
        list_of_students[nr_of_students] = student;
        nr_of_students++;
    } else {
        cout << "Maximum number of students reached." << endl;
    }
}
