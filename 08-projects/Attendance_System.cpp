

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX = 50;

// Function Declarations

void displayMenu();

void registerStudent(int ids[], string names[],
                     int present[], int absent[],
                     int &count);

void displayStudents(int ids[], string names[],
                     int present[], int absent[],
                     int count);

void markAttendance(int ids[], string names[],
                    int present[], int absent[],
                    int count);

void searchStudent(int ids[], string names[],
                   int present[], int absent[],
                   int count);

double calculatePercentage(int present, int absent);

void attendanceReport(int ids[], string names[],
                      int present[], int absent[],
                      int count);

void lowAttendance(int ids[], string names[],
                   int present[], int absent[],
                   int count);


// Main Function

int main()
{
    int ids[MAX];
    string names[MAX];

    int present[MAX] = {0};
    int absent[MAX] = {0};

    int count = 0;
    int choice;

    do
    {
        displayMenu();

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                registerStudent(ids, names, present,
                                absent, count);
                break;

            case 2:
                displayStudents(ids, names, present,
                                absent, count);
                break;

            case 3:
                markAttendance(ids, names, present,
                               absent, count);
                break;

            case 4:
                searchStudent(ids, names, present,
                              absent, count);
                break;

            case 5:
                attendanceReport(ids, names, present,
                                 absent, count);
                break;

            case 6:
                lowAttendance(ids, names, present,
                              absent, count);
                break;

            case 7:
                cout << "\nThank you for using Attendance Pro!\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while(choice != 7);

    return 0;
}


// Display Menu

void displayMenu()
{
    cout << "\n====================================\n";
    cout << "       ATTENDANCE MANAGEMENT\n";
    cout << "====================================\n";

    cout << "1. Register New Student\n";
    cout << "2. Display All Students\n";
    cout << "3. Mark Attendance\n";
    cout << "4. Search Student\n";
    cout << "5. Attendance Report\n";
    cout << "6. Low Attendance Students\n";
    cout << "7. Exit\n";

    cout << "====================================\n";
}


// Register Student

void registerStudent(int ids[], string names[],
                     int present[], int absent[],
                     int &count)
{
    if(count >= MAX)
    {
        cout << "\nStudent limit reached!\n";
        return;
    }

    int newID;

    cout << "\nEnter Student ID: ";
    cin >> newID;

    for(int i = 0; i < count; i++)
    {
        if(ids[i] == newID)
        {
            cout << "\nStudent ID already exists!\n";
            return;
        }
    }

    ids[count] = newID;

    cin.ignore();

    cout << "Enter Student Name: ";
    getline(cin, names[count]);

    present[count] = 0;
    absent[count] = 0;

    count++;

    cout << "\nStudent registered successfully!\n";
}


// Display Students

void displayStudents(int ids[], string names[],
                     int present[], int absent[],
                     int count)
{
    if(count == 0)
    {
        cout << "\nNo students registered!\n";
        return;
    }

    cout << "\n========== STUDENT LIST ==========\n";

    cout << left
         << setw(12) << "ID"
         << setw(20) << "Name"
         << setw(12) << "Present"
         << "Absent\n";

    cout << "---------------------------------------------\n";

    for(int i = 0; i < count; i++)
    {
        cout << left
             << setw(12) << ids[i]
             << setw(20) << names[i]
             << setw(12) << present[i]
             << absent[i] << endl;
    }
}


// Mark Attendance

void markAttendance(int ids[], string names[],
                    int present[], int absent[],
                    int count)
{
    if(count == 0)
    {
        cout << "\nNo students registered!\n";
        return;
    }

    int searchID;
    int status;
    int index = -1;

    cout << "\nEnter Student ID: ";
    cin >> searchID;

    for(int i = 0; i < count; i++)
    {
        if(ids[i] == searchID)
        {
            index = i;
            break;
        }
    }

    if(index == -1)
    {
        cout << "\nStudent not found!\n";
        return;
    }

    cout << "\nStudent Name: " << names[index] << endl;

    cout << "\n1. Present\n";
    cout << "2. Absent\n";

    cout << "\nEnter Attendance Status: ";
    cin >> status;

    if(status == 1)
    {
        present[index]++;

        cout << "\nAttendance marked as PRESENT!\n";
    }
    else if(status == 2)
    {
        absent[index]++;

        cout << "\nAttendance marked as ABSENT!\n";
    }
    else
    {
        cout << "\nInvalid attendance status!\n";
    }
}


// Search Student

void searchStudent(int ids[], string names[],
                   int present[], int absent[],
                   int count)
{
    int searchID;
    bool found = false;

    cout << "\nEnter Student ID: ";
    cin >> searchID;

    for(int i = 0; i < count; i++)
    {
        if(ids[i] == searchID)
        {
            cout << "\nStudent Found!\n";

            cout << "ID: " << ids[i] << endl;
            cout << "Name: " << names[i] << endl;

            cout << "Present Days: " << present[i] << endl;
            cout << "Absent Days: " << absent[i] << endl;

            cout << "Attendance: "
                 << fixed << setprecision(2)
                 << calculatePercentage(present[i], absent[i])
                 << "%\n";

            found = true;
            break;
        }
    }

    if(found == false)
    {
        cout << "\nStudent not found!\n";
    }
}


// Calculate Attendance Percentage

double calculatePercentage(int present, int absent)
{
    int total = present + absent;

    if(total == 0)
        return 0;

    return (double)present / total * 100;
}


// Attendance Report

void attendanceReport(int ids[], string names[],
                      int present[], int absent[],
                      int count)
{
    if(count == 0)
    {
        cout << "\nNo students available!\n";
        return;
    }

    cout << "\n========== ATTENDANCE REPORT ==========\n";

    cout << left
         << setw(12) << "ID"
         << setw(18) << "Name"
         << setw(10) << "Present"
         << setw(10) << "Absent"
         << "Percentage\n";

    cout << "----------------------------------------------------------\n";

    for(int i = 0; i < count; i++)
    {
        cout << left
             << setw(12) << ids[i]
             << setw(18) << names[i]
             << setw(10) << present[i]
             << setw(10) << absent[i];

        cout << fixed << setprecision(2)
             << calculatePercentage(present[i], absent[i])
             << "%\n";
    }
}


// Find Low Attendance Students

void lowAttendance(int ids[], string names[],
                   int present[], int absent[],
                   int count)
{
    if(count == 0)
    {
        cout << "\nNo students available!\n";
        return;
    }

    bool found = false;

    cout << "\n========== LOW ATTENDANCE STUDENTS ==========\n";

    for(int i = 0; i < count; i++)
    {
        int total = present[i] + absent[i];

        if(total > 0 &&
           calculatePercentage(present[i], absent[i]) < 80)
        {
            cout << "\nStudent ID: " << ids[i] << endl;
            cout << "Name: " << names[i] << endl;

            cout << "Attendance: "
                 << fixed << setprecision(2)
                 << calculatePercentage(present[i], absent[i])
                 << "%\n";

            cout << "WARNING: Low Attendance!\n";

            found = true;
        }
    }

    if(found == false)
    {
        cout << "\nNo students with low attendance!\n";
    }
}
