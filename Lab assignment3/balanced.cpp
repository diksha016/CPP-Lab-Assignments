#include<iostream>
#include<string>
using namespace std;
#define MAX 5
char stack[MAX];
int top = -1;
void push(char ch){
    if (top < MAX - 1){
        top++;
        stack[top] = ch;
        }

}
char pop(){
    if (top != -1){
        return stack[top--];
    }
    return '\0';
}
int main(){
    string expression;
    cout<<"Enter an expression: ";
    cin>>expression;
    for(int i = 0 ; i < expression.length() ; i++){
        if (expression[i] == '('){
            push(expression[i]);

        }
        else if (expression[i] == ')'){
            if (top == -1)
        {
            cout<<"Parenthesis not balanced"<<endl;
            return 0;
        }
        pop();
    }
}  
    if (top ==  -1){
        cout<<"parenthesis is balanced"<<endl;
    }
    else
    { cout << "parenthesis is not balanced"<<endl;}
    return 0;
}