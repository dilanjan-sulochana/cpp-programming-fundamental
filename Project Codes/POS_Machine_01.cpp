
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function declarations

void displayMenu();
void displayProducts(string names[], int ids[],
                     double prices[], int stock[], int size);

void addToCart(int ids[], int stock[],
               int cart[], int size);

void viewCart(string names[], double prices[],
              int cart[], int size);

void checkout(string names[], double prices[],
              int stock[], int cart[], int size);


// Main Function

int main()
{
    const int SIZE = 5;

    int ids[SIZE] = {101, 102, 103, 104, 105};

    string names[SIZE] =
    {
        "Rice",
        "Sugar",
        "Milk",
        "Soap",
        "Biscuit"
    };

    double prices[SIZE] =
    {
        250.00, 300.00, 450.00, 180.00, 150.00
    };

    int stock[SIZE] = {50, 40, 30, 25, 60};

    int cart[SIZE] = {0, 0, 0, 0, 0};

    int choice;

    do
    {
        displayMenu();

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                displayProducts(names, ids, prices, stock, SIZE);
                break;

            case 2:
                addToCart(ids, stock, cart, SIZE);
                break;

            case 3:
                viewCart(names, prices, cart, SIZE);
                break;

            case 4:
                checkout(names, prices, stock, cart, SIZE);
                break;

            case 5:
                cout << "\nThank you for using SMART MART!\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while(choice != 5);

    return 0;
}


// Display Main Menu

void displayMenu()
{
    cout << "\n====================================\n";
    cout << "          SMART MART POS\n";
    cout << "====================================\n";

    cout << "  1. Display Products\n";
    cout << "  2. Add Item to Cart\n";
    cout << "  3. View Shopping Cart\n";
    cout << "  4. Checkout & Print Bill\n";
    cout << "  5. Exit\n";

    cout << "====================================\n";
}


// Display Products

void displayProducts(string names[], int ids[],
                     double prices[], int stock[], int size)
{
    cout << "\n========== PRODUCT LIST ==========\n";

    cout << left
         << setw(10) << "ID"
         << setw(15) << "Product"
         << setw(12) << "Price"
         << "Stock\n";

    cout << "------------------------------------------\n";

    for(int i = 0; i < size; i++)
    {
        cout << left
             << setw(10) << ids[i]
             << setw(15) << names[i]
             << setw(12) << fixed << setprecision(2)
             << prices[i]
             << stock[i] << endl;
    }

    cout << "==========================================\n";
}


// Add Items to Cart

void addToCart(int ids[], int stock[],
               int cart[], int size)
{
    int id, quantity;
    int index = -1;

    cout << "\nEnter Product ID: ";
    cin >> id;

    for(int i = 0; i < size; i++)
    {
        if(ids[i] == id)
        {
            index = i;
            break;
        }
    }

    if(index == -1)
    {
        cout << "\nProduct not found!\n";
        return;
    }

    cout << "Available Stock: "
         << stock[index] - cart[index] << endl;

    cout << "Enter Quantity: ";
    cin >> quantity;

    if(quantity <= 0)
    {
        cout << "\nInvalid quantity!\n";
    }
    else if(quantity > stock[index] - cart[index])
    {
        cout << "\nNot enough stock available!\n";
    }
    else
    {
        cart[index] += quantity;

        cout << "\nItem added successfully!\n";
    }
}


// View Shopping Cart

void viewCart(string names[], double prices[],
              int cart[], int size)
{
    double total = 0;
    bool empty = true;

    cout << "\n========== SHOPPING CART ==========\n";

    cout << left
         << setw(15) << "Product"
         << setw(10) << "Qty"
         << setw(12) << "Price"
         << "Total\n";

    cout << "------------------------------------------\n";

    for(int i = 0; i < size; i++)
    {
        if(cart[i] > 0)
        {
            empty = false;

            double itemTotal = prices[i] * cart[i];

            cout << left
                 << setw(15) << names[i]
                 << setw(10) << cart[i]
                 << setw(12) << fixed << setprecision(2)
                 << prices[i]
                 << itemTotal << endl;

            total += itemTotal;
        }
    }

    if(empty)
    {
        cout << "Your cart is empty!\n";
    }
    else
    {
        cout << "------------------------------------------\n";

        cout << "Subtotal: Rs. "
             << fixed << setprecision(2) << total << endl;
    }
}


// Checkout and Generate Bill

void checkout(string names[], double prices[],
              int stock[], int cart[], int size)
{
    double subtotal = 0;
    double discount = 0;
    double finalTotal = 0;
    double payment, change;

    bool empty = true;

    for(int i = 0; i < size; i++)
    {
        if(cart[i] > 0)
        {
            empty = false;
            subtotal += prices[i] * cart[i];
        }
    }

    if(empty)
    {
        cout << "\nYour cart is empty!\n";
        return;
    }

    // Calculate Discount

    if(subtotal >= 10000)
    {
        discount = subtotal * 0.10;
    }
    else if(subtotal >= 5000)
    {
        discount = subtotal * 0.05;
    }

    finalTotal = subtotal - discount;

    // Display Bill

    cout << "\n";
    cout << "====================================\n";
    cout << "          SMART MART\n";
    cout << "          CUSTOMER BILL\n";
    cout << "====================================\n";

    cout << left
         << setw(15) << "Product"
         << setw(8) << "Qty"
         << "Total\n";

    cout << "------------------------------------\n";

    for(int i = 0; i < size; i++)
    {
        if(cart[i] > 0)
        {
            cout << left
                 << setw(15) << names[i]
                 << setw(8) << cart[i]
                 << fixed << setprecision(2)
                 << prices[i] * cart[i] << endl;
        }
    }

    cout << "------------------------------------\n";

    cout << "Subtotal     : Rs. " << subtotal << endl;
    cout << "Discount     : Rs. " << discount << endl;

    cout << "Final Amount : Rs. " << finalTotal << endl;

    // Customer Payment

    do
    {
        cout << "\nEnter Payment: Rs. ";
        cin >> payment;

        if(payment < finalTotal)
        {
            cout << "Insufficient payment! Try again.\n";
        }

    } while(payment < finalTotal);

    change = payment - finalTotal;

    // Update Stock

    for(int i = 0; i < size; i++)
    {
        stock[i] -= cart[i];
        cart[i] = 0;
    }

    // Final Receipt

    cout << "\n====================================\n";
    cout << "          PAYMENT RECEIPT\n";
    cout << "====================================\n";

    cout << "Total Amount : Rs. " << finalTotal << endl;
    cout << "Paid Amount  : Rs. " << payment << endl;
    cout << "Change       : Rs. " << change << endl;

    cout << "====================================\n";
    cout << "       THANK YOU! COME AGAIN\n";
    cout << "====================================\n";
}
