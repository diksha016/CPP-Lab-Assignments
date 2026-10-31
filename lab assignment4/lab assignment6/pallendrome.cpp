/*Check Whether a Doubly Linked List of Characters Is a Palindrome*/

#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

// Insert character at end
void insert(char value) {
    Node* newNode = new Node();

    newNode->data = value;
    newNode->prev = NULL;
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
        newNode->prev = temp;
    }
}

// Check palindrome
bool isPalindrome() {
    if (head == NULL) {
        return true;
    }

    Node* left = head;
    Node* right = head;

    // Move right to the last node
    while (right->next != NULL) {
        right = right->next;
    }

    // Compare from both ends
    while (left != right && left->prev != right) {

        if (left->data != right->data) {
            return false;
        }

        left = left->next;
        right = right->prev;
    }

    return true;
}

int main() {
    string str;

    cout << "Enter a string: ";
    cin >> str;

    for (int i = 0; i < str.length(); i++) {
        insert(str[i]);
    }

    if (isPalindrome()) {
        cout << "True: String is Palindrome.";
    }
    else {
        cout << "False: String is Not Palindrome.";
    }

    return 0;
}
