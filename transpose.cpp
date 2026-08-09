#include <iostream>
using namespace std;

int main() {
    int a[10][10], r, c;

    cout << "Enter number of rows and columns: ";
    cin >> r >> c;

    cout << "Enter matrix elements:\n";

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }

    cout << "\nTranspose of Matrix:\n";

    for (int j = 0; j < c; j++) {
        for (int i = 0; i < r; i++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}