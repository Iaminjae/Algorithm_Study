#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n, num = 0;
    string ps;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        bool vps = true;
        stack<char> st;
        cin >> ps;

        for (int j = 0; j < ps.size(); j++)
        {
            if (!st.empty() && ps[j] == ')')
            {
                st.pop();
                continue;
            }
            else if (st.empty() && ps[j] == ')')
            {
                vps = false;
                break;
            }
            st.push(ps[j]);
        }

        if (!st.empty())
        {
            vps = false;
        }

        if (vps && st.empty())
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
}