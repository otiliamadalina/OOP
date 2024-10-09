#ifndef LABORATORIES_TEST_UNIVERSITYDB_H
#define LABORATORIES_TEST_UNIVERSITYDB_H

#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <fstream>
#include <sstream>
#include <ctime>
#include <chrono>
#include <iomanip>

using namespace std;

class OperationLogger {
public:
    virtual void log(const string& message) = 0;
    virtual ~OperationLogger() = default;

    static string getCurrentTime();
};


class ConsoleLogger : public OperationLogger {
public:
    void log(const string& message) override {
        cout << "[" << getCurrentTime() << "]: " << message << endl;
    }
};

class FileLogger : public OperationLogger {
private:
    string LoggingSystem;
public:
    FileLogger(const string& file) : LoggingSystem(file) {}

    void log(const string& message) override {
        ofstream outFile(LoggingSystem, ios::app);
        if (outFile.is_open()) {
            outFile << "[" << getCurrentTime() << "]: " << message << endl;
            outFile.close();
        } else {
            cerr << "Failed to open log file" << endl;
        }
    }
};

class Student {
    string firstName, lastName, email, enrollmentDate, dateOfBirth, ID;

public:
    Student() = default;

    string facultyAbbreviation;

    string getEmail() const { return email; }
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }

    bool isGraduate{false};
    bool isGraduated() const { return isGraduate; }

    void addStudentData(OperationLogger* logger);
    void displayStudentData(OperationLogger* logger);
    void retrieveStudentByID(OperationLogger* logger);
    void deleteAStudentByID(OperationLogger* logger);

    friend class Faculty;
    friend class FileManager;

};

class Faculty {

public:
    string facultyName, facultyAbbreviation, studyField;

    Faculty()  = default;

    void createFaculty(OperationLogger* logger);
    void displayAllFaculties(OperationLogger* logger);
    void searchStudentByEmail(OperationLogger* logger);
    void displayAllFacultiesOfAField(OperationLogger* logger);
    void displayEnrolledStudents(OperationLogger* logger);
    void displayGraduatedStudents(OperationLogger* logger);
    void graduateAStudentByEmail(OperationLogger* logger);
    void checkStudentBelongsFaculty(OperationLogger* logger);

};

class FileManager {

public:
    //int get_nr_of_lines_from_file();

    void writeStudentsToFile(OperationLogger* logger);
    void readFacultiesFromFile(OperationLogger* logger);
    void write_faculties_to_file(OperationLogger* logger);

    friend class Faculty;
    friend class Student;
};

#endif //LABORATORIES_TEST_UNIVERSITYDB_H
