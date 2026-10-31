/*Count Occurrences and Delete All Occurrences of a Key
Given input*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert elements at the end
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

// Count and delete all occurrences
void countAndDelete(int key) {
    int count = 0;

    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL) {

        if (temp->data == key) {
            count++;

            if (prev == NULL) {
                head = temp->next;
                delete temp;
                temp = head;
            }
            else {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
        }
        else {
            prev = temp;
            temp = temp->next;
        }
    }

    cout << "Count: " << count << endl;
}

// Display linked list
void display() {
    Node* temp = head;

    if (head == NULL) {
        cout << "List is Empty.";
        return;
    }

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL";
}

int main() {
    int n, value, key;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter linked list elements:\n";

    for (int i = 0; i < n; i++) {
        cin >> value;
        insert(value);
    }

    cout << "Enter key to count and delete: ";
    cin >> key;

    countAndDelete(key);

    cout << "Updated Linked List: ";
    display();

    return 0;
}
