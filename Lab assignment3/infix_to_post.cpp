//Write a program to convert an Infix expression into a Postfix expression. 
#include <iostream>
#include <string>
using namespace std;

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    top++;
    stack[top] = ch;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

int main() {
    string infix, postfix = "";

    cout << "Enter an infix expression: ";
    cin >> infix;

    for (int i = 0; i < infix.length(); i++) {

        char ch = infix[i];

        // If character is an operand
        if ((ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z') ||
            (ch >= '0' && ch <= '9')) {

            postfix += ch;
        }

        // If opening parenthesis
        else if (ch == '(') {
            push(ch);
        }

        // If closing parenthesis
        else if (ch == ')') {

            while (top != -1 && peek() != '(') {
                postfix += pop();
            }

            if (top != -1)
                pop();
        }

        // If operator
        else {
            while (top != -1 &&
                   peek() != '(' &&
                   precedence(peek()) >= precedence(ch)) {

                postfix += pop();
            }

            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix += pop();
    }

    cout << "Postfix expression: " << postfix;

    return 0;
}
