/*: Display Circular Linked List with Head Repeated at the End*/

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
}

// Display with head repeated
void display() {
    if (head == NULL) {
        cout << "List is empty.";
        return;
    }

    Node* temp = head;

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << head->data;
}

int main() {
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements:\n";

    for (int i = 0; i < n; i++) {
        cin >> value;
        insert(value);
    }

    cout << "Circular Linked List: ";
    display();

    return 0;
}
