/*Circular Linked List – Complete Program*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at beginning
void insertBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    }
    else {
        Node* temp = head;

        while (temp->next != head) {
            temp = temp->next;
        }

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    cout << "Node inserted at beginning.\n";
}

// Insert at end
void insertEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    }
    else {
        Node* temp = head;

        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    cout << "Node inserted at end.\n";
}

// Insert after a specific value
void insertAfter(int key, int value) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;

    do {
        if (temp->data == key) {
            Node* newNode = new Node();
            newNode->data = value;

            newNode->next = temp->next;
            temp->next = newNode;

            cout << "Node inserted after " << key << ".\n";
            return;
        }

        temp = temp->next;

    } while (temp != head);

    cout << "Node not found.\n";
}

// Insert before a specific value
void insertBefore(int key, int value) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    if (head->data == key) {
        insertBeginning(value);
        return;
    }

    Node* temp = head;

    while (temp->next != head && temp->next->data != key) {
        temp = temp->next;
    }

    if (temp->next == head) {
        cout << "Node not found.\n";
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;

    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Node inserted before " << key << ".\n";
}

// Delete a specific node
void deleteNode(int key) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* current = head;
    Node* previous = NULL;

    do {
        if (current->data == key) {

            // Only one node
            if (current->next == head && current == head) {
                delete current;
                head = NULL;
            }

            // Deleting head
            else if (current == head) {
                Node* last = head;

                while (last->next != head) {
                    last = last->next;
                }

                head = head->next;
                last->next = head;
                delete current;
            }

            // Deleting middle or last node
            else {
                previous->next = current->next;
                delete current;
            }

            cout << "Node deleted successfully.\n";
            return;
        }

        previous = current;
        current = current->next;

    } while (current != head);

    cout << "Node not found.\n";
}

// Search a node
void searchNode(int key) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    int position = 1;

    do {
        if (temp->data == key) {
            cout << "Node found at position: " << position << endl;
            return;
        }

        temp = temp->next;
        position++;

    } while (temp != head);

    cout << "Node not found.\n";
}

// Display list
void display() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;

    cout << "Circular Linked List: ";

    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "HEAD\n";
}

int main() {
    int choice, value, key;

    do {
        cout << "\n--- CIRCULAR LINKED LIST MENU ---\n";
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
