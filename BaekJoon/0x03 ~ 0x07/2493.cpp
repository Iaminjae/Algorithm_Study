#include <iostream>
#include <stack>

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, height;
    stack<pair<int, int>> st;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> height;

        while (!st.empty())
        {
            if (height < st.top().second)
            {
                cout << st.top().first << " ";
                break;
            }
            st.pop();
        }

        if (st.empty())
        {
            cout << 0 << " ";
        }
        st.push(make_pair(i + 1, height));
    }
}