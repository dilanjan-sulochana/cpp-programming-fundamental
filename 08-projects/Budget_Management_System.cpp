
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int SIZE = 5;

// Function Declarations

void displayMenu();

void displayCategories(string categories[]);

void addIncome(double &income);

void addExpense(string categories[],
                double expenses[],
                double budgets[],
                double &income);

void setBudget(string categories[],
               double budgets[]);

void displayBudget(string categories[],
                   double expenses[],
                   double budgets[]);

double calculateTotalExpenses(double expenses[]);

void financialSummary(double income,
                      double expenses[]);


// Main Function

int main()
{
    string categories[SIZE] =
    {
        "Food",
        "Transport",
        "Education",
        "Bills",
        "Other"
    };

    double expenses[SIZE] = {0, 0, 0, 0, 0};

    double budgets[SIZE] = {0, 0, 0, 0, 0};

    double income = 0;

    int choice;

    do
    {
        displayMenu();

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                addIncome(income);
                break;

            case 2:
                addExpense(categories, expenses,
                           budgets, income);
                break;

            case 3:
                setBudget(categories, budgets);
                break;

            case 4:
                displayBudget(categories, expenses,
                              budgets);
                break;

            case 5:
                financialSummary(income, expenses);
                break;

            case 6:
                cout << "\nThank you for using Smart Budget!\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while(choice != 6);

    return 0;
}


// Display Main Menu

void displayMenu()
{
    cout << "\n====================================\n";
    cout << "       SMART BUDGET MANAGER\n";
    cout << "====================================\n";

    cout << "1. Add Monthly Income\n";
    cout << "2. Add Expense\n";
    cout << "3. Set Category Budget\n";
    cout << "4. View Budget Details\n";
    cout << "5. Financial Summary\n";
    cout << "6. Exit\n";

    cout << "====================================\n";
}


// Display Categories

void displayCategories(string categories[])
{
    cout << "\n========== EXPENSE CATEGORIES ==========\n";

    for(int i = 0; i < SIZE; i++)
    {
        cout << i + 1 << ". " << categories[i] << endl;
    }
}


// Add Monthly Income

void addIncome(double &income)
{
    double amount;

    cout << "\nEnter Monthly Income: Rs. ";
    cin >> amount;

    if(amount <= 0)
    {
        cout << "Invalid income amount!\n";
    }
    else
    {
        income += amount;

        cout << "\nIncome added successfully!\n";

        cout << "Total Income: Rs. "
             << fixed << setprecision(2)
             << income << endl;
    }
}


// Add Expense

void addExpense(string categories[],
                double expenses[],
                double budgets[],
                double &income)
{
    int choice;
    double amount;

    displayCategories(categories);

    cout << "\nSelect Category: ";
    cin >> choice;

    if(choice < 1 || choice > SIZE)
    {
        cout << "Invalid category!\n";
        return;
    }

    int index = choice - 1;

    cout << "Enter Expense Amount: Rs. ";
    cin >> amount;

    if(amount <= 0)
    {
        cout << "Invalid expense amount!\n";
        return;
    }

    if(amount > income - calculateTotalExpenses(expenses))
    {
        cout << "Insufficient available balance!\n";
        return;
    }

    expenses[index] += amount;

    cout << "\nExpense added successfully!\n";

    cout << "Category: " << categories[index] << endl;

    cout << "Category Total: Rs. "
         << expenses[index] << endl;

    // Budget Warning

    if(budgets[index] > 0)
    {
        if(expenses[index] > budgets[index])
        {
            cout << "\nWARNING: Budget Exceeded!\n";
        }
        else if(expenses[index] == budgets[index])
        {
            cout << "\nWARNING: Budget Limit Reached!\n";
        }
        else if(expenses[index] >= budgets[index] * 0.80)
        {
            cout << "\nWARNING: You have used 80% of your budget!\n";
        }
    }
}


// Set Category Budget

void setBudget(string categories[],
               double budgets[])
{
    int choice;
    double amount;

    displayCategories(categories);

    cout << "\nSelect Category: ";
    cin >> choice;

    if(choice < 1 || choice > SIZE)
    {
        cout << "Invalid category!\n";
        return;
    }

    int index = choice - 1;

    cout << "Enter Budget Limit: Rs. ";
    cin >> amount;

    if(amount <= 0)
    {
        cout << "Invalid budget amount!\n";
        return;
    }

    budgets[index] = amount;

    cout << "\nBudget set successfully!\n";

    cout << "Category: " << categories[index] << endl;

    cout << "Budget: Rs. "
         << fixed << setprecision(2)
         << budgets[index] << endl;
}


// Calculate Total Expenses

double calculateTotalExpenses(double expenses[])
{
    double total = 0;

    for(int i = 0; i < SIZE; i++)
    {
        total += expenses[i];
    }

    return total;
}


// Display Budget Details

void displayBudget(string categories[],
                   double expenses[],
                   double budgets[])
{
    cout << "\n========== BUDGET DETAILS ==========\n";

    cout << left
         << setw(15) << "Category"
         << setw(15) << "Budget"
         << setw(15) << "Spent"
         << "Remaining\n";

    cout << "------------------------------------------------\n";

    for(int i = 0; i < SIZE; i++)
    {
        cout << left
             << setw(15) << categories[i]
             << setw(15) << fixed << setprecision(2)
             << budgets[i]
             << setw(15) << expenses[i];

        cout << budgets[i] - expenses[i] << endl;

        if(budgets[i] > 0)
        {
            if(expenses[i] > budgets[i])
            {
                cout << "  -> Budget Exceeded!\n";
            }
            else if(expenses[i] >= budgets[i] * 0.80)
            {
                cout << "  -> Budget Warning!\n";
            }
        }
    }
}


// Financial Summary

void financialSummary(double income,
                      double expenses[])
{
    double totalExpenses = calculateTotalExpenses(expenses);

    double balance = income - totalExpenses;

    cout << "\n====================================\n";
    cout << "        FINANCIAL SUMMARY\n";
    cout << "====================================\n";

    cout << "Total Income    : Rs. "
         << fixed << setprecision(2)
         << income << endl;

    cout << "Total Expenses  : Rs. "
         << totalExpenses << endl;

    cout << "Remaining Money : Rs. "
         << balance << endl;

    cout << "====================================\n";
}

