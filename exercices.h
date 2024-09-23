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

    Bicycle(int x, string y);

    ~Bicycle();
};

Bicycle::Bicycle(int x, string y) {
    ID = x;
    model = y;
}

Bicycle::~Bicycle() {
    cout << "Bicycle with ID " << ID << " and model " << model << " is destroyed." << endl;
}

//q4 a.---------------------------------------

class MyClass {
private:
    int private_stuff;

protected:
    int protected_stuff;

public:
    MyClass() {
        private_stuff = 190;
        protected_stuff = 99;
    }

    friend class Friendly;
};

class Friendly {
public:
    void display(MyClass &t) {
        cout << "The value of Private Variable = "
             << t.private_stuff << endl;
        cout << "The value of Protected Variable = "
             << t.protected_stuff;
    }
};

//q4 b.---------------------------------------

class DataBase;

class user {

private:
    int password;

protected:
    string role;

public:
    user() {
        password = 8765432;
        role = "admin";
    }

    friend class DataBase;

    void display_db(DataBase &info_data);
};


class DataBase {

private:
    string email;

public:
    DataBase() {
        email = "user@gmail.com";
    }

     void display(user &info) {
        cout << "Password: " << info.password << endl;
         cout << "Role: " << info.role << endl;
     }

    friend class user;
};

void user::display_db(DataBase &info_data) {
    cout << "Email: " << info_data.email << endl;
}


#endif //OOP_WORK_EXERCICES_H
