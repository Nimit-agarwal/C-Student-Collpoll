#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<stdlib.h>
#include<cstring>
#include<fstream>
#include<iomanip>
#include <string>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<sstream>
#include<bitset>
#include<unordered_map>
#include<unordered_set>
#include <cstdlib>

using namespace std;

struct student {
    int rollno;
    char name[50];
    int p_marks, c_marks, m_marks, e_marks, cs_marks;
    double per;
    char grade;
    int tempc;
};

struct Node {
    student data;
    Node* next;
};

class LinkedListStack {
private:
    Node* top;

public:
    LinkedListStack() {
        top = NULL;
    }

    void push(student s) {
        Node* newNode = new Node;
        newNode->data = s;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    student peek() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
            student s;
            return s;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == NULL;
    }
};

class LinkedListQueue {
private:
    Node* front;
    Node* rear;

public:
    LinkedListQueue() {
        front = NULL;
        rear = NULL;
    }

    void enqueue(student s) {
        Node* newNode = new Node;
        newNode->data = s;
        newNode->next = NULL;
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete temp;
    }

    student peek() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            student s;
            return s;
        }
        return front->data;
    }

    bool isEmpty() {
        return front == NULL;
    }
};

fstream fp;
student st;

void write_student() {
    fp.open("student.dat", ios::out | ios::app);
    cout << "\nEnter The roll number of student: ";
    cin >> st.rollno;
    cin.ignore();
    cout << "\n\nEnter The Name of student: ";
    cin.getline(st.name, 50);
    cout << "\nEnter The marks in physics out of 100 : ";
    cin >> st.p_marks;
    cout << "\nEnter The marks in chemistry out of 100 : ";
    cin >> st.c_marks;
    cout << "\nEnter The marks in maths out of 100 : ";
    cin >> st.m_marks;
    cout << "\nEnter The marks in english out of 100 : ";
    cin >> st.e_marks;
    cout << "\nEnter The marks in computer science out of 100 : ";
    cin >> st.cs_marks;
    st.per = (st.p_marks + st.c_marks + st.m_marks + st.e_marks + st.cs_marks) / 5.0;
    if (st.per >= 60)
        st.grade = 'A';
    else if (st.per >= 50 && st.per < 60)
        st.grade = 'B';
    else if (st.per >= 33 && st.per < 50)
        st.grade = 'C';
    else
        st.grade = 'F';
    fp.write((char*)&st, sizeof(student));
    fp.close();
    cout << "\n\nStudent record Has Been Created ";
}

void display_all() {
    system("clear");
    int tempc;
    cout << "\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
    fp.open("student.dat", ios::in);
    while (fp.read((char*)&st, sizeof(student))) {
        cout << "\nRoll Number of Student : " << st.rollno;
        cout << "\nName of student : " << st.name;
        cout << "\nMarks in Physics : " << st.p_marks;
        cout << "\nMarks in Chemistry : " << st.c_marks;
        cout << "\nMarks in Maths : " << st.m_marks;
        cout << "\nMarks in English : " << st.e_marks;
        cout << "\nMarks in Computer Science : " << st.cs_marks;
        cout << "\nPercentage of student is  : " << st.per;
        cout << "\nGrade of student is : " << st.grade;
        cout << "\n\n====================================\n";
    }
    cout<<"\n\nEnter 1 to continue :- ";
    cin>>tempc;
    fp.close();
}

void display_sp(int n) {
    bool flag = false;
    fp.open("student.dat", ios::in);
    while (fp.read((char*)&st, sizeof(student))) {
        if (st.rollno == n) {
            system("clear");
            cout << "\nRoll number of student : " << st.rollno;
            cout << "\nName of student : " << st.name;
            cout << "\nMarks in Physics : " << st.p_marks;
            cout << "\nMarks in Chemistry : " << st.c_marks;
            cout << "\nMarks in Maths : " << st.m_marks;
            cout << "\nMarks in English : " << st.e_marks;
            cout << "\nMarks in Computer Science : " << st.cs_marks;
            cout << "\nPercentage of student is  : " << st.per;
            cout << "\nGrade of student is : " << st.grade;
            flag = true;
        }
    }
    int tempc;
    cout<<"\n\nEnter 1 to continue :- ";
    cin>>tempc;
    fp.close();
    if (flag == false)
        cout << "\n\nrecord not exist";
}

