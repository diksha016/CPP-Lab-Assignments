/*Reverse a Singly Linked List*/

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

// Reverse linked list
void reverseList() {
    Node* prev = NULL;
    Node* current = head;
    Node* nextNode = NULL;

    while (current != NULL) {

        nextNode = current->next;

        current->next = prev;

        prev = current;

        current = nextNode;
    }

    head = prev;
}

// Display linked list
void display() {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL";
}

int main() {
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter linked list elements:\n";

    for (int i = 0; i < n; i++) {
        cin >> value;
        insert(value);
    }

    cout << "Original Linked List: ";
    display();

    reverseList();

    cout << "\nReversed Linked List: ";
    display();

    return 0;
}
