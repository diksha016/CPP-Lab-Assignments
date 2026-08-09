#include <iostream>
using namespace std;

int main() {
    int arr[100], n, k, choice;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter number of positions to rotate: ";
    cin >> k;

    k = k % n;

    cout << "\n1. Left Rotation";
    cout << "\n2. Right Rotation";
    cout << "\nEnter your choice: ";
    cin >> choice;

    if (choice == 1) {
        for (int r = 0; r < k; r++) {
            int first = arr[0];

            for (int i = 0; i < n - 1; i++) {
                arr[i] = arr[i + 1];
            }

            arr[n - 1] = first;
        }
    }
    else if (choice == 2) {
        for (int r = 0; r < k; r++) {
            int last = arr[n - 1];

            for (int i = n - 1; i > 0; i--) {
                arr[i] = arr[i - 1];
            }

            arr[0] = last;
        }
    }

    cout << "\nArray after rotation:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}