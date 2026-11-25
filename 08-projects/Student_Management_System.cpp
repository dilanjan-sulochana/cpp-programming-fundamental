
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX = 50;

// Function Declarations

void displayMenu();

void addStudent(int ids[], string names[],
                double marks1[], double marks2[],
                double marks3[], int &count);

void displayStudents(int ids[], string names[],
                     double marks1[], double marks2[],
                     double marks3[], int count);

void searchStudent(int ids[], string names[],
                   double marks1[], double marks2[],
                   double marks3[], int count);

double calculateAverage(double m1, double m2, double m3);

char calculateGrade(double average);

void displayResult(int ids[], string names[],
                   double marks1[], double marks2[],
                   double marks3[], int count);

void findTopStudent(int ids[], string names[],
                    double marks1[], double marks2[],
                    double marks3[], int count);

void classStatistics(double marks1[], double marks2[],
                     double marks3[], int count);


// Main Function

int main()
{
    int ids[MAX];
    string names[MAX];

    double marks1[MAX];
    double marks2[MAX];
    double marks3[MAX];

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
                addStudent(ids, names, marks1,
                           marks2, marks3, count);
                break;

            case 2:
                displayStudents(ids, names, marks1,
                                marks2, marks3, count);
                break;

            case 3:
                searchStudent(ids, names, marks1,
                              marks2, marks3, count);
                break;

            case 4:
                displayResult(ids, names, marks1,
                              marks2, marks3, count);
                break;

            case 5:
                findTopStudent(ids, names, marks1,
                               marks2, marks3, count);
                break;

            case 6:
                classStatistics(marks1, marks2,
                                marks3, count);
                break;

            case 7:
                cout << "\nThank you for using Student Portal!\n";
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
    cout << "\n========================================\n";
    cout << "          STUDENT MANAGEMENT\n";
    cout << "========================================\n";

    cout << "1. Add New Student\n";
    cout << "2. Display All Students\n";
    cout << "3. Search Student\n";
    cout << "4. Examination Results\n";
    cout << "5. Find Top Student\n";
    cout << "6. Class Statistics\n";
    cout << "7. Exit\n";

    cout << "========================================\n";
}


// Add Student

void addStudent(int ids[], string names[],
                double marks1[], double marks2[],
                double marks3[], int &count)
{
    if(count >= MAX)
    {
        cout << "\nStudent limit reached!\n";
        return;
    }

    cout << "\n========== ADD STUDENT ==========\n";

    cout << "Enter Student ID: ";
    cin >> ids[count];

    // Check duplicate ID

    for(int i = 0; i < count; i++)
    {
        if(ids[i] == ids[count])
        {
            cout << "Student ID already exists!\n";
            return;
        }
    }

    cin.ignore();

    cout << "Enter Student Name: ";
    getline(cin, names[count]);

    cout << "Enter Subject 1 Marks: ";
    cin >> marks1[count];

    cout << "Enter Subject 2 Marks: ";
    cin >> marks2[count];

    cout << "Enter Subject 3 Marks: ";
    cin >> marks3[count];

    if(marks1[count] < 0 || marks1[count] > 100 ||
       marks2[count] < 0 || marks2[count] > 100 ||
       marks3[count] < 0 || marks3[count] > 100)
    {
        cout << "Invalid marks! Enter marks between 0-100.\n";
        return;
    }

    count++;

    cout << "\nStudent added successfully!\n";
}


// Display All Students

void displayStudents(int ids[], string names[],
                     double marks1[], double marks2[],
                     double marks3[], int count)
{
    if(count == 0)
    {
        cout << "\nNo students available!\n";
        return;
    }

    cout << "\n================ STUDENT LIST ================\n";

    cout << left
         << setw(10) << "ID"
         << setw(20) << "Name"
         << setw(10) << "Sub 1"
         << setw(10) << "Sub 2"
         << "Sub 3\n";

    cout << "------------------------------------------------\n";

    for(int i = 0; i < count; i++)
    {
        cout << left
             << setw(10) << ids[i]
             << setw(20) << names[i]
             << setw(10) << marks1[i]
             << setw(10) << marks2[i]
             << marks3[i] << endl;
    }
}


