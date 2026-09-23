#include <iostream>
using namespace std;
#define MAX 5

int queueArr[MAX];
int front = -1;
int rear = -1;

bool isEmpty()
{
    return front == -1;
}

bool isFull()
{
    return (rear + 1) % MAX == front;
}

// Function to insert an element into the circular queue
void enqueue(int value)
{
    if (isFull())
    {
        cout << "Queue Overflow! Queue is full." << endl;
        return;
        
    }

    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }

    queueArr[rear] = value;

    cout << value << " inserted into the queue." << endl;
}

// Function to remove an element from the circular queue
void dequeue()
{
    if (isEmpty())
    {
        cout << "Queue Underflow! Queue is empty." << endl;
        return;
    }

    cout << queueArr[front] << " removed from the queue." << endl;

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

// Function to display all elements of the circular queue
void display()
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Queue elements are: ";

    int i = front;

    do
    {
        cout << queueArr[i] << " ";
        i = (i + 1) % MAX;
    }
    while (i != (rear + 1) % MAX);

    cout << endl;
}

// Function to display the front element
void peek()
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Front element is: " << queueArr[front] << endl;
}

// Main function
int main()
{
    int choice;
    int value;

    do
    {
        cout << "\n===== CIRCULAR QUEUE MENU =====" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Check Empty" << endl;
        cout << "4. Check Full" << endl;
        cout << "5. Display" << endl;
        cout << "6. Peek" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                if (isEmpty())
                {
                    cout << "Queue is empty." << endl;
                }
                else
                {
                    cout << "Queue is not empty." << endl;
                }
                break;

            case 4:
                if (isFull())
                {
                    cout << "Queue is full." << endl;
                }
                else
                {
                    cout << "Queue is not full." << endl;
                }
                break;

            case 5:
                display();
                break;

            case 6:
                peek();
                break;

            case 7:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 7);

    return 0;
}