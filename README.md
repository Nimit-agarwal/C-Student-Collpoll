# Cpp-Student-Collpoll

In the provided C++ program, the classes LinkedListStack and LinkedListQueue are defined to create stack and queue data structures using linked lists. These classes are not explicitly called within the code as standalone functions but are intended to be used as part of the program's data structure implementation.
The actual usage of these classes within the program can be found in the following functions:
* 		LinkedListStack is used in the entry_menu() function for managing a stack of student records. The specific operations that involve the stack are write_student(), display_all(), display_sp(n), modify_student(n), and delete_student(n).
* 		LinkedListQueue is used in the class_result() function for displaying all student records. The class_result() function uses the queue data structure to sequentially display student records in a first-in, first-out (FIFO) manner.
So, while the classes themselves are not explicitly called as functions, their functionality is integrated into the entry_menu() and class_result() functions to manage student records in a stack and queue, respectively.

# Student Report Card Project

#Introduction

The Student Report Card Project is a program written in C++ that allows users to create, display, search, modify, and delete student records. It provides a user-friendly interface for managing student information such as roll number, name, marks in different subjects, percentage, and grade.
#Key Concepts

The program utilizes several key concepts in C++ programming, including:
* Structures: The student structure is used to store information about each student, such as roll number, name, marks in different subjects, percentage, and grade.
* Linked List: The program uses linked lists to implement both a stack and a queue. The Node structure represents a node in the linked list, and the LinkedListStack and LinkedListQueue classes provide the necessary operations for pushing, popping, enqueueing, and dequeuing elements.
* File Handling: The program uses file handling to store and retrieve student records. The fstream class is used to open, read, and write to a file named "student.dat".
Code Structure
The code is structured into several functions and classes to perform different operations. Here is an overview of the main components:
* struct student: Represents a student and stores their information.
* struct Node: Represents a node in the linked list.
* class LinkedListStack: Implements a stack using a linked list.
* class LinkedListQueue: Implements a queue using a linked list.
* void write_student(): Prompts the user to enter details of a student and writes the record to the file.
* void display_all(): Displays all student records stored in the file.
* void display_sp(int n): Displays the record of a specific student based on their roll number.
* void modify_student(int n): Modifies the record of a specific student based on their roll number.
* void delete_student(int n): Deletes the record of a specific student based on their roll number.
* void class_result(): Displays the result of all students, including their roll number, name, marks in different subjects, percentage, and grade.
* void result(): Prompts the user to enter a roll number and displays the result of the corresponding student.
* void intro(): Displays an introduction to the program.
* void entry_menu(): Displays the entry/edit menu and allows the user to perform various operations on student records.
* int main(): The main function that displays the main menu and allows the user to navigate through different options.
Code Examples
Here are a few code examples to illustrate how the program works:
1. Creating a student record and writing it to the file:
language-cpp
 Copy code
void write_student() {
    // Open the file in append mode
    fp.open("student.dat", ios::out | ios::app);

    // Prompt the user to enter student details
    cout << "\nEnter The roll number of student: ";
    cin >> st.rollno;
    cin.ignore();
    cout << "\n\nEnter The Name of student: ";
    cin.getline(st.name, 50);
    // ...

    // Calculate the percentage and grade
    st.per = (st.p_marks + st.c_marks + st.m_marks + st.e_marks + st.cs_marks) / 5.0;
    if (st.per >= 60)
        st.grade = 'A';
    else if (st.per >= 50 && st.per < 60)
        st.grade = 'B';
    else if (st.per >= 33 && st.per < 50)
        st.grade = 'C';
    else
        st.grade = 'F';

    // Write the student record to the file
    fp.write((char*)&st, sizeof(student));
    fp.close();
    cout << "\n\nStudent record Has Been Created ";
}
2. Displaying all student records:
language-cpp
 Copy code
void display_all() {
    system("clear");
    int tempc;
    cout << "\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
    fp.open("student.dat", ios::in);
    while (fp.read((char*)&st, sizeof(student))) {
        // Display the student details
        cout << "\nRoll Number of Student : " << st.rollno;
        cout << "\nName of student : " << st.name;
        // ...

        cout << "\n\n====================================\n";
    }
    cout<<"\nEnter 1 to continue :- ";
    cin>>tempc;
    fp.close();
}
3. Modifying a student record:
language-cpp
 Copy code
void modify_student(int n) {
    bool found = false;
    fp.open("student.dat", ios::in | ios::out);
    while (fp.read((char*)&st, sizeof(student)) && found == false) {
        if (st.rollno == n) {
            // Display the current student details
            cout << "\nRoll number of student : " << st.rollno;
            cout << "\nName of student : " << st.name;
            // ...

            // Prompt the user to enter new details
            cout << "\n\nPlease Enter The New Details of student" << endl;
            cout << "\nEnter The roll number of student: ";
            cin >> st.rollno;
            cin.ignore();
            cout << "\n\nEnter The Name of student: ";
            cin.getline(st.name, 50);
            // ...

            // Calculate the new percentage and grade
            st.per = (st.p_marks + st.c_marks + st.m_marks + st.e_marks + st.cs_marks) / 5.0;
            if (st.per >= 60)
                st.grade = 'A';
            else if (st.per >= 50 && st.per < 60)
                st.grade = 'B';
            else if (st.per >= 33 && st.per < 50)
                st.grade = 'C';
            else
                st.grade = 'F';

            // Update the student record in the file
            unsigned long pos = -1 * sizeof(st);
            fp.seekp(pos, ios::cur);
            fp.write((char*)&st, sizeof(student));
            cout << "\n\n\t Record Updated";
            found = true;
        }
    }
    int tempc;
    cout<<"\nEnter 1 to continue :- ";
    cin>>tempc;
    fp.close();
    if (found == false)
        cout << "\n\n Record Not Found ";
}
Conclusion
The Student Report Card Project is a comprehensive program written in C++ that allows users to manage student records. It provides functionality for creating, displaying, searching, modifying, and deleting student records. The program utilizes key concepts such as structures, linked lists, and file handling to efficiently store and retrieve student information. With its user-friendly interface and robust functionality, the Student Report Card Project is a valuable tool for educational institutions to manage student data effectively.
