#include "universityDB.h"

void SaveManager::saveData(const vector<Faculty>& faculties) {
    ofstream ofs("TUMdb.txt");
    for (const auto& faculty : faculties) {
        faculty.saveToFile(ofs);
    }
}
void SaveManager::loadData(vector<Faculty>& faculties) {
    ifstream ifs("TUMdb.txt");
    string line;
    while (getline(ifs, line)) {
        Faculty faculty;
        faculty.loadFromFile(line);
        while (getline(ifs, line) && !line.empty()) {
            Student student;
            student.loadFromFile(line);
            faculty.addStudent(student);
        }
        faculties.push_back(faculty);
    }
}
