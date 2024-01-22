#include <iostream>
using namespace std;

// This program print out pyramid of asterisks based on user input height.
int main() {
    int rows;
    cout << "Enter the number of rows for the pyramid: ";
    cin >> rows;

    for (int i = 1; i <= rows/2 + 1; i++) {
        for (int s = 1; s <= rows - i; s++) cout << " ";
        for (int a = 1; a <= 2 * i - 1; a++) cout << "*";
        cout << endl;
    }
    for (int i = rows/2; i > 0; i--) {
        for (int s = 1; s <= rows - i; s++) cout << " ";
        for (int a = 1; a <= 2 * i - 1; a++) cout << "*";
        cout << endl;
    }
    
    return 0;
}