#include <iostream>
#include <stack>

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    string all;
    stack<pair<int, char>> st;
    int lazer = 0;
    int sum = 0;
    cin >> all;

    for (int i = 0; i < all.size(); i++)
    {
        if (all[i] == ')')
        {
            if (st.top().first == i - 1)
            {
                if (i - 1 == 0)
                {
                    st.pop();
                    continue;
                }
                st.pop();
                sum += st.size();
                continue;
            }
            sum += 1;
            st.pop();
            continue;
        }

        st.push(make_pair(i, all[i]));
    }
    cout << sum;
}