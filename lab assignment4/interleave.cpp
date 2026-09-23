#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    queue<int> q1;
    queue<int> q2;

    int n, value;

    cout << "Enter the number of elements: ";
    cin >> n;

    if (n % 2 != 0)
    {
        cout << "Please enter an even number of elements." << endl;
        return 0;
    }

    cout << "Enter the queue elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        q.push(value);
    }

    int half = n / 2;

    // Store the first half in q1
    for (int i = 0; i < half; i++)
    {
        q1.push(q.front());
        q.pop();
    }

    // Store the second half in q2
    while (!q.empty())
    {
        q2.push(q.front());
        q.pop();
    }

    // Interleave both halves
    while (!q1.empty() && !q2.empty())
    {
        q.push(q1.front());
        q1.pop();

        q.push(q2.front());
        q2.pop();
    }

    // Display the interleaved queue
    cout << "Interleaved queue: ";

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;

    return 0;
}