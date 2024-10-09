#include "universityDB.h"

StudyField getStudyFieldFromString(const string &fieldStr) {
    if (fieldStr == "0") return MECHANICAL_ENGINEERING;
    else if (fieldStr == "1") return SOFTWARE_ENGINEERING;
    else if (fieldStr == "2") return FOOD_TECHNOLOGY;
    else if (fieldStr == "3") return URBANISM_ARCHITECTURE;
    else if (fieldStr == "4") return VETERINARY_MEDICINE;
    else return FIELD_COUNT;
}

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

void FileManager::writeStudentsToFile() {
    vector<Student> students;
    Student student;
    student.addStudentData();
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

    for (const auto& s : students) {
        file << s.ID << '/'
             << s.facultyAbbreviation << '/'
             << s.lastName << '/'
             << s.firstName << '/'
             << s.email << '/'
             << s.enrollmentDate << '/'
             << s.dateOfBirth << '\n';
        cout << "Student has been added successfully to " << ((student.isGraduated()) ? "graduated" : "enrolled") << " students file.\n";
    }
    file.close();
}

void FileManager::readFacultiesFromFile() {

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

        faculty.displayAllFaculties();
    }
    file.close();
}

void FileManager::write_faculties_to_file() {

    string TUMfaculties = "D:\\UTM\\OOP\\laboratories_TEST\\TUMfaculties.txt";
    ofstream file(TUMfaculties, ios::app);
    if (!file) {
        cerr << "Failed to open the file!\n";
    }

    vector<Faculty> faculties;
    Faculty faculty;
    faculty.createFaculty();
    faculties.push_back(faculty);

    for (const auto& s : faculties) {
        file << s.facultyAbbreviation << '/'
             << s.facultyName << '/'
             << s.studyField << '\n';
    }
    file.close();
}

