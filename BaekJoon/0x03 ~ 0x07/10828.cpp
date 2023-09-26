#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n;
    string command;
    int num;
    stack<int> st;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> command;

        if (command == "push")
        {
            cin >> num;

            st.push(num);
        }
        else if (command == "pop")
        {
            if (st.size() < 1)
            {
                cout << -1 << '\n';
                continue;
            }
            cout << st.top() << '\n';
            st.pop();
        }
        else if (command == "size")
        {
            cout << st.size() << '\n';
        }
        else if (command == "empty")
        {
            bool i = st.empty();

            cout << i << '\n';
        }
        else if (command == "top")
        {
            if (st.size() < 1)
            {
                cout << -1 << '\n';
                continue;
            }
            cout << st.top() << '\n';
        }
    }
}