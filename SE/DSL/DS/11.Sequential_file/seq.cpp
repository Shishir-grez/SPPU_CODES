#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student
{
    int rollNumber;
    string name;
    string division;
    string address;
};

const string fileName = "student.txt";

// Function to add a student to the file
void addStudent()
{
    Student student;
    cout << "Enter roll number: ";
    cin >> student.rollNumber;
    cin.ignore();

    cout << "Enter name: ";
    getline(cin, student.name);

    cout << "Enter division: ";
    getline(cin, student.division);

    cout << "Enter address: ";
    getline(cin, student.address);

    // Open the file in append mode
    ofstream file;
    file.open("student.txt", ios::app);
    if (!file.is_open())
    {
        cout << "Error opening file." << endl;
        return;
    }

    // Write the student record to the file
    file << student.rollNumber << "," << student.name << "," << student.division << "," << student.address << endl;
    file.close();

    cout << "Student added successfully." << endl;
}

// Function to delete a student from the file
void deleteStudent()
{
    int rollNumber;
    cout << "Enter roll number to delete: ";
    cin >> rollNumber;
    cin.ignore();

    // Open a temporary file for writing
    ofstream tempFile;
    tempFile.open("temp.txt", ios::out);
    if (!tempFile.is_open())
    {
        cout << "Error opening file." << endl;
        return;
    }

    // Open the original file for reading
    ifstream file;
    file.open("student.txt", ios::in);
    if (!file.is_open())
    {
        cout << "Error opening file." << endl;
        tempFile.close();
        return;
    }

    bool found = false;
    string line;
    // Read the file line by line
    while (getline(file, line))
    {
        // Extract the roll number from the line
        char str[1000];
        int m = 0;
        int i = 0;

        while (line[i] != '\0' && line[i] != ',')
        {
            str[m] = line[i];
            i++;
            m++;
        }

        str[m] = '\0';
        int currentRollNumber = atoi(str);

        // If the roll number matches, skip writing to the temporary file
        if (currentRollNumber == rollNumber)
        {
            found = true;
            continue;
        }

        // Write the line to the temporary file
        tempFile << line << endl;
    }

    file.close();
    tempFile.close();

    // Delete the original file
    remove(fileName.c_str());

    // Rename the temporary file to the original file
    rename("temp.txt", fileName.c_str());

    if (found)
    {
        cout << "Student with roll number " << rollNumber << " deleted successfully." << endl;
    }
    else
    {
        cout << "Student with roll number " << rollNumber << " not found." << endl;
    }
}

// Function to display student details
void displayStudent()
{
    int rollNumber;
    cout << "Enter roll number to display: ";
    cin >> rollNumber;
    cin.ignore();

    // Open the file for reading
    ifstream file;
    file.open(fileName, ios::in);
    if (!file.is_open())
    {
        cout << "Error opening file." << endl;
        return;
    }

    bool found = false;
    string line;
    // Read the file line by line
    while (getline(file, line))
    {
        // Extract the roll number from the line
        int currentRollNumber = stoi(line.substr(0, line.find(',')));

        // If the roll number matches, display the student details
        if (currentRollNumber == rollNumber)
        {
            found = true;
            cout << "Student details:" << endl;
            cout << "Roll Number: " << currentRollNumber << endl;

            // Extract the remaining fields from the line
            string remainingFields = line.substr(line.find(',') + 1);
            size_t pos = remainingFields.find(',');
            cout << "Name: " << remainingFields.substr(0, pos) << endl;
            remainingFields = remainingFields.substr(pos + 1);

            pos = remainingFields.find(',');
            cout << "Division: " << remainingFields.substr(0, pos) << endl;
            remainingFields = remainingFields.substr(pos + 1);

            cout << "Address: " << remainingFields << endl;
            break;
        }
    }

    file.close();

    if (!found)
    {
        cout << "Student with roll number " << rollNumber << " not found." << endl;
    }
}

int main()
{
    int choice;
    do
    {
        cout << "1. Add Student" << endl;
        cout << "2. Delete Student" << endl;
        cout << "3. Display Student" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            deleteStudent();
            break;
        case 3:
            displayStudent();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

        cout << endl;
    } while (choice != 4);

    return 0;
}
