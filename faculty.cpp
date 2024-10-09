#include "universityDB.h"

void Faculty::createFaculty(OperationLogger* logger) {

    cout << "Enter faculty name: ";
    getline(cin, facultyName);

    cout << "Enter faculty abbreviation: ";
    getline(cin, facultyAbbreviation);

    cout << "Enter study field:";
    getline(cin, studyField);

    cout << "\nFaculty created successfully!" << endl;

    logger->log("Faculty created: " + facultyName);

}

void Faculty::displayAllFaculties(OperationLogger* logger) {

    cout << "\nFaculty Name: " << facultyName;
    cout << "\nAbbreviation: " << facultyAbbreviation;
    cout << "\nStudy Field: " << studyField << endl;

}

void Faculty::displayAllFacultiesOfAField(OperationLogger* logger) {
    string searchField;

    cout << "Enter the study field: ";
    getline(cin, searchField);

    cout << "\nFaculties for the field " << searchField << "\":\n";

    string TUMfaculties = "D:\\UTM\\OOP\\laboratories_TEST\\TUMfaculties.txt";
    fstream file(TUMfaculties);
    if (!file) {
        cerr << "Failed to open the file!\n";
        return;
    }

    string line;
    bool found = false;

    while (getline(file, line)) {
        stringstream ss(line);
        Faculty faculty;

        getline(ss, faculty.facultyAbbreviation, '/');
        getline(ss, faculty.facultyName, '/');
        getline(ss, faculty.studyField, '/');

        if (faculty.studyField == searchField) {
            faculty.displayAllFaculties(logger);
            found = true;
        }
    }

    if (!found) {
        cout << "No faculties found.\n";
    }
    file.close();

    logger->log("Searched faculties for field: " + searchField);
}

void Faculty::graduateAStudentByEmail(OperationLogger* logger) {
    string email;
    cout << "Enter the email: ";
    getline(cin, email);

    string enrolledStudents = "D:\\UTM\\OOP\\laboratories_TEST\\enrolledStudents.txt";
    string graduatedStudents ="D:\\UTM\\OOP\\laboratories_TEST\\graduatedStudents.txt";
    fstream file(enrolledStudents);
    if (!file) {
        cerr << "Failed to open the file enrolled st" << "\n";
        return;
    }

    string line;
    bool found = false;

    vector<Student> students;
    Student graduatedStudent;

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

        if (student.getEmail() == email) {
            graduatedStudent = student;
            found = true;
            cout << "Student graduated successfully!" << endl;

            logger->log("Graduated student: " + graduatedStudent.getFirstName() + " " + graduatedStudent.getLastName());

        } else {
            students.push_back(student);
        }
    }
    file.close();

    if (file.tellp() != 0) {
        file << '\n\n';
    }

    ofstream outFile(enrolledStudents);
    if (!outFile) {
        cerr << "Failed to open the file enrolled st" << "\n";
        return;
    }

    for (size_t i = 0; i < students.size(); ++i) {
        const auto& student = students[i];
        outFile << student.ID << '/'
                << student.facultyAbbreviation << '/'
                << student.lastName << '/'
                << student.firstName << '/'
                << student.email << '/'
                << student.enrollmentDate << '/'
                << student.dateOfBirth;

        if (i < students.size() - 1) {
            outFile << '\n';
        }
    }

    outFile.close();

    if (found) {
        ofstream gradFile(graduatedStudents, ios::app);
        if (!gradFile) {
            cerr << "Failed to open the file graduated st" << "\n";
            return;
        }

        if (file.tellp() != 0) {
            file << '\n';
        }

        gradFile << graduatedStudent.ID << '/'
                 << graduatedStudent.facultyAbbreviation << '/'
                 << graduatedStudent.lastName << '/'
                 << graduatedStudent.firstName << '/'
                 << graduatedStudent.email << '/'
                 << graduatedStudent.enrollmentDate << '/'
                 << graduatedStudent.dateOfBirth << '\n';

        gradFile.close();

    } else {
        cout << "No student found" << endl;
    }
}

