#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<char> q;
    string w;
    cout << "please enter a word" << endl;
    cin >> w;

    int count = w.length();
    for (int i = 0; i < w.length(); i++)
    {

        q.push(w[i]);
    }
    int r = q.back();
    for (int i = 0; i < w.length(); i++)
    {

        if (q.empty() == false)
        {
            if ((q.back()) - (q.front()) == 1)
            {

                break;
            }
            else
            {
                cout << (char)q.front() << (char)q.back();
                r--;
                q.pop();
            }
        }
    }
    return 0;
}