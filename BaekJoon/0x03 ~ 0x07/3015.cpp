#include <iostream>
#include <stack>

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int num, count = 0;
    int a[500001];
    int see[500001] = {0};
    stack<int> st;

    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < num; i++)
    {

        while (!st.empty())
        {
            if (a[i] > a[st.top()])
            {
                count++;
                st.pop();
                continue;
            }
            see[st.top()] = 1;
            st.pop();
            count++;
        }

        for (int j = 0; j < i; j++)
        {
            if (see[j] == 1)
            {
                st.push(see[j]);
                see[j] = 0;
            }
        }

        st.push(i);
    }

    cout << count;
}