# Student Information System

## Overview

This is a simple C++ program that manages student information. You can add, remove, display, and sort students, as well as calculate their grades.

## Files

- `main.cpp`: Contains the main function and program flow.
- `functions.h`: Header file with function declarations.
- `functions.cpp`: Function definitions for managing student data.
- `students.txt`: Text file to store student information.

## Features

- Add a student.
- Remove a student.
- Display all students.
- Display a specific student.
- Sort students by name or grade.
- Calculate letter grades.

## How to Run

1. Clone or download the project.
2. Open the terminal and navigate to the project folder.
3. Create a build folder:
   ```
   mkdir build
   cd build
   ```
4. Run CMake:
   ```
   cmake ..
   ```
5. Build the project:
   ```
   cmake --build .
   ```
6. Run the program:
   ```
   ./StudentInformationSystem
   ```

## `students.txt` Format

Each line contains:
```
Name Age Grade
```
Example:
```
John 20 85.5
Jane 22 90.0
```

## Error Handling

- If `students.txt` cannot be opened, an error message will appear.
- Invalid student data will be skipped.
- Incorrect input formats will result in error messages.
