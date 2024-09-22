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


int main() {


    return 0;
}