void Faculty::displayEnrolledStudents(OperationLogger* logger) {
    string facultyAbb;
    cout << "Enter faculty abbreviation ";
    getline(cin, facultyAbb);

    cout << "List of enrolled students in faculty " << facultyAbb << ": " << endl;
    cout << "\n";

    string enrolledStudenets = "D:\\UTM\\OOP\\laboratories_TEST\\enrolledStudents.txt";
    fstream file(enrolledStudenets);

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
        getline(ss, student.dateOfBirth, '/');

        if (student.facultyAbbreviation == facultyAbb) {
            cout << student.getFirstName() << " " << student.getLastName() << " (" << student.email << ")\n";
            found = true;
        }
    }
    logger->log("Displayed enrolled students for faculty: " + facultyAbb);
}

void Faculty::displayGraduatedStudents(OperationLogger* logger){
    cout << "\nEnter the faculty abbreviation: ";
    string facultyAbb;
    getline(cin, facultyAbb);

    cout << "\nList of Graduated Students from " << facultyAbb << ":\n";

    string graduatedStudents = "D:\\UTM\\OOP\\laboratories_TEST\\graduatedStudents.txt";
    fstream file(graduatedStudents);
    if (!file) {
        cerr << "Failed to open the file!\n";
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
        getline(ss, student.dateOfBirth, '/');
        string graduationStatus;
        getline(ss, graduationStatus, '/');

        if (student.facultyAbbreviation == facultyAbb) {
            cout << student.getFirstName() << " " << student.getLastName() << " (" << student.email << ")\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No graduated students found" << endl;
    }
    file.close();

    logger->log("Displayed graduated students for faculty: " + facultyAbb);
}

void Faculty::searchStudentByEmail(OperationLogger* logger) {
    string email;
    cout << "Enter the email: ";
    getline(cin, email);

    string enrolledStudents = "D:\\UTM\\OOP\\laboratories_TEST\\enrolledStudents.txt";
    fstream file(enrolledStudents);
    if (!file) {
        cerr << "Failed to open the file!\n";
        return;
    }

    cout << "Enrolled students:";

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
        getline(ss, student.dateOfBirth, '/');

        if (student.getEmail() == email) {
            student.displayStudentData(logger);
            found = true;
            break;
        }
    }
    file.close();

    if (!found) {
        string graduatedStudents = "D:\\UTM\\OOP\\laboratories_TEST\\graduatedStudents.txt";
        fstream gradFile(graduatedStudents);
        if (!gradFile) {
            cerr << "Failed to open the file!" << endl;
            return;
        }

        while (getline(gradFile, line)) {
            stringstream ss(line);
            Student student;

            getline(ss, student.ID, '/');
            getline(ss, student.facultyAbbreviation, '/');
            getline(ss, student.lastName, '/');
            getline(ss, student.firstName, '/');
            getline(ss, student.email, '/');
            getline(ss, student.enrollmentDate, '/');
            getline(ss, student.dateOfBirth, '/');

            if (student.getEmail() == email) {
                cout << "Graduated student:";
                student.displayStudentData(logger);
                found = true;
                break;
            }
        }
        gradFile.close();
    }
    if (!found) {
        cout << "No student found!" << endl;
    }
    logger->log("Searched for student by email: " + email);
}

void Faculty::checkStudentBelongsFaculty(OperationLogger* logger) {
    string email, facultyAbb;
    cout << "Enter the faculty abbreviation: ";
    getline(cin, facultyAbb);

    cout << "Enter the email: ";
    getline(cin, email);

    string enrolledStudents = "D:\\UTM\\OOP\\laboratories_TEST\\enrolledStudents.txt";
    fstream file(enrolledStudents);
    if (!file) {
        cerr << "Failed to open the file!\n";
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
        getline(ss, student.dateOfBirth, '/');

        if (student.getEmail() == email && student.facultyAbbreviation == facultyAbb) {
            student.displayStudentData(logger);
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No student found" << endl;
    }
    logger->log("Checked if student belongs to faculty: " + facultyAbb + ", email: " + email);
}