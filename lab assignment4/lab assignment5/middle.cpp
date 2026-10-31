/*Find the Middle of a Linked List*/

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

// Find middle node
void findMiddle() {
    if (head == NULL) {
        cout << "List is Empty.";
        return;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "Middle element: " << slow->data;
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

    findMiddle();

    return 0;
}
