// CPP code to illustrate
// Queue in Standard Template Library (STL)
#include <iostream>
#include <queue>

using namespace std;

// Print the queue
void showq(queue<int> gq)
{
    queue<int> g = gq;
    while (!g.empty())
    {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
}

// Driver Code
int main()
{

    queue<int> queue;
    int x, y;
    x = 4;
    y = 5;

    queue.push(x);
    queue.push(y);
    x = queue.front();
    queue.pop();
    queue.push(x + 5);
    queue.push(16);
    queue.push(x);
    queue.push(y - 3);
    cout << "Queue Elements: ";
    while (!queue.empty())
    {
        cout << queue.front() << " ";
        queue.pop();
    }
    cout << endl;
    return 0;
}
