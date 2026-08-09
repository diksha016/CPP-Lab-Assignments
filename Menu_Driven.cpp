#include <iostream>
using namespace std;

int main() {
    int arr[100], n = 0, choice, i, pos, value, key;

    do {
        cout << "\n----- MENU -----";
        cout << "\n1. CREATE";
        cout << "\n2. DISPLAY";
        cout << "\n3. INSERT";
        cout << "\n4. DELETE";
        cout << "\n5. LINEAR SEARCH";
        cout << "\n6. EXIT";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter number of elements: ";
                cin >> n;

                cout << "Enter " << n << " elements:\n";
                for (i = 0; i < n; i++) {
                    cin >> arr[i];
                }
                break;

            case 2:
                if (n == 0) {
                    cout << "Array is empty!";
                } else {
                    cout << "Array elements are: ";
                    for (i = 0; i < n; i++) {
                        cout << arr[i] << " ";
                    }
                }
                break;

            case 3:
                cout << "Enter position (1 to " << n + 1 << "): ";
                cin >> pos;

                cout << "Enter value: ";
                cin >> value;

                if (pos < 1 || pos > n + 1) {
                    cout << "Invalid position!";
                } else {
                    for (i = n; i >= pos; i--) {
                        arr[i] = arr[i - 1];
                    }

                    arr[pos - 1] = value;
                    n++;

                    cout << "Element inserted successfully!";
                }
                break;

            case 4:
                cout << "Enter position to delete (1 to " << n << "): ";
                cin >> pos;

                if (pos < 1 || pos > n) {
                    cout << "Invalid position!";
                } else {
                    for (i = pos - 1; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }

                    n--;
                    cout << "Element deleted successfully!";
                }
                break;

            case 5:
                cout << "Enter element to search: ";
                cin >> key;

                for (i = 0; i < n; i++) {
                    if (arr[i] == key) {
                        cout << "Element found at position " << i + 1;
                        break;
                    }
                }

                if (i == n) {
                    cout << "Element not found!";
                }
                break;

            case 6:
                cout << "Program exited successfully!";
                break;

            default:
                cout << "Invalid choice!";
        }

    } while (choice != 6);

    return 0;
}