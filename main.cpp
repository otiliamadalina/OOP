#include "myclasses.h"

enum StudyField {
    MECHANICAL_ENGINEERING,
    SOFTWARE_ENGINEERING,
    FOOD_TECHNOLOGY,
    URBANISM_ARCHITECTURE,
    VETERINARY_MEDICINE
};

int main () {

    Student student = inputStudentData();
    student.displayStudentData();

    return 0;
}