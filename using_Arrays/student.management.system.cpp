#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
using namespace std;

struct Student {
  string name;
  int age;
  char grade;
};


void addStudent(Student students[], int& count) {
  if (count < 100) {
    cout << "Enter student name: ";
    cin.ignore(); // Ignore the newline character left in the input stream
    getline(cin, students[count].name);
    cout << "Enter student age: ";
    cin >> students[count].age;
    cout << "Enter student grade: ";
    cin >> students[count].grade;
    students[count].grade = toupper(students[count].grade); // Capitalize the grade
    count++;
    cout << "Student added successfully!" << endl;
  } else {
    cout << "Cannot add more students. Maximum limit reached." << endl;
  }
}

void displayStudents(Student students[], int count) {
  cout << "Student Records:" << endl;
  for (int i = 0; i < count; i++) {
    cout << "Name: " << students[i].name << endl;
    cout << "Age: " << students[i].age << endl;
    cout << "Grade: " << students[i].grade << endl;
    cout << endl;
  }
}

void searchStudent(Student students[], int count, string name) {
  bool found = false;
  for (int i = 0; i < count; i++) {
    if (students[i].name == name) {
      cout << "Student found!" << endl;
      cout << "Name: " << students[i].name << endl;
      cout << "Age: " << students[i].age << endl;
      cout << "Grade: " << students[i].grade << endl;
      found = true;
      break;
    }
  }
  if (!found) {
    cout << "Student not found." << endl;
  }
}

int main() {
  Student students[100];
  int count = 0;

  int choice;
  do {
    cout << "Student Management System" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. Display Students" << endl;
    cout << "3. Search Student" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        addStudent(students, count);
        break;
      case 2:
        displayStudents(students, count);
        break;
      case 3: {
        string searchName;
        cout << "Enter student name to search: ";
        cin.ignore(); // Ignore the newline character left in the input stream
        getline(cin, searchName);
        searchStudent(students, count, searchName);
        break;
      }
      case 4:
        cout << "Exiting program..." << endl;
        break;
      default:
        cout << "Invalid choice. Try again." << endl;
    }
    cout << endl;
  } while (choice != 4);

  return 0;
}
