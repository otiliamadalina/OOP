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
        faculties.push_back(newFaculty);  // Add the new faculty to the vector
        cout << "Faculty created successfully!\n";
    } else {
        cout << "Invalid choice. Faculty not created.\n";
    }
}

void Faculty::displayFaculties() {
    cout << "\n";
    for (const auto& faculty : faculties) {
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
        for (const auto& faculty : faculties) {
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
    if (nr_of_students < 50) {
        list_of_students[nr_of_students].inputData();
        nr_of_students++;
    } else {
        cout << "Maximum number of students reached." << endl;
    }
}

void Faculty::displayStudents() const {
    string facultyAbbreviation;
    cout << "Enter faculty abbreviation to display enrolled students: ";
    getline(cin, facultyAbbreviation);

    cout << "List of students in faculty " << facultyAbbreviation << ": " << endl;
    bool foundEnrolled = false;

    for (int i = 0; i < nr_of_students; i++) {

        if (!list_of_students[i].isGraduated() &&
            list_of_students[i].facultyAbbreviationStudentBelongs == facultyAbbreviation) {
            list_of_students[i].printData();
            foundEnrolled = true;
        }
    }
    if (!foundEnrolled) {
        cout << "No enrolled students found for faculty: " << facultyAbbreviation << "." << endl;
    }
}

void Faculty::displayGraduatedStudents() const {
    string facultyAbbreviation;
    cout << "Enter faculty abbreviation to display graduated students: ";
    getline(cin, facultyAbbreviation);

    cout << "List of graduated students in faculty " << facultyAbbreviation << ": " << endl;
    bool foundGraduated = false;

    for (int i = 0; i < nr_of_students; i++) {

        if (list_of_students[i].isGraduated() &&
            list_of_students[i].facultyAbbreviationStudentBelongs == facultyAbbreviation) {
            list_of_students[i].printData();
            foundGraduated = true;
        }
    }

    if (!foundGraduated) {
        cout << "No graduated students found for faculty " << facultyAbbreviation << "." << endl;
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
            for (const auto& faculty : faculties) {
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

void Faculty::checkStudentBelongsFaculty() const {
    string facultyAbbreviation;
    string email;

    cout << "Enter faculty abbreviation: ";
    getline(cin, facultyAbbreviation);

    cout << "Enter student email: ";
    getline(cin, email);

    bool found = false;

    for (int i = 0; i < nr_of_students; i++) {
        if (list_of_students[i].getEmail() == email &&
            list_of_students[i].facultyAbbreviationStudentBelongs == facultyAbbreviation) {
            cout << "Student " << email << " belongs to faculty " << facultyAbbreviation << "." << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with email " << email << " does not belong to faculty " << facultyAbbreviation << "." << endl;
    }
}
