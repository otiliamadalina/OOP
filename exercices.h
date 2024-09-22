#ifndef OOP_WORK_EXERCICES_H
#define OOP_WORK_EXERCICES_H

#include <iostream>
#include <string>
#include <utility>

using namespace std;

//q1---------------------------------------

class Teacher {

private:
    int salary;

public:

    void setSalary(int s) {
        salary = s;
    }

    int getSalary() const {
        return salary;
    }
};

//q2---------------------------------------

class Employee {
protected:
    string name;
    string position;

public:
    Employee(string n, string p) : name(std::move(n)), position(std::move(p)) {}

    string getName() { return name; }

    string getPosition() { return position; }

    void printDetails() {
        cout << "\nName: " << name << "\nPosition: " << position << endl;
    }
};

//q3---------------------------------------

class Bicycle {
public:
    int ID;
    string model;

    Bicycle (int x, string y);

    ~Bicycle();
};

Bicycle::Bicycle(int x, string y) {
    ID = x;
    model = y;
}

Bicycle::~Bicycle() {
    cout << "Bicycle with ID " << ID << " and model " << model << " is destroyed." << endl;
}


#endif //OOP_WORK_EXERCICES_H