void modify_student(int n) {
    bool found = false;
    fp.open("student.dat", ios::in | ios::out);
    while (fp.read((char*)&st, sizeof(student)) && found == false) {
        if (st.rollno == n) {
            cout << "\nRoll number of student : " << st.rollno;
            cout << "\nName of student : " << st.name;
            cout << "\nMarks in Physics : " << st.p_marks;
            cout << "\nMarks in Chemistry : " << st.c_marks;
            cout << "\nMarks in Maths : " << st.m_marks;
            cout << "\nMarks in English : " << st.e_marks;
            cout << "\nMarks in Computer Science : " << st.cs_marks;
            cout << "\nPercentage of student is  : " << st.per;
            cout << "\nGrade of student is : " << st.grade;
            cout << "\n\nPlease Enter The New Details of student" << endl;
            cout << "\nEnter The roll number of student: ";
            cin >> st.rollno;
            cin.ignore();
            cout << "\n\nEnter The Name of student: ";
            cin.getline(st.name, 50);
            cout << "\nEnter The marks in physics out of 100 : ";
            cin >> st.p_marks;
            cout << "\nEnter The marks in chemistry out of 100 : ";
            cin >> st.c_marks;
            cout << "\nEnter The marks in maths out of 100 : ";
            cin >> st.m_marks;
            cout << "\nEnter The marks in english out of 100 : ";
            cin >> st.e_marks;
            cout << "\nEnter The marks in computer science out of 100 : ";
            cin >> st.cs_marks;
            st.per = (st.p_marks + st.c_marks + st.m_marks + st.e_marks + st.cs_marks) / 5.0;
            if (st.per >= 60)
                st.grade = 'A';
            else if (st.per >= 50 && st.per < 60)
                st.grade = 'B';
            else if (st.per >= 33 && st.per < 50)
                st.grade = 'C';
            else
                st.grade = 'F';
            unsigned long pos = -1 * sizeof(st);
            fp.seekp(pos, ios::cur);
            fp.write((char*)&st, sizeof(student));
            cout << "\n\n\t Record Updated";
            found = true;
        }
    }
    int tempc;
    cout<<"\n\nEnter 1 to continue :- ";
    cin>>tempc;
    fp.close();
    if (found == false)
        cout << "\n\n Record Not Found ";
}

void delete_student(int n) {
    fp.open("student.dat", ios::in | ios::out);
    fstream fp2;
    fp2.open("Temp.dat", ios::out);
    fp.seekg(0, ios::beg);
    while (fp.read((char*)&st, sizeof(student))) {
        if (st.rollno != n)
            fp2.write((char*)&st, sizeof(student));
    }
    fp2.close();
    fp.close();
    remove("student.dat");
    rename("Temp.dat", "student.dat");
    cout << "\n\n\tRecord Deleted ..";
}

void class_result() {
    system("clear");
    fp.open("student.dat", ios::in);
    if (!fp) {
        cout << "ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Entry Menu to create File";
        cout << "\n\n\n Program is closing ....";
        exit(0);
    }

    cout << "\n\n\t\tALL STUDENTS RESULT \n\n";
    cout << "====================================================\n";
    cout << "R.No.  Name       P   C   M   E   CS  %age   Grade\n";
    cout << "====================================================\n";

    while (fp.read((char*)&st, sizeof(student))) {
        cout << st.rollno << "    " << st.name << "    " << st.p_marks << "    " << st.c_marks << "    " << st.m_marks << "    " << st.e_marks << "    " << st.cs_marks << "    " << st.per << "    " << st.grade << endl;
    }
    fp.close();
}

void result() {
    int rno;
    system("clear");
    cout << "\n\n\n\tEnter Roll Number Of Student : ";
    cin >> rno;
    display_sp(rno);
}

void intro() {
    system("clear");
    cout << "\n\n\n\t\tSTUDENT REPORT CARD PROJECT";
    cout << "\n\n\n\tMADE BY : YOUR NAME";
    cout << "\n\n\tCOLLEGE : BENNETT UNIVERSITY";
}

