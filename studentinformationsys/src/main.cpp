#include <iostream>
#include <vector>
#include "functions.h"

int main() {
    std::vector<Student> students;
    int choice;

    while (true) {
        printMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
            break;
            case 2:
                removeStudent(students);
            break;
            case 3:
                printAllStudents(students);
            break;
            case 4:
                printSpecificStudent(students);
            break;
            case 5:
                changeStudentInfo(students);
            break;
            case 6:
                sortStudents(students);
            break;
            case 7:
                calculateLetterGrades(students);
            break;
            case 8:
                deleteAllStudents(students);
            break;
            case 9:
                std::cout << "Exiting program.\n";
            return 0;
            default:
                std::cout << "Invalid choice, please try again.\n";
        }
    }

    return 0;
}
