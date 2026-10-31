/*Find the Size of a Doubly and Circular Linked List*/
#include <iostream>
using namespace std;

// Doubly Linked List
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

// Circular Linked List
struct CNode {
    int data;
    CNode* next;
};

DNode* dHead = NULL;
CNode* cHead = NULL;

// Insert into Doubly Linked List
void insertDoubly(int value) {
    DNode* newNode = new DNode();

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (dHead == NULL) {
        dHead = newNode;
    }
    else {
        DNode* temp = dHead;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Insert into Circular Linked List
void insertCircular(int value) {
    CNode* newNode = new CNode();

    newNode->data = value;

    if (cHead == NULL) {
        cHead = newNode;
        newNode->next = cHead;
    }
    else {
        CNode* temp = cHead;

        while (temp->next != cHead) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = cHead;
    }
}

// Find size of Doubly Linked List
int sizeDoubly() {
    int count = 0;
    DNode* temp = dHead;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

// Find size of Circular Linked List
int sizeCircular() {
    if (cHead == NULL) {
        return 0;
    }

    int count = 0;
    CNode* temp = cHead;

    do {
        count++;
        temp = temp->next;
    } while (temp != cHead);

    return count;
}

int main() {
    int n, value;

    cout << "Enter number of nodes for Doubly Linked List: ";
    cin >> n;

    cout << "Enter elements:\n";

    for (int i = 0; i < n; i++) {
        cin >> value;
        insertDoubly(value);
    }

    cout << "Size of Doubly Linked List: "
         << sizeDoubly() << endl;

    cout << "\nEnter number of nodes for Circular Linked List: ";
    cin >> n;

    cout << "Enter elements:\n";

    for (int i = 0; i < n; i++) {
        cin >> value;
        insertCircular(value);
    }

    cout << "Size of Circular Linked List: "
         << sizeCircular() << endl;

    return 0;
}
