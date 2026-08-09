#include <iostream>
using namespace std;

int main() {
    int arr[10][10], r, c, sum;

    cout << "Enter number of rows and columns: ";
    cin >> r >> c;

    cout << "Enter matrix elements:\n";

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }

    // Sum of each row
    cout << "\nSum of rows:\n";

    for (int i = 0; i < r; i++) {
        sum = 0;

        for (int j = 0; j < c; j++) {
            sum += arr[i][j];
        }

        cout << "Row " << i + 1 << " = " << sum << endl;
    }

    // Sum of each column
    cout << "\nSum of columns:\n";

    for (int j = 0; j < c; j++) {
        sum = 0;

        for (int i = 0; i < r; i++) {
            sum += arr[i][j];
        }

        cout << "Column " << j + 1 << " = " << sum << endl;
    }

    return 0;
}