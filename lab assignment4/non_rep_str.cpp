#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    string str;

    cout << "Enter the string: ";
    cin >> str;

    queue<char> q;

    int frequency[256] = {0};

    cout << "First non-repeating characters: ";

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        // Increase the frequency of the current character
        frequency[ch]++;

        // Insert the current character into the queue
        q.push(ch);

        // Remove repeating characters from the front
        while (!q.empty() && frequency[q.front()] > 1)
        {
            q.pop();
        }

        // Display the first non-repeating character
        if (q.empty())
        {
            cout << -1 << " ";
        }
        else
        {
            cout << q.front() << " ";
        }
    }

    cout << endl;

    return 0;
}