void entry_menu() {
    char ch;
    int num;
    intro();
    do {
        system("clear");
        cout << "\n\n\n\tENTRY MENU";
        cout << "\n\n\t1.CREATE STUDENT RECORD";
        cout << "\n\n\t2.DISPLAY ALL STUDENTS RECORDS";
        cout << "\n\n\t3.SEARCH STUDENT RECORD ";
        cout << "\n\n\t4.MODIFY STUDENT RECORD";
        cout << "\n\n\t5.DELETE STUDENT RECORD";
        cout << "\n\n\t6.BACK TO MAIN MENU";
        cout << "\n\n\tPlease Enter Your Choice (1-6) ";
        cin >> ch;
        system("clear");
        switch (ch) {
        case '1': write_student(); break;
        case '2': display_all(); break;
        case '3': cout << "\n\n\tPlease Enter The roll number "; cin >> num; display_sp(num); break;
        case '4': cout << "\n\n\tPlease Enter The roll number "; cin >> num; modify_student(num); break;
        case '5': cout << "\n\n\tPlease Enter The roll number "; cin >> num; delete_student(num); break;
        case '6': break;
        default:cout << "\a";
        }
    } while (ch != '6');
}

void face(){

    const char* pythonScript = "attendence.py";

    const char* pythonInterpreterPath = "/Library/Frameworks/Python.framework/Versions/3.11/bin/python3"; // Path to Python interpreter

    std::string command = std::string(pythonInterpreterPath) + " " + pythonScript;

    const char* commandPtr = command.c_str();

    int exitCode = std::system(commandPtr);

    if (exitCode == 0) {
        std::cout << "Python script executed successfully." << std::endl;
    } else {
        std::cerr << "Failed to execute Python script." << std::endl;
    }
}


int main() {
    char ch;
    int tempc;
    while(1){
        system("clear");
        cout << "\n\n\n\tMAIN MENU";
        cout << "\n\n\t01. RESULT MENU";
        cout << "\n\n\t02. ENTRY/EDIT MENU";
        cout << "\n\n\t03. ATTENDENCE FACE RECOGNITION";
        cout << "\n\n\t04. DISPLAY ATTENDENCE";
        cout << "\n\n\t05. DELETE PREVIOUS ATTENDENCE";
        cout << "\n\n\t06. STUDENT TRANSPORTATION";
        cout << "\n\n\t07. EXIT";
        cout << "\n\n\tPlease Select Your Option (1-4) ";
        ch = getchar();
        system("clear");
        if (ch=='1'){ 
            class_result();
            cout<<"\n\nEnter 1 to continue :- ";
            cin>>tempc;
        }
        if (ch=='2'){
            entry_menu();
        }
        if (ch=='7'){
            exit(0);
        }
        if (ch=='3'){
            face();
        }
        if (ch=='4'){
            const std::string csvFileName = "attendences.csv"; // Change this to your CSV file's name
            // Open the CSV file for reading
            std::ifstream csvFile(csvFileName);
            if (!csvFile.is_open()) {
                std::cerr << "Error: Could not open the CSV file." << std::endl;
                return 1;
            }
            std::string line;
            while (std::getline(csvFile, line)) {
                std::istringstream lineStream(line);
                std::string field;
                std::vector<std::string> fields;
                while (std::getline(lineStream, field, ',')) {
                    fields.push_back(field);
                }
                for (const std::string& data : fields) {
                    std::cout << data << " | ";
                }
                std::cout << std::endl;
            }
            cout<<"\n\nEnter 1 to continue :- ";
            cin>>tempc;
            csvFile.close();
        }
        if (ch=='5'){
            const char* filename = "attendences.csv";
            std::ofstream ofs;
            ofs.open(filename, std::ofstream::out | std::ofstream::trunc);
            ofs.close();
            std::cout << "Previous Attendence Cleared Successfully!" << std::endl;
            cout<<"\n\nEnter 1 to continue :- ";
            cin>>tempc;
        }
        if(ch=='6'){
            std::system("g++ tempc.cpp -o executable"); // Compile the file
            std::system("./executable"); // Run the compiled file
        }
        else{
            cout << "\a";
        }
    }
    return 0;
}
