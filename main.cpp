#include "universityDB.h"

enum FACULTY_MENU {
    CREATE_A_NEW_STUDENT = 1,
    GRADUATE_A_STUDENT,
    ENROLLED_STUDENTS,
    GRADUATE_STUDENTS,
    BELONGS_TO_FACULTY,
    EXIT
};

enum GENERAL_MENU {
    CREATE_FACULTY = 1,
    SEARCH_STUDENT_AND_SHOW_FIELD,
    DISPLAY_FACULTIES_FROM_FILE,
    DISPLAY_ALL_FACULTIES_OF_A_FIELD
};

enum STUDENT_MENU {
    RETRIEVE_A_STUDENT = 1,
    DELETE_A_STUDENT
};

void print_general_menu() {
    cout << "\n\tGENERAL MENU:\n";
    cout << "(" << CREATE_FACULTY << ") Create faculty\n";
    cout << "(" << SEARCH_STUDENT_AND_SHOW_FIELD << ") Search student and show field\n";
    cout << "(" << DISPLAY_FACULTIES_FROM_FILE << ") Display faculties\n";
    cout << "(" << DISPLAY_ALL_FACULTIES_OF_A_FIELD << ") Display all faculties of a field\n";
    cout << "(" << EXIT << ") EXIT\n";
}

void print_faculty_menu() {
    cout << "\n\tFaculty MENU:\n";
    cout << "(" << CREATE_A_NEW_STUDENT << ") Add student\n";
    cout << "(" << GRADUATE_A_STUDENT << ") Graduate a student\n";
    cout << "(" << ENROLLED_STUDENTS << ") Display enrolled students\n";
    cout << "(" << GRADUATE_STUDENTS << ") Display graduated students\n";
    cout << "(" << BELONGS_TO_FACULTY << ") Check if a student belongs to a faculty\n";
    cout << "(" << EXIT << ") EXIT\n";
}

void print_student_menu() {
    cout << "\n\tStudent MENU:\n";
    cout << "(" << RETRIEVE_A_STUDENT << ") Add student\n";
    cout << "(" << DELETE_A_STUDENT << ") Delete a student\n";
    cout << "(" << EXIT << ") EXIT\n";
}


int main() {
    Faculty faculty;
    FileManager fileManager;
    Student student;
    int choice, exercice;

    while (true) {
        cout << "\n1. General options\n";
        cout << "2. Faculty options\n";
        cout << "3. Student options\n";
        cout << "0. EXIT\n";
        cout << "Select exercise: ";
        cin >> exercice;

        if (exercice == 1) {
            do {
                print_general_menu();
                cin >> choice;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                switch (choice) {
                    case CREATE_FACULTY:
                        fileManager.write_faculties_to_file();
                        break;

                    case SEARCH_STUDENT_AND_SHOW_FIELD:
                        faculty.searchStudentByEmail();
                        break;

                    case DISPLAY_FACULTIES_FROM_FILE:
                        fileManager.readFacultiesFromFile();
                        break;

                    case DISPLAY_ALL_FACULTIES_OF_A_FIELD:
                        faculty.displayAllFacultiesOfAField();
                        break;

                    case EXIT:
                        break;

                    default:
                        cout << "Invalid choice\n";
                }
            } while (choice != EXIT);

        } else if (exercice == 2) {
            do {
                print_faculty_menu();
                cin >> choice;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                switch (choice) {
                    case CREATE_A_NEW_STUDENT: {
                        fileManager.writeStudentsToFile();
                        break;
                    }
                    case GRADUATE_A_STUDENT: {
                        faculty.graduateAStudentByEmail();
                        break;
                    }
                    case ENROLLED_STUDENTS:
                        faculty.displayEnrolledStudents();
                        break;

                    case GRADUATE_STUDENTS:
                        faculty.displayGraduatedStudents();
                        break;

                    case BELONGS_TO_FACULTY: {
                        faculty.checkStudentBelongsFaculty();
                        break;
                    }
                    case EXIT:
                        break;

                    default:
                        cout << "Invalid choice\n";
                }
            } while (choice != EXIT);

        } else if (exercice == 3) {
            do {
                print_student_menu();
                cin >> choice;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                switch (choice) {
                    case RETRIEVE_A_STUDENT:
                        student.retrieveStudentByID();
                        break;

                    case DELETE_A_STUDENT:
                        student.deleteAStudentByID();
                        break;

                    case EXIT:
                        break;

                    default:
                        cout << "Invalid choice\n";
                }
            } while (choice != EXIT);

        } else if (exercice == 0) {
            break;
        }
    }
    return 0;
}