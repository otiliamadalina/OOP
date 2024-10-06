#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <fstream>
using namespace std;

enum StudyField {
    MECHANICAL_ENGINEERING,
    SOFTWARE_ENGINEERING,
    FOOD_TECHNOLOGY,
    URBANISM_ARCHITECTURE,
    VETERINARY_MEDICINE,
    FIELD_COUNT
};

const string fieldNames[FIELD_COUNT] = {
        "Mechanical Engineering",
        "Software Engineering",
        "Food Technology",
        "Urbanism Architecture",
        "Veterinary Medicine"
};

class Student {
    string firstName, lastName, email, enrollmentDate, dateOfBirth;

public:
    bool isGraduate{false};

    void inputData();

    void printData() const;

    string getEmail() const { return email; }

    bool isGraduated() const { return isGraduate; }

    void setGraduationStatus(bool status) { isGraduate = status; }

    string facultyAbbreviationStudentBelongs;

};

class Faculty {
    Student list_of_students[50];
    int nr_of_students;


    struct FacultyInfo {
        string facultyName;
        string facultyAbbreviation;
        StudyField studyField;
    };
public:
    vector<FacultyInfo> faculties;

    Faculty() : nr_of_students(0) {}

    void createFaculty();

    void displayFaculties();

    void searchStudent() const;

    void displayAllFacultiesOfAField() ;

    void addStudentData();

    void displayStudents() const;

    void displayGraduatedStudents() const;

    void graduateStudentByEmail(const string &email);

    void checkStudentBelongsFaculty() const;

};

