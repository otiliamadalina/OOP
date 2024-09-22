#include "exercices.h"
#include "manager.h"

class Book {
    int ID;
    string title, author;
    int ISBN;

public:
    Book() {
        ID = 0;
        ISBN = 0;
    }

    void inputData();

    void printData();

    int getID() const { return ID; }
};

void Book::inputData() {
    cout << "Enter ID: ";
    cin >> ID;
    cin.ignore();
    cout << "Enter title: ";
    getline(std::cin, title);
    cout << "Enter author: ";
    getline(std::cin, author);
    cout << "Enter ISBN: ";
    cin >> ISBN;
};

void Book::printData() {
    cout << "ID: " << ID << ", Title: " << title << ", Author: " << author << ", ISBN: " << ISBN << endl;
}

class Library {
    Book list_of_books[50];
    int nr_of_books;

public:
    Library() {
        nr_of_books = 0;
    }

    void addBook();

    void deleteBook();

    void printBooks();
};

void Library::addBook() {
    if (nr_of_books < 50) {
        list_of_books[nr_of_books].inputData();
        nr_of_books++;
    }
}

void Library::deleteBook() {
    int ID;
    cout << "Enter the ID of the book you want to delete: ";
    cin >> ID;
    bool found = false;

    for (int i = 0; i < nr_of_books; i++) {
        if (list_of_books[i].getID() == ID) {
            for (int j = i; j < nr_of_books - 1; j++) {
                list_of_books[j] = list_of_books[j + 1];
            }
            nr_of_books--;
            found = true;
            cout << "Book with ID " << ID << " deleted." << endl;
            break;
        }
    }
    if (!found) {
        cout << "Book with ID " << ID << " not found." << endl;
    }
}

void Library::printBooks() {
    for (int i = 0; i < nr_of_books; i++) {
        list_of_books[i].printData();
    }
}

enum MENU {
    ADD = 1,
    DELETE,
    PRINT,
    EXIT
};

void print_menu() {
    cout << "MENU:\n";
    cout << "(" << ADD << ") Add book\n";
    cout << "(" << DELETE << ") Delete book\n";
    cout << "(" << PRINT << ") Print list of books\n";
    cout << "(" << EXIT << ") EXIT\n";
}

int main() {

    Library library;
    int choice, exercice;

    while(1) {
        cout << "\n-1- Laboratory\n";
        cout << "\t-2- Incapsulation\n";
        cout << "\t\t-3- Inheritance\n";
        cout << "\t\t\t-4- Constructor\n";
        cout << "\t\t\t\t-5- Friend class\n";
        cout << "Select exercice: ";
        cin >> exercice;

        if (exercice == 1) {
            do {
                print_menu();
                cin >> choice;

                switch (choice) {
                    case ADD:
                        library.addBook();
                        break;

                    case DELETE:
                        library.deleteBook();
                        break;

                    case PRINT:
                        library.printBooks();
                        break;

                    case EXIT:
                        break;

                    default:
                        cout << "Invalid choice";
                }
            } while (choice != EXIT);

        } else if (exercice == 2){
            Teacher teacher{};
            teacher.setSalary(7000);
            cout << "Salary: " << teacher.getSalary() << " MDL\n\n\n";

        } else if (exercice == 3) {
            Manager manager("John", "Manager", "HR");
            manager.printDetails();

        } else if (exercice == 4) {
            cout << "Bicycles: \n";
            Bicycle bicycle1(1, "Road");
            Bicycle bicycle2(2, "Mountain");
            cout << bicycle1.ID << " " << bicycle1.model << " " << "\n";
            cout << bicycle2.ID << " " << bicycle2.model << " " << "\n";

        } else if (exercice == 5) {
            MyClass myclass;
            Friendly friendly;
            friendly.display(myclass);
            cout << "\n" << endl;

            myClass obj1(10);
            myOtherClass obj2(30);
            obj1.printData2();
            obj1.acces_myOtherClass(obj2);
        }
    }


    return 0;
}

