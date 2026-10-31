
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

// Insert at beginning
void insertBeginning(int value) {
    Node* newNode = new Node();

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode;

    cout << "Node inserted at beginning.\n";
}

// Insert at end
void insertEnd(int value) {
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    }
    else {
        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    cout << "Node inserted at end.\n";
}

// Insert after a specific value
void insertAfter(int key, int value) {
    Node* temp = head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Node not found.\n";
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;

    cout << "Node inserted after " << key << ".\n";
}

// Insert before a specific value
void insertBefore(int key, int value) {
    Node* temp = head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Node not found.\n";
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;

    newNode->prev = temp->prev;
    newNode->next = temp;

    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    }
    else {
        head = newNode;
    }

    temp->prev = newNode;

    cout << "Node inserted before " << key << ".\n";
}

// Delete a specific node
void deleteNode(int key) {
    Node* temp = head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Node not found.\n";
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    else {
        head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    delete temp;

    cout << "Node deleted successfully.\n";
}

// Search a node
void searchNode(int key) {
    Node* temp = head;
    int position = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Node found at position: " << position << endl;
            return;
        }

        temp = temp->next;
        position++;
    }

    cout << "Node not found.\n";
}

// Display list
void display() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;

    cout << "Doubly Linked List: ";

    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

int main() {
    int choice, value, key;

    do {
        cout << "\n--- DOUBLY LINKED LIST MENU ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Node\n";
        cout << "4. Insert Before a Node\n";
        cout << "5. Delete Specific Node\n";
        cout << "6. Search Node\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertBeginning(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertEnd(value);
                break;

            case 3:
                cout << "Enter target value: ";
                cin >> key;
                cout << "Enter new value: ";
                cin >> value;
                insertAfter(key, value);
                break;

            case 4:
                cout << "Enter target value: ";
                cin >> key;
                cout << "Enter new value: ";
                cin >> value;
                insertBefore(key, value);
                break;

            case 5:
                cout << "Enter value to delete: ";
                cin >> key;
                deleteNode(key);
                break;

            case 6:
                cout << "Enter value to search: ";
                cin >> key;
                searchNode(key);
                break;

            case 7:
                display();
                break;

            case 8:
                cout << "Program exited.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 8);

    return 0;
}
