

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Product
{
    int id;
    string name;
    double price;
    int stock;
};

struct CartItem
{
    int productIndex;
    int quantity;
};

void displayProducts(Product products[], int count);
int searchProduct(Product products[], int count, int id);
void addProduct(Product products[], int &count);
void updateStock(Product products[], int count);
void processSale(Product products[], int count,
                 double &totalSales, int &totalItemsSold);
void salesReport(double totalSales, int totalItemsSold);

int main()
{
    Product products[100] =
    {
        {101, "Rice", 250.00, 50},
        {102, "Sugar", 300.00, 40},
        {103, "Milk", 450.00, 30},
        {104, "Soap", 180.00, 25},
        {105, "Tea", 500.00, 20}
    };

    int count = 5;

    double totalSales = 0;
    int totalItemsSold = 0;

    int choice;

    do
    {
        cout << "\n========== ADVANCED POS ==========" << endl;
        cout << "1. Display Products" << endl;
        cout << "2. New Sale" << endl;
        cout << "3. Add New Product" << endl;
        cout << "4. Update Stock" << endl;
        cout << "5. Sales Report" << endl;
        cout << "6. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                displayProducts(products, count);
                break;

            case 2:
                processSale(products, count,
                            totalSales, totalItemsSold);
                break;

            case 3:
                addProduct(products, count);
                break;

            case 4:
                updateStock(products, count);
                break;

            case 5:
                salesReport(totalSales, totalItemsSold);
                break;

            case 6:
                cout << "POS System Closed!" << endl;
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while(choice != 6);

    return 0;
}

// Display all products
void displayProducts(Product products[], int count)
{
    cout << "\n========== PRODUCT LIST ==========" << endl;

    cout << left << setw(10) << "ID"
         << setw(20) << "Name"
         << setw(12) << "Price"
         << "Stock" << endl;

    for(int i = 0; i < count; i++)
    {
        cout << left << setw(10) << products[i].id
             << setw(20) << products[i].name
             << setw(12) << fixed << setprecision(2)
             << products[i].price
             << products[i].stock << endl;
    }
}

// Search product by ID
int searchProduct(Product products[], int count, int id)
{
    for(int i = 0; i < count; i++)
    {
        if(products[i].id == id)
        {
            return i;
        }
    }

    return -1;
}

// Add a new product
void addProduct(Product products[], int &count)
{
    if(count >= 100)
    {
        cout << "Product storage is full!" << endl;
        return;
    }

    int id;

    cout << "Enter Product ID: ";
    cin >> id;

    if(searchProduct(products, count, id) != -1)
    {
        cout << "Product ID already exists!" << endl;
        return;
    }

    cin.ignore();

    cout << "Enter Product Name: ";
    getline(cin, products[count].name);

    cout << "Enter Price: ";
    cin >> products[count].price;

    cout << "Enter Stock Quantity: ";
    cin >> products[count].stock;

    if(products[count].price <= 0 ||
       products[count].stock < 0)
    {
        cout << "Invalid product details!" << endl;
        return;
    }

    products[count].id = id;

    count++;

    cout << "Product added successfully!" << endl;
}

// Update existing stock
void updateStock(Product products[], int count)
{
    int id;
    int quantity;

    cout << "Enter Product ID: ";
    cin >> id;

    int index = searchProduct(products, count, id);

    if(index == -1)
    {
        cout << "Product not found!" << endl;
        return;
    }

    cout << "Current Stock: "
         << products[index].stock << endl;

    cout << "Enter quantity to add: ";
    cin >> quantity;

    if(quantity <= 0)
    {
        cout << "Invalid quantity!" << endl;
        return;
    }

    products[index].stock += quantity;

    cout << "Stock updated successfully!" << endl;

    cout << "New Stock: "
         << products[index].stock << endl;
}

// Process customer sale
void processSale(Product products[], int count,
                 double &totalSales, int &totalItemsSold)
{
    CartItem cart[100];

    int cartCount = 0;
    int id;
    int quantity;

    double subtotal = 0;
    double discount = 0;
    double finalTotal = 0;
    double payment = 0;
    double change = 0;

    cout << "\n========== NEW SALE ==========" << endl;

    displayProducts(products, count);

    cout << "\nEnter 0 to finish adding items." << endl;

    while(true)
    {
        cout << "\nEnter Product ID: ";
        cin >> id;

        if(id == 0)
            break;

        int index = searchProduct(products, count, id);

        if(index == -1)
        {
            cout << "Product not found!" << endl;
            continue;
        }

        cout << "Product: " << products[index].name << endl;
        cout << "Available Stock: "
             << products[index].stock << endl;

        cout << "Enter quantity: ";
        cin >> quantity;

        if(quantity <= 0)
        {
            cout << "Invalid quantity!" << endl;
            continue;
        }

        // Check whether product already exists in cart
        int cartIndex = -1;

        for(int i = 0; i < cartCount; i++)
        {
            if(cart[i].productIndex == index)
            {
                cartIndex = i;
                break;
            }
        }

        int alreadyInCart = 0;

        if(cartIndex != -1)
        {
            alreadyInCart = cart[cartIndex].quantity;
        }

        // Check available stock
        if(quantity + alreadyInCart > products[index].stock)
        {
            cout << "Insufficient stock!" << endl;
            continue;
        }

        // Add item to cart
        if(cartIndex != -1)
        {
            cart[cartIndex].quantity += quantity;
        }
        else
        {
            cart[cartCount].productIndex = index;
            cart[cartCount].quantity = quantity;

            cartCount++;
        }

        cout << "Item added to cart!" << endl;
    }

    if(cartCount == 0)
    {
        cout << "No items selected!" << endl;
        return;
    }

    // Calculate subtotal
    for(int i = 0; i < cartCount; i++)
    {
        int index = cart[i].productIndex;

        subtotal += products[index].price
                    * cart[i].quantity;
    }

    // Discount calculation
    if(subtotal >= 10000)
    {
        discount = subtotal * 0.10;
    }
    else if(subtotal >= 5000)
    {
        discount = subtotal * 0.05;
    }

    finalTotal = subtotal - discount;

    // Display bill
    cout << "\n========== CUSTOMER BILL ==========" << endl;

    cout << left << setw(20) << "Product"
         << setw(10) << "Qty"
         << setw(12) << "Price"
         << "Total" << endl;

    for(int i = 0; i < cartCount; i++)
    {
        int index = cart[i].productIndex;

        double itemTotal = products[index].price
                           * cart[i].quantity;

        cout << left << setw(20) << products[index].name
             << setw(10) << cart[i].quantity
             << setw(12) << fixed << setprecision(2)
             << products[index].price
             << itemTotal << endl;
    }

    cout << "\nSubtotal: Rs. " << subtotal << endl;
    cout << "Discount: Rs. " << discount << endl;
    cout << "Final Total: Rs. " << finalTotal << endl;

    // Payment
    cout << "\nEnter customer payment: Rs. ";
    cin >> payment;

    if(payment < finalTotal)
    {
        cout << "Insufficient payment!" << endl;
        cout << "Sale cancelled!" << endl;
        return;
    }

    change = payment - finalTotal;

    // Deduct stock only after successful payment
    for(int i = 0; i < cartCount; i++)
    {
        int index = cart[i].productIndex;

        products[index].stock -= cart[i].quantity;

        totalItemsSold += cart[i].quantity;
    }

    totalSales += finalTotal;

    cout << "\n========== PAYMENT RECEIPT ==========" << endl;

    cout << "Subtotal: Rs. " << subtotal << endl;
    cout << "Discount: Rs. " << discount << endl;
    cout << "Paid: Rs. " << payment << endl;
    cout << "Change: Rs. " << change << endl;

    cout << "\nSale completed successfully!" << endl;
}

// Display sales report
void salesReport(double totalSales, int totalItemsSold)
{
    cout << "\n========== SALES REPORT ==========" << endl;

    cout << "Total Revenue: Rs. "
         << fixed << setprecision(2)
         << totalSales << endl;

    cout << "Total Items Sold: "
         << totalItemsSold << endl;
}
