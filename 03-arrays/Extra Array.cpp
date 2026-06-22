#include <iostream>
using namespace std;

int main() {
    int arr[5];

    // Input elements
    for (int i = 0; i < 5; i++) {
        cout << "Enter 5 integers: ";
        cin >> arr[i];
    }

    // Output elements
    cout << "You entered: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
