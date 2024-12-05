#include "functions.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <limits>  // For numeric_limits

// Function to print the main menu
void printMenu() {
    std::cout << "Student Information System\n";
    std::cout << "1. Add Student\n";
    std::cout << "2. Remove Student\n";
    std::cout << "3. Print All Students\n";
    std::cout << "4. Print Specific Student\n";
    std::cout << "5. Change Student Info\n";
    std::cout << "6. Sort Students\n";
    std::cout << "7. Calculate Letter Grades\n";
    std::cout << "8. Delete All Students\n";
    std::cout << "9. Exit\n";
    std::cout << "Enter your choice: ";
}

// Function to add a student
void addStudent(std::vector<Student>& students) {
    try {
        Student newStudent;
        std::cout << "Enter student name: ";
        std::cin.ignore();
        std::getline(std::cin, newStudent.name);

        std::cout << "Enter student age: ";
        std::cin >> newStudent.age;

        // Validate age
        if (newStudent.age < 0) {
            throw std::invalid_argument("Age cannot be negative.");
        }

        std::cout << "Enter student grade: ";
        std::cin >> newStudent.grade;

        // Validate grade
        if (!validateGrade(newStudent.grade)) {
            throw std::invalid_argument("Grade must be between 0 and 100.");
        }

        students.push_back(newStudent);
        std::cout << "Student added successfully!\n";
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
        std::cin.clear(); // Clear any input errors
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

// Function to remove a student
void removeStudent(std::vector<Student>& students) {
    try {
        std::string name;
        std::cout << "Enter the name of the student to remove: ";
        std::cin.ignore();
        std::getline(std::cin, name);

        auto it = std::remove_if(students.begin(), students.end(), [&name](const Student& student) {
            return student.name == name;
        });

        if (it != students.end()) {
            students.erase(it, students.end());
            std::cout << "Student removed successfully!\n";
        } else {
            throw std::runtime_error("Student not found.");
        }
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}

// Function to print all students
void printAllStudents(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "No students available.\n";
        return;
    }

    std::cout << std::setw(20) << "Name" << std::setw(10) << "Age" << std::setw(10) << "Grade\n";
    for (const auto& student : students) {
        std::cout << std::setw(20) << student.name << std::setw(10) << student.age << std::setw(10) << student.grade << "\n";
    }
}

// Function to print a specific student's data
void printSpecificStudent(const std::vector<Student>& students) {
    try {
        std::string name;
        std::cout << "Enter the name of the student: ";
        std::cin.ignore();
        std::getline(std::cin, name);

        auto it = std::find_if(students.begin(), students.end(), [&name](const Student& student) {
            return student.name == name;
        });

        if (it != students.end()) {
            std::cout << "Name: " << it->name << "\n";
            std::cout << "Age: " << it->age << "\n";
            std::cout << "Grade: " << it->grade << "\n";
        } else {
            throw std::runtime_error("Student not found.");
        }
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}

// Function to change student info
void changeStudentInfo(std::vector<Student>& students) {
    try {
        std::string name;
        std::cout << "Enter the name of the student to change info: ";
        std::cin.ignore();
        std::getline(std::cin, name);

        auto it = std::find_if(students.begin(), students.end(), [&name](const Student& student) {
            return student.name == name;
        });

        if (it != students.end()) {
            std::cout << "Enter new age: ";
            std::cin >> it->age;

            // Validate age
            if (it->age < 0) {
                throw std::invalid_argument("Age cannot be negative.");
            }

            std::cout << "Enter new grade: ";
            std::cin >> it->grade;

            // Validate grade
            if (!validateGrade(it->grade)) {
                throw std::invalid_argument("Grade must be between 0 and 100.");
            }

            std::cout << "Student info updated successfully!\n";
        } else {
            throw std::runtime_error("Student not found.");
        }
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}

// Function to sort students by grade (ascending)
void sortStudents(std::vector<Student>& students) {
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.grade < b.grade;
    });
    std::cout << "Students sorted by grade.\n";
}

// Function to calculate letter grades based on the grade
void calculateLetterGrades(const std::vector<Student>& students) {
    for (const auto& student : students) {
        char gradeLetter;
        if (student.grade >= 90) gradeLetter = 'A';
        else if (student.grade >= 80) gradeLetter = 'B';
        else if (student.grade >= 70) gradeLetter = 'C';
        else if (student.grade >= 60) gradeLetter = 'D';
        else gradeLetter = 'F';

        std::cout << student.name << " - " << gradeLetter << "\n";
    }
}

// Function to delete all students
void deleteAllStudents(std::vector<Student>& students) {
    students.clear();
    std::cout << "All students have been deleted.\n";
}

// Validate grade input (between 0 and 100)
bool validateGrade(double grade) {
    return grade >= 0 && grade <= 100;
}

// Validate age input
bool validateAge(int age) {
    return age >= 0;
}
