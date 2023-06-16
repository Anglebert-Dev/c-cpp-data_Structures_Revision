#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

struct Student {
  string name;
  int age;
  char grade;
};

void addStudent(ofstream& file) {
  Student student;
  cout << "Enter student name: ";
  cin.ignore(); // Ignore the newline character left in the input stream
  getline(cin, student.name);
  cout << "Enter student age: ";
  cin >> student.age;
  cout << "Enter student grade: ";
  cin >> student.grade;
  student.grade = toupper(student.grade); // Capitalize the grade

  // Write student data to the file
  file << student.name << "," << student.age << "," << student.grade << endl;

  cout << "Student added successfully!" << endl;
}

void displayStudents(ifstream& file) {
  cout << "Student Records:" << endl;
  string line;
  while (getline(file, line)) {
    size_t pos1 = line.find(',');
    size_t pos2 = line.find(',', pos1 + 1);
    string name = line.substr(0, pos1);
    int age = stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
    char grade = line[pos2 + 1];

    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Grade: " << grade << endl;
    cout << endl;
  }
}

void searchStudent(ifstream& file, const string& name) {
  bool found = false;
  string line;
  while (getline(file, line)) {
    size_t pos1 = line.find(',');
    size_t pos2 = line.find(',', pos1 + 1);
    string studentName = line.substr(0, pos1);
    int age = stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
    char grade = line[pos2 + 1];

    // Convert both names to uppercase for case-insensitive comparison
    string upperName = studentName;
    transform(upperName.begin(), upperName.end(), upperName.begin(), ::toupper);
    string upperSearchName = name;
    transform(upperSearchName.begin(), upperSearchName.end(), upperSearchName.begin(), ::toupper);

    // Check if student name matches the search name
    if (upperName.find(upperSearchName) != string::npos) {
      cout << "Student found!" << endl;
      cout << "Name: " << studentName << endl;
      cout << "Age: " << age << endl;
      cout << "Grade: " << grade << endl;
      found = true;
      break;
    }
  }

  if (!found) {
    cout << "Student not found." << endl;
  }
}

int main() {
  ofstream outFile("students.txt", ios::app); // Open the file in append mode
  if (!outFile.is_open()) {
    cout << "Unable to open file." << endl;
    return 1;
  }

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
        addStudent(outFile);
        break;
      case 2: {
        ifstream inFile("students.txt");
        if (!inFile.is_open()) {
          cout << "Unable to open file." << endl;
          break;
        }
        displayStudents(inFile);
        inFile.close();
        break;
      }
      case 3: {
        string searchName;
        cout << "Enter student name to search: ";
        cin.ignore(); // Ignore the newline character left in the input stream
        getline(cin, searchName);

        ifstream inFile("students.txt");
        if (!inFile.is_open()) {
          cout << "Unable to open file." << endl;
          break;
        }
        searchStudent(inFile, searchName);
        inFile.close();
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

  outFile.close();

  return 0;
}
