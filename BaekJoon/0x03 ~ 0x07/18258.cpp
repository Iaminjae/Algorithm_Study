#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, num;
    string command;
    queue<int> q;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> command;

        if (command == "push")
        {
            cin >> num;
            q.push(num);
        }
        else if (command == "pop")
        {
            if (q.empty())
            {
                cout << -1 << '\n';
                continue;
            }
            cout << q.front() << '\n';
            q.pop();
        }
        else if (command == "size")
        {
            if (q.empty())
            {
                cout << 0 << '\n';
                continue;
            }
            cout << q.size() << '\n';
        }
        else if (command == "empty")
        {
            bool zon;
            zon = q.empty();
            cout << zon << '\n';
        }
        else if (command == "front")
        {
            if (q.empty())
            {
                cout << -1 << '\n';
                continue;
            }
            cout << q.front() << '\n';
        }
        else if (command == "back")
        {
            if (q.empty())
            {
                cout << -1 << '\n';
                continue;
            }
            cout << q.back() << '\n';
        }
    }

    return 0;
}