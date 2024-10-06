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
    string facultyAbbreviationStudentBelongs;

    bool isGraduate{false};

    void inputData();

    void printData() const;

    string getEmail() const { return email; }

    string getFirstName() const { return firstName; }

    string getLastName() const { return lastName; }

    bool isGraduated() const { return isGraduate; }

    void setGraduationStatus(bool status) { isGraduate = status; }

    void saveToFile(ofstream &ofs) const;

    void loadFromFile(const string &line);

};

class Faculty {

    struct FacultyInfo {
        string facultyName;
        string facultyAbbreviation;
        StudyField studyField;
    };

public:
    vector<FacultyInfo> faculties;

    string facultyName, facultyAbbreviation;;

    Faculty() : nr_of_students(0) {}

    void createFaculty();

    void displayFaculties();

    void searchStudent() const;

    void displayAllFacultiesOfAField();

    void addStudentData();

    void displayStudents() const;

    void displayGraduatedStudents() const;

    void graduateStudentByEmail(const string &email);

    void checkStudentBelongsFaculty(const string &facultyAbbreviation, const string &email);

    void addStudent(const Student &student);

    void saveToFile(ofstream &ofs) const;

    void loadFromFile(const string &line);


    int nr_of_students;
    Student list_of_students[500];
};

class SaveManager {
public:
    static void saveData(const vector<Faculty> &faculties);

    static void loadData(vector<Faculty> &faculties);
};


