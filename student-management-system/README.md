# Student Management System

A menu-driven Student Management System built in C that demonstrates the use of structures, arrays, functions, loops, and input validation.

The application allows users to manage student records directly from the terminal. Student information is stored in memory using an array of structures, making this project a practical introduction to data management in C.

---

# Features

### Add Student

* Add a new student record
* Store student ID, name, and marks
* Prevent duplicate student IDs
* Validate marks before storing them

### Display Students

* Display all student records currently stored in the system
* Show ID, name, and marks for each student

### Search Student

* Search for a student using their unique ID
* Display student information if found
* Show an error message if the student does not exist

### Delete Student

* Delete a student record using their ID
* Automatically shift remaining records to maintain array continuity

### Input Validation

* Prevent duplicate student IDs
* Restrict marks to the range of 0-100
* Limit the maximum number of students to 100

---

# Technologies Used

* C Programming Language
* GCC Compiler
* Standard C Libraries

  * `stdio.h`
  * `string.h`

---

# Concepts Practiced

This project was built to strengthen understanding of core C programming concepts:

## Structures

Student information is stored using a structure:

```c id="c3hpl7"
typedef struct student_management {
    int id;
    char name[15];
    int marks;
} student;
```

This groups related student data into a single record.

---

## Arrays of Structures

Student records are stored in an array:

```c id="f1tb5g"
student students[100];
```

This allows the program to manage multiple students efficiently.

---

## Functions

The program is divided into multiple functions:

* `add()`
* `display()`
* `search()`
* `delete()`
* `showMenu()`

This improves readability, maintainability, and code organization.

---

## Input Validation

The system validates user input to prevent:

* Invalid marks
* Duplicate IDs
* Database overflow

---

## Searching

The search feature uses a linear search algorithm to locate students by ID.

Time Complexity:

```text id="1a3n2i"
O(n)
```

---

## Deletion

Deleting a student requires shifting all elements after the deleted record one position to the left.

Example:

Before deletion:

```text id="q5ctc4"
[101] [102] [103] [104]
```

Delete student 102:

```text id="0at0d9"
[101] [103] [104]
```

---

# Project Structure

```text id="wtj1qm"
student-management-system/
├── student_management.c
└── README.md
```

---

# How to Compile

Using GCC:

```bash id="qnvxev"
gcc student_management -o student_management
```

---

# How to Run

Linux / macOS:

```bash id="um0vko"
./student_management
```

Windows:

```bash id="u7mmbs"
student_management.exe
```

---

# Program Menu

```text id="nmkmgt"
1. Add student
2. Display all students
3. Search Student
4. Delete Student
0. Exit
```

---

# Sample Execution

```text id="p4j0yz"
1. Add student
Choose operation: 1

Enter student id: 101
Enter student name: Alice
Enter student marks: 90

Student added
```

Display students:

```text id="9v6lf4"
Id: 101
Name: Alice
Marks: 90
```

Search student:

```text id="2zzaj8"
Enter student id: 101

Id: 101
Name: Alice
Marks: 90
```

Delete student:

```text id="6fwf3j"
Enter student id you want to delete: 101

Student deleted
```

---

# Current Limitations

* Data is not permanently stored
* Records are lost when the program exits
* Maximum capacity is limited to 100 students
* Student names are limited to 14 characters

---

# Future Improvements

Planned features include:

* Update student information
* Sort students by marks
* Calculate average marks
* Find highest scoring student
* File handling using:

  * `fopen()`
  * `fprintf()`
  * `fscanf()`
* Automatic data loading on startup
* Dynamic memory allocation using pointers
* Linked-list based implementation

---

# Learning Outcomes

Through this project, I practiced:

* Problem decomposition
* Menu-driven application design
* Data organization using structures
* Input validation techniques
* Searching and deletion algorithms
* Working with strings in C
* Building larger programs using multiple functions

---

# Author

**Shahid**

Built as part of my C programming learning journey.
