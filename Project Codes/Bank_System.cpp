
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Account
{
    int accountNumber;
    string name;
    double balance;
};

void createAccount(Account accounts[], int &count);
void displayAllAccounts(Account accounts[], int count);
int searchAccount(Account accounts[], int count, int accountNumber);
void depositMoney(Account accounts[], int count);
void withdrawMoney(Account accounts[], int count);
void checkBalance(Account accounts[], int count);
void displayAccount(Account account);

int main()
{
    Account accounts[100];
    int count = 0;
    int choice;

    do
    {
        cout << "\n===== BANK MANAGEMENT SYSTEM =====" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Display All Accounts" << endl;
        cout << "3. Search Account" << endl;
        cout << "4. Deposit Money" << endl;
        cout << "5. Withdraw Money" << endl;
        cout << "6. Check Balance" << endl;
        cout << "7. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                createAccount(accounts, count);
                break;

            case 2:
                displayAllAccounts(accounts, count);
                break;

            case 3:
            {
                int accNo;
                cout << "Enter account number: ";
                cin >> accNo;

                int index = searchAccount(accounts, count, accNo);

                if(index != -1)
                    displayAccount(accounts[index]);
                else
                    cout << "Account not found!" << endl;

                break;
            }

            case 4:
                depositMoney(accounts, count);
                break;

            case 5:
                withdrawMoney(accounts, count);
                break;

            case 6:
                checkBalance(accounts, count);
                break;

            case 7:
                cout << "Thank you for using our bank!" << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while(choice != 7);

    return 0;
}

void createAccount(Account accounts[], int &count)
{
    if(count >= 100)
    {
        cout << "Bank account limit reached!" << endl;
        return;
    }

    accounts[count].accountNumber = 1001 + count;

    cin.ignore();

    cout << "Enter customer name: ";
    getline(cin, accounts[count].name);

    cout << "Enter initial deposit: ";
    cin >> accounts[count].balance;

    if(accounts[count].balance < 0)
    {
        cout << "Invalid deposit amount!" << endl;
        accounts[count].balance = 0;
    }

    cout << "\nAccount created successfully!" << endl;
    cout << "Account Number: "
         << accounts[count].accountNumber << endl;

    count++;
}

void displayAllAccounts(Account accounts[], int count)
{
    if(count == 0)
    {
        cout << "No accounts available!" << endl;
        return;
    }

    cout << "\n===== ALL ACCOUNTS =====" << endl;

    for(int i = 0; i < count; i++)
    {
        cout << "\nAccount Number: "
             << accounts[i].accountNumber << endl;

        cout << "Name: "
             << accounts[i].name << endl;

        cout << "Balance: Rs. "
             << fixed << setprecision(2)
             << accounts[i].balance << endl;
    }
}

int searchAccount(Account accounts[], int count, int accountNumber)
{
    for(int i = 0; i < count; i++)
    {
        if(accounts[i].accountNumber == accountNumber)
        {
            return i;
        }
    }

    return -1;
}

void depositMoney(Account accounts[], int count)
{
    int accNo;
    double amount;

    cout << "Enter account number: ";
    cin >> accNo;

    int index = searchAccount(accounts, count, accNo);

    if(index == -1)
    {
        cout << "Account not found!" << endl;
        return;
    }

    cout << "Enter deposit amount: ";
    cin >> amount;

    if(amount <= 0)
    {
        cout << "Invalid amount!" << endl;
        return;
    }

    accounts[index].balance += amount;

    cout << "Deposit successful!" << endl;
    cout << "New balance: Rs. "
         << fixed << setprecision(2)
         << accounts[index].balance << endl;
}

void withdrawMoney(Account accounts[], int count)
{
    int accNo;
    double amount;

    cout << "Enter account number: ";
    cin >> accNo;

    int index = searchAccount(accounts, count, accNo);

    if(index == -1)
    {
        cout << "Account not found!" << endl;
        return;
    }

    cout << "Enter withdrawal amount: ";
    cin >> amount;

    if(amount <= 0)
    {
        cout << "Invalid amount!" << endl;
    }
    else if(amount > accounts[index].balance)
    {
        cout << "Insufficient balance!" << endl;
    }
    else
    {
        accounts[index].balance -= amount;

        cout << "Withdrawal successful!" << endl;
        cout << "Remaining balance: Rs. "
             << fixed << setprecision(2)
             << accounts[index].balance << endl;
    }
}

void checkBalance(Account accounts[], int count)
{
    int accNo;

    cout << "Enter account number: ";
    cin >> accNo;

    int index = searchAccount(accounts, count, accNo);

    if(index == -1)
    {
        cout << "Account not found!" << endl;
    }
    else
    {
        displayAccount(accounts[index]);
    }
}

void displayAccount(Account account)
{
    cout << "\n===== ACCOUNT DETAILS =====" << endl;

    cout << "Account Number: "
         << account.accountNumber << endl;

    cout << "Customer Name: "
         << account.name << endl;

    cout << "Balance: Rs. "
         << fixed << setprecision(2)
         << account.balance << endl;
}
