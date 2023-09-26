#include <iostream>
#include <stack>

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, height;
    long long count = 0;
    stack<pair<int, int>> st;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> height;
        if (st.size() != 0)
        {
            while (!st.empty())
            {
                if (st.top().second > height)
                {
                    count += st.size();
                    break;
                }

                st.pop();
            }
        }
        st.push(make_pair(i + 1, height));
    }

    cout << count;
}