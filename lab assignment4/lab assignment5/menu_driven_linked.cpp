
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
    newNode->next = head;
    head = newNode;

    cout << "Node inserted at beginning.\n";
}

// Insert at end
void insertEnd(int value) {
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }
    else {
        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "Node inserted at end.\n";
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

    while (temp->next != NULL && temp->next->data != key) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "Target node not found.\n";
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Node inserted before " << key << ".\n";
}

// Insert after a specific value
void insertAfter(int key, int value) {
    Node* temp = head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Target node not found.\n";
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Node inserted after " << key << ".\n";
}

// Delete from beginning
void deleteBeginning() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    head = head->next;

    delete temp;

    cout << "First node deleted.\n";
}

// Delete from end
void deleteEnd() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
    }
    else {
        Node* temp = head;

        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    cout << "Last node deleted.\n";
}

// Delete a specific value
void deleteSpecific(int key) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    if (head->data == key) {
        deleteBeginning();
        return;
    }

    Node* temp = head;

    while (temp->next != NULL && temp->next->data != key) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "Node not found.\n";
        return;
    }

    Node* delNode = temp->next;
    temp->next = delNode->next;

    delete delNode;

    cout << "Node deleted successfully.\n";
}

// Search and display position
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

// Display linked list
void display() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;

    cout << "Linked List: ";

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

int main() {
    int choice, value, key;

    do {
        cout << "\n----- SINGLY LINKED LIST MENU -----\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Node\n";
        cout << "4. Insert After a Node\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete Specific Node\n";
        cout << "8. Search Node\n";
        cout << "9. Display List\n";
        cout << "10. Exit\n";

        cout << "Enter your choice: ";
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
                insertBefore(key, value);
                break;

            case 4:
                cout << "Enter target value: ";
                cin >> key;
                cout << "Enter new value: ";
                cin >> value;
                insertAfter(key, value);
                break;

            case 5:
                deleteBeginning();
                break;

            case 6:
                deleteEnd();
                break;

            case 7:
                cout << "Enter value to delete: ";
                cin >> key;
                deleteSpecific(key);
                break;

            case 8:
                cout << "Enter value to search: ";
                cin >> key;
                searchNode(key);
                break;

            case 9:
                display();
                break;

            case 10:
                cout << "Program exited.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 10);

    return 0;
}
