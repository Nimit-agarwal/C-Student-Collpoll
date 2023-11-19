#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    string name;
    int rollNumber;
    string route;
};

void addStudent() {
    system("clear");
    ofstream file("transport.dat", ios::app | ios::binary);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    Student student;
    cout << "Enter student name: ";
    getline(cin, student.name);
    cout << "Enter roll number: ";
    cin >> student.rollNumber;
    cin.ignore();
    cout << "Enter route: ";
    getline(cin, student.route);

    file.write(reinterpret_cast<char*>(&student), sizeof(Student));
    file.close();

    cout << "Student added successfully!" << endl;
}

void displayStudents() {
    system("clear");
    ifstream file("transport.dat", ios::binary);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    Student student;
    while (file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        cout << "Name: " << student.name << endl;
        cout << "Roll Number: " << student.rollNumber << endl;
        cout << "Route: " << student.route << endl;
        cout << endl;
    }

    file.close();
}

void modifyStudent() {
    system("clear");
    fstream file("transport.dat", ios::in | ios::out | ios::binary);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    int rollNumber;
    cout << "Enter the roll number of the student to modify: ";
    cin >> rollNumber;
    cin.ignore();

    Student student;
    bool found = false;
    while (file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        if (student.rollNumber == rollNumber) {
            cout << "Enter new student name: ";
            getline(cin, student.name);
            cout << "Enter new route: ";
            getline(cin, student.route);

            file.seekp(-sizeof(Student), ios::cur);
            file.write(reinterpret_cast<char*>(&student), sizeof(Student));

            found = true;
            break;
        }
    }

    file.close();

    if (found) {
        cout << "Student modified successfully!" << endl;
    } else {
        cout << "Student not found!" << endl;
    }
}

void deleteStudent() {
    system("clear");
    ifstream file("transport.dat", ios::binary);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    ofstream tempFile("temp.dat", ios::binary);
    if (!tempFile) {
        cout << "Error creating temporary file!" << endl;
        return;
    }

    int rollNumber;
    cout << "Enter the roll number of the student to delete: ";
    cin >> rollNumber;
    cin.ignore();

    Student student;
    bool found = false;
    while (file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        if (student.rollNumber != rollNumber) {
            tempFile.write(reinterpret_cast<char*>(&student), sizeof(Student));
        } else {
            found = true;
        }
    }

    file.close();
    tempFile.close();

    remove("transport.dat");
    rename("temp.dat", "transport.dat");

    if (found) {
        cout << "Student deleted successfully!" << endl;
    } else {
        cout << "Student not found!" << endl;
    }
}

void searchStudent() {
    system("clear");
    ifstream file("transport.dat", ios::binary);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    int rollNumber;
    cout << "Enter the roll number of the student to search: ";
    cin >> rollNumber;
    cin.ignore();

    Student student;
    bool found = false;
    while (file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        if (student.rollNumber == rollNumber) {
            cout << "Name: " << student.name << endl;
            cout << "Roll Number: " << student.rollNumber << endl;
            cout << "Route: " << student.route << endl;
            cout << endl;

            found = true;
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "Student not found!" << endl;
    }
}

int main() {
    int choice;
    int tempc;
    do {
        system("clear");
        cout << "\n\n\n\tENTRY MENU";
        cout << "\n\n\t1.CREATE STUDENT TRANSPORTATION RECORD";
        cout << "\n\n\t2.DISPLAY ALL STUDENTS TRANSPORTATION RECORDS";
        cout << "\n\n\t3.MODIFY STUDENT TRANSPORTATION RECORD";
        cout << "\n\n\t4.DELETE STUDENT TRANSPORTATION RECORD";
        cout << "\n\n\t5.SEARCH STUDENT TRANSPORTATION RECORD";
        cout << "\n\n\t6.EXIT";
        cout << "\n\n\tPlease Enter Your Choice (1-6): ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                cout << "\n\nEnter 1 to continue: ";
                cin >> tempc;
                break;
            case 3:
                modifyStudent();
                cout << "\n\nEnter 1 to continue: ";
                cin >> tempc;
                break;
            case 4:
                deleteStudent();
                cout << "\n\nEnter 1 to continue: ";
                cin >> tempc;
                break;
            case 5:
                searchStudent();
                cout << "\n\nEnter 1 to continue: ";
                cin >> tempc;
                break;
            case 6:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }

        cout << endl;
    } while (choice != 6);

    return 0;
}
