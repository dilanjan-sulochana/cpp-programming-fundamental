#include <iostream>
using namespace std;

void decimalToBinaryIterative(int n) {
    if (n == 0) {
        cout << "0";
        return;
    }
    int binaryNum[32];
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        cout << binaryNum[j];
    }
}

int main() {
    int number;
    cout << "Enter a decimal number: ";
    cin >> number;

    cout << "Binary equivalent: ";
    decimalToBinaryIterative(number);

    return 0;
}
