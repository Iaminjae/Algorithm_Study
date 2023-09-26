#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int n, num;
    string com;
    deque<int> dq;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> com;

        if (com == "push_front")
        {
            cin >> num;

            dq.push_front(num);
        }
        else if (com == "push_back")
        {
            cin >> num;

            dq.push_back(num);
        }
        else if (com == "pop_front")
        {
            if (dq.empty())
            {
                cout << -1 << '\n';
                continue;
            }
            cout << dq.front() << '\n';
            dq.pop_front();
        }
        else if (com == "pop_back")
        {
            if (dq.empty())
            {
                cout << -1 << '\n';
                continue;
            }
            cout << dq.back() << '\n';
            dq.pop_back();
        }
        else if (com == "size")
        {
            if (dq.empty())
            {
                cout << 0 << '\n';
                continue;
            }
            cout << dq.size() << '\n';
        }
        else if (com == "empty")
        {
            bool yn = dq.empty();
            cout << yn << '\n';
        }
        else if (com == "front")
        {
            if (dq.empty())
            {
                cout << -1 << '\n';
                continue;
            }
            cout << dq.front() << '\n';
        }
        else if (com == "back")
        {
            if (dq.empty())
            {
                cout << -1 << '\n';
                continue;
            }
            cout << dq.back() << '\n';
        }
    }

    return 0;
}