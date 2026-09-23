#include <iostream>
#include <queue>
using namespace std;

class StackUsingTwoQueues
{
private:
    queue<int> q1;
    queue<int> q2;

public:

    // Push operation
    void push(int value)
    {
        // Insert the new element into q2
        q2.push(value);

        // Move all elements from q1 to q2
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap q1 and q2
        swap(q1, q2);

        cout << value << " pushed into the stack." << endl;
    }

    // Pop operation
    void pop()
    {
        if (q1.empty())
        {
            cout << "Stack Underflow! Stack is empty." << endl;
            return;
        }

        cout << q1.front() << " popped from the stack." << endl;
        q1.pop();
    }

    // Peek operation
    void peek()
    {
        if (q1.empty())
        {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Top element is: " << q1.front() << endl;
    }

    // Check whether stack is empty
    bool isEmpty()
    {
        return q1.empty();
    }

    // Display stack elements
    void display()
    {
        if (q1.empty())
        {
            cout << "Stack is empty." << endl;
            return;
        }

        queue<int> temp = q1;

        cout << "Stack elements are: ";

        while (!temp.empty())
        {
            cout << temp.front() << " ";
            temp.pop();
        }

        cout << endl;
    }
};

int main()
{
    StackUsingTwoQueues s;

    int choice;
    int value;

    do
    {
        cout << "\n===== STACK USING TWO QUEUES =====" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Check Empty" << endl;
        cout << "5. Display" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.peek();
                break;

            case 4:
                if (s.isEmpty())
                {
                    cout << "Stack is empty." << endl;
                }
                else
                {
                    cout << "Stack is not empty." << endl;
                }
                break;

            case 5:
                s.display();
                break;

            case 6:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 6);

    return 0;
}