#include <iostream>
using namespace std;

#define MAX 5

int stack[MAX];
int top = -1;

void push() {
    int value;

    if (top == MAX - 1) {
        cout << "Stack Overflow! Stack is full.\n";
    }
    else {
        cout << "Enter value to push: ";
        cin >> value;

        top++;
        stack[top] = value;

        cout << "Element pushed successfully.\n";
    }
}

void pop() {
    if (top == -1) {
        cout << "Stack Underflow! Stack is empty.\n";
    }
    else {
        cout << "Deleted element: " << stack[top] << endl;
        top--;
    }
}

void isEmpty() {
    if (top == -1)
        cout << "Stack is Empty.\n";
    else
        cout << "Stack is Not Empty.\n";
}

void isFull() {
    if (top == MAX - 1)
        cout << "Stack is Full.\n";
    else
        cout << "Stack is Not Full.\n";
}

void display() {
    if (top == -1) {
        cout << "Stack is Empty.\n";
    }
    else {
        cout << "Stack elements are:\n";

        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }

        cout << endl;
    }
}

void peek() {
    if (top == -1) {
        cout << "Stack is Empty.\n";
    }
    else {
        cout << "Top element is: " << stack[top] << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "\n----- STACK MENU -----\n";
        cout << "1. PUSH\n";
        cout << "2. POP\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout << "5. DISPLAY\n";
        cout << "6. PEEK\n";
        cout << "7. EXIT\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                isEmpty();
                break;

            case 4:
                isFull();
                break;

            case 5:
                display();
                break;

            case 6:
                peek();
                break;

            case 7:
                cout << "Program exited successfully.\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}