//Write a program for the evaluation of a Postfix expression. 
#include <iostream>
#include <string>
using namespace std;

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    top++;
    stack[top] = value;
}

int pop() {
    return stack[top--];
}

int main() {
    string postfix;

    cout << "Enter a postfix expression: ";
    cin >> postfix;

    for (int i = 0; i < postfix.length(); i++) {

        char ch = postfix[i];

        // If character is an operand
        if (ch >= '0' && ch <= '9') {
            push(ch - '0');
        }

        // If character is an operator
        else {
            int operand2 = pop();
            int operand1 = pop();
            int result;

            switch (ch) {

                case '+':
                    result = operand1 + operand2;
                    break;

                case '-':
                    result = operand1 - operand2;
                    break;

                case '*':
                    result = operand1 * operand2;
                    break;

                case '/':
                    result = operand1 / operand2;
                    break;

                default:
                    cout << "Invalid operator!";
                    return 0;
            }

            push(result);
        }
    }

    cout << "Result = " << pop();

    return 0;
}

