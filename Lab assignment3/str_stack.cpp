#include <iostream>
#include <string>
using namespace std;

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    if (top == MAX - 1) {
        cout << "Stack Overflow!";
    }
    else {
        top++;
        stack[top] = ch;
    }
}

char pop() {
    if (top == -1) {
        return '\0';
    }
    else {
        return stack[top--];
    }
}

int main() {
    string str;

    cout << "Enter a string: ";
    cin >> str;

    // Push every character into the stack
    for (int i = 0; i < str.length(); i++) {
        push(str[i]);
    }

    cout << "Reversed string: ";

    // Pop every character from the stack
    while (top != -1) {
        cout << pop();
    }

    return 0;
}

