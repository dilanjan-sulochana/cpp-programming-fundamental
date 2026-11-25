#include <iostream>
using namespace std;

void inputMarks(int marks[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "Enter marks for subject " << i + 1 << ": ";
        cin >> marks[i];
    }
}

double calculateAverage(int marks[], int n)
{
    int total = 0;

    for(int i = 0; i < n; i++)
    {
        total = total + marks[i];
    }

    return (double)total / n;
}

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

void displayResult(double average, char grade)
{
    cout << "\n---------- RESULT ----------" << endl;
    cout << "Average Marks: " << average << endl;
    cout << "Grade: " << grade << endl;

    if(grade == 'F')
        cout << "Status: Fail" << endl;
    else
        cout << "Status: Pass" << endl;
}

int main()
{
    int marks[5];

    inputMarks(marks, 5);

    double average = calculateAverage(marks, 5);

    char grade = calculateGrade(average);

    displayResult(average, grade);

    return 0;
}
