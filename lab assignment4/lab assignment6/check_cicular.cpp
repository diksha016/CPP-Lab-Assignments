/*Check Whether a Linked List Is a Circular Linked List*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at end
void insert(int value) {
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
}

// Check whether linked list is circular
bool isCircular() {
    if (head == NULL) {
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    // Detect a cycle
    while (fast != NULL && fast->next != NULL) {

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {

            // Check whether cycle starts at head
            slow = head;

            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }

            return slow == head;
        }
    }

    return false;
}

// Display linked list
void display() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;

    cout << "LinkedList: ";

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

int main() {
    int n, value, choice;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements:\n";

    for (int i = 0; i < n; i++) {
        cin >> value;
        insert(value);
    }

    cout << "Should the last node point to head?\n";
    cout << "1. Yes (Circular)\n";
    cout << "2. No (Normal)\n";
    cin >> choice;

    if (head != NULL && choice == 1) {
        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = head;
    }

    if (choice == 1) {
        cout << "LinkedList: ";
        Node* temp = head;

        if (temp != NULL) {
            do {
                cout << temp->data << " -> ";
                temp = temp->next;
            } while (temp != head);

            cout << "HEAD\n";
        }
    }
    else {
        display();
    }

    if (isCircular()) {
        cout << "True: Linked List is Circular.";
    }
    else {
        cout << "False: Linked List is Not Circular.";
    }

    return 0;
}