#include "universityDB.h"

/*
int FileManager::get_nr_of_lines_from_file() {

    string TUMdb = "D:\\UTM\\OOP\\laboratories_TEST\\TUMdb.txt";
    fstream file(TUMdb);
    if (!file) {
        cerr << "Failed to open the file!\n";
        return -1;
    }

    int lines = 0;
    string line;
    while (getline(file, line)) {
        lines++;
    }

    return lines;
}
*/

void FileManager::writeStudentsToFile(OperationLogger *logger) {
    vector<Student> students;
    Student student;
    student.addStudentData(logger);
    students.push_back(student);

    string filePath;
    if (student.isGraduated()) {
        filePath = "D:\\UTM\\OOP\\laboratories_TEST\\graduatedStudents.txt";
    } else {
        filePath = "D:\\UTM\\OOP\\laboratories_TEST\\enrolledStudents.txt";
    }

    ofstream file(filePath, ios::app);
    if (!file) {
        cerr << "Failed to open the file: " << filePath << "!\n";
        return;
    }

    if (file.tellp() != 0) {
        file << '\n';
    }

    for (const auto &s: students) {
        file << s.ID << '/'
             << s.facultyAbbreviation << '/'
             << s.lastName << '/'
             << s.firstName << '/'
             << s.email << '/'
             << s.enrollmentDate << '/'
             << s.dateOfBirth << '\n';
        cout << "Student has been added successfully to " << ((student.isGraduated()) ? "graduated" : "enrolled")
             << " students file.\n";
    }
    file.close();
    logger->log("Student added: " + student.getFirstName() +
                " to " + ((student.isGraduated()) ? "graduated" : "enrolled") +
                " students file.");
}

void FileManager::readFacultiesFromFile(OperationLogger *logger) {

    string TUMfaculties = "D:\\UTM\\OOP\\laboratories_TEST\\TUMfaculties.txt";
    fstream file(TUMfaculties);
    if (!file) {
        cerr << "Failed to open the file!\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Faculty faculty;

        getline(ss, faculty.facultyAbbreviation, '/');
        getline(ss, faculty.facultyName, '/');
        getline(ss, faculty.studyField, '/');

        faculty.displayAllFaculties(logger);
    }
    file.close();

    logger->log("Faculties were read from the file.");
}

void FileManager::write_faculties_to_file(OperationLogger *logger) {

    string TUMfaculties = "D:\\UTM\\OOP\\laboratories_TEST\\TUMfaculties.txt";
    ofstream file(TUMfaculties, ios::app);
    if (!file) {
        cerr << "Failed to open the file!\n";
    }

    vector<Faculty> faculties;
    Faculty faculty;
    faculty.createFaculty(logger);
    faculties.push_back(faculty);

    for (const auto &s: faculties) {
        file << s.facultyAbbreviation << '/'
             << s.facultyName << '/'
             << s.studyField << '\n';
    }
    file.close();

    logger->log("Faculty added: " + faculty.facultyName +
                " with abbreviation: " + faculty.facultyAbbreviation);
}

string OperationLogger::getCurrentTime() {
    auto now = chrono::system_clock::now();
    time_t end_time = chrono::system_clock::to_time_t(now);
    string timeString = ctime(&end_time);

    if (!timeString.empty() && timeString.back() == '\n') {
        timeString.pop_back();
    }
    return timeString;
};