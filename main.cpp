#include "universityDB.h"

enum FACULTY_MENU {
    ADD = 1,
    GRADUATE_A_STUDENT,
    ENROLLED_STUDENTS,
    GRADUATE_STUDENTS,
    BELONGS_TO_FACULTY,
    EXIT
};

enum GENERAL_MENU {
    CREATE_FACULTY = 1,
    SEARCH_STUDENT_AND_SHOW_FIELD,
    DISPLAY_FACULTIES,
    DISPLAY_ALL_FACULTIES_OF_A_FIELD,
    GO_BACK
};

void print_general_menu() {
    cout << "\n\tGENERAL MENU:\n";
    cout << "(" << CREATE_FACULTY << ") Create faculty\n";
    cout << "(" << SEARCH_STUDENT_AND_SHOW_FIELD << ") Search student and show field\n";
    cout << "(" << DISPLAY_FACULTIES << ") Display faculties\n";
    cout << "(" << DISPLAY_ALL_FACULTIES_OF_A_FIELD << ") Display all faculties of a field\n";
    cout << "(" << GO_BACK << ") EXIT\n";
}

void print_faculty_menu() {
    cout << "\n\tFaculty MENU:\n";
    cout << "(" << ADD << ") Add student\n";
    cout << "(" << GRADUATE_A_STUDENT << ") Graduate a student\n";
    cout << "(" << ENROLLED_STUDENTS << ") Display enrolled students\n";
    cout << "(" << GRADUATE_STUDENTS << ") Display graduated students\n";
    cout << "(" << BELONGS_TO_FACULTY << ") Check if a student belongs to a faculty\n";
    cout << "(" << EXIT << ") EXIT\n";
}

int main() {
    Faculty faculty;
    int choice, exercice;

    vector<Faculty> faculties;
    SaveManager saveManager;
    saveManager.loadData(faculties);


    while (true) {
        cout << "\n-1- General options\n";
        cout << "\t-2- Faculty options\n";
        cout << "\t\t-3- Save Data\n";
        cout << "\t\t\t-0- EXIT\n";
        cout << "Select exercise: ";
        cin >> exercice;

        if (exercice == 1) {
            do {
                print_general_menu();
                cin >> choice;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                switch (choice) {
                    case CREATE_FACULTY:
                        faculty.createFaculty();
                        break;

                    case SEARCH_STUDENT_AND_SHOW_FIELD:
                        faculty.searchStudent();
                        break;

                    case DISPLAY_FACULTIES:
                        faculty.displayFaculties();
                        break;

                    case DISPLAY_ALL_FACULTIES_OF_A_FIELD:
                        faculty.displayAllFacultiesOfAField();
                        break;

                    case GO_BACK:
                        break;

                    default:
                        cout << "Invalid choice\n";
                }
            } while (choice != GO_BACK);

        } else if (exercice == 2) {
            do {
                print_faculty_menu();
                cin >> choice;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                switch (choice) {
                    case ADD:
                        faculty.addStudentData();
                        break;

                    case GRADUATE_A_STUDENT: {
                        string email;
                        cout << "Enter email of the student to graduate: ";
                        getline(cin, email);
                        faculty.graduateStudentByEmail(email);
                        break;
                    }
                    case ENROLLED_STUDENTS:
                        faculty.displayStudents();
                        break;

                    case GRADUATE_STUDENTS:
                        faculty.displayGraduatedStudents();
                        break;

                    case BELONGS_TO_FACULTY: {
                        string facultyAbbreviation, email;
                        cout << "Enter faculty abbreviation: ";
                        getline(cin, facultyAbbreviation);
                        cout << "Enter student email: ";
                        getline(cin, email);
                        faculty.checkStudentBelongsFaculty(facultyAbbreviation, email);
                        break;
                    }
                    case EXIT:
                        break;

                    default:
                        cout << "Invalid choice\n";
                }
            } while (choice != EXIT);

        } else if (exercice == 3) {
            saveManager.saveData(faculties);
            cout << "Data saved successfully.\n";

            break;

        }else if (exercice == 0) {
            break;
        }
    }
    return 0;
}
