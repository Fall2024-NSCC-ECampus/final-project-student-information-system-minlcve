#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <vector>

// Student structure to store student data
struct Student {
    std::string name;
    int age;
    double grade;
};


void printMenu();
void addStudent(std::vector<Student>& students);
void removeStudent(std::vector<Student>& students);
void printAllStudents(const std::vector<Student>& students);
void printSpecificStudent(const std::vector<Student>& students);
void changeStudentInfo(std::vector<Student>& students);
void sortStudents(std::vector<Student>& students);
void calculateLetterGrades(const std::vector<Student>& students);
void deleteAllStudents(std::vector<Student>& students);
bool validateGrade(double grade);
bool validateAge(int age);

#endif // FUNCTIONS_H
