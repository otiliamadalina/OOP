#ifndef OOP_WORK_MANAGER_H
#define OOP_WORK_MANAGER_H

#include "exercices.h"

//q2---------------------------------------

class Manager:
        public Employee {
private:
    string department;

public:
    Manager(string n, string p, string d):
            Employee(n, p), department(d) {}

    string getDepartment() {return department;}
    void setDepartment(string newDepartment) { department = newDepartment;}
    void printDetails() {
        Employee::printDetails();
        cout << "Department: " << department << endl;
    }


};

#endif //OOP_WORK_MANAGER_H
