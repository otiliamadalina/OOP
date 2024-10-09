#ifndef LABORATORIES_TEST_UNIVERSITYDB_H
#define LABORATORIES_TEST_UNIVERSITYDB_H

#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

enum StudyField {
    MECHANICAL_ENGINEERING,
    SOFTWARE_ENGINEERING,
    FOOD_TECHNOLOGY,
    URBANISM_ARCHITECTURE,
    VETERINARY_MEDICINE,
    FIELD_COUNT
};


class Student {
    string firstName, lastName, email, enrollmentDate, dateOfBirth, ID;

public:
    string facultyAbbreviation;

    string getEmail() const { return email; }

    string getFirstName() const { return firstName; }

    string getLastName() const { return lastName; }

    bool isGraduate{false};
    bool isGraduated() const { return isGraduate; }

    void addStudentData();

    void displayStudentData();

    void retrieveStudentByID();

    void deleteAStudentByID();

    friend class Faculty;
    friend class FileManager;

};

class Faculty {

public:
    string facultyName, facultyAbbreviation, studyField;

    void createFaculty();

    void displayAllFaculties();

    void searchStudentByEmail();

    void displayAllFacultiesOfAField();

    void displayEnrolledStudents();

    void displayGraduatedStudents();

    void graduateAStudentByEmail();

    void checkStudentBelongsFaculty();

};

class FileManager {

public:
    //int get_nr_of_lines_from_file();

    void writeStudentsToFile();

    void readFacultiesFromFile();

    void write_faculties_to_file();

    friend class Faculty;
    friend class Student;
};





#endif //LABORATORIES_TEST_UNIVERSITYDB_H