// Search Student

void searchStudent(int ids[], string names[],
                   double marks1[], double marks2[],
                   double marks3[], int count)
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

            cout << "Subject 1: " << marks1[i] << endl;
            cout << "Subject 2: " << marks2[i] << endl;
            cout << "Subject 3: " << marks3[i] << endl;

            found = true;
            break;
        }
    }

    if(found == false)
    {
        cout << "\nStudent not found!\n";
    }
}


// Calculate Average

double calculateAverage(double m1, double m2, double m3)
{
    return (m1 + m2 + m3) / 3.0;
}


// Calculate Grade

char calculateGrade(double average)
{
    if(average >= 75)
        return 'A';

    else if(average >= 65)
        return 'B';

    else if(average >= 50)
        return 'C';

    else if(average >= 35)
        return 'D';

    else
        return 'F';
}


// Display Examination Results

void displayResult(int ids[], string names[],
                   double marks1[], double marks2[],
                   double marks3[], int count)
{
    if(count == 0)
    {
        cout << "\nNo students available!\n";
        return;
    }

    cout << "\n========== EXAMINATION RESULTS ==========\n";

    cout << left
         << setw(10) << "ID"
         << setw(20) << "Name"
         << setw(12) << "Average"
         << setw(10) << "Grade"
         << "Status\n";

    for(int i = 0; i < count; i++)
    {
        double average = calculateAverage(
            marks1[i], marks2[i], marks3[i]
        );

        char grade = calculateGrade(average);

        string status;

        if(grade == 'F')
            status = "Fail";
        else
            status = "Pass";

        cout << left
             << setw(10) << ids[i]
             << setw(20) << names[i]
             << setw(12) << fixed << setprecision(2)
             << average
             << setw(10) << grade
             << status << endl;
    }
}


// Find Top Student

void findTopStudent(int ids[], string names[],
                    double marks1[], double marks2[],
                    double marks3[], int count)
{
    if(count == 0)
    {
        cout << "\nNo students available!\n";
        return;
    }

    int topIndex = 0;

    for(int i = 1; i < count; i++)
    {
        double current = calculateAverage(
            marks1[i], marks2[i], marks3[i]
        );

        double highest = calculateAverage(
            marks1[topIndex], marks2[topIndex],
            marks3[topIndex]
        );

        if(current > highest)
        {
            topIndex = i;
        }
    }

    cout << "\n========== TOP STUDENT ==========\n";

    cout << "Student ID: " << ids[topIndex] << endl;
    cout << "Name: " << names[topIndex] << endl;

    cout << "Average: "
         << fixed << setprecision(2)
         << calculateAverage(
                marks1[topIndex],
                marks2[topIndex],
                marks3[topIndex]
            ) << endl;

    cout << "Grade: "
         << calculateGrade(
                calculateAverage(
                    marks1[topIndex],
                    marks2[topIndex],
                    marks3[topIndex]
                )
            ) << endl;
}


// Class Statistics

void classStatistics(double marks1[], double marks2[],
                     double marks3[], int count)
{
    if(count == 0)
    {
        cout << "\nNo students available!\n";
        return;
    }

    double total = 0;

    int passCount = 0;
    int failCount = 0;

    for(int i = 0; i < count; i++)
    {
        double average = calculateAverage(
            marks1[i], marks2[i], marks3[i]
        );

        total += average;

        if(average >= 35)
            passCount++;
        else
            failCount++;
    }

    double classAverage = total / count;

    cout << "\n========== CLASS STATISTICS ==========\n";

    cout << "Total Students: " << count << endl;

    cout << "Class Average: "
         << fixed << setprecision(2)
         << classAverage << endl;

    cout << "Passed Students: " << passCount << endl;

    cout << "Failed Students: " << failCount << endl;

    cout << "Pass Percentage: "
         << (double)passCount / count * 100
         << "%" << endl;
}

