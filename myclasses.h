#ifndef OOP_WORK_MYCLASSES_H
#define OOP_WORK_MYCLASSES_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
private:
    string firstName;
    string lastName;
    string email;
    string dateOfBirth;
    string enrollmentDate;

public:
    Student(string firstName, string lastName, string email, string dateOfBirth, string enrollmentDate);
    void displayStudentData();

    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
};

Student inputStudentData();

#endif //OOP_WORK_MYCLASSES_H
