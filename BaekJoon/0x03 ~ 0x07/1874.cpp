#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    int n;
    int num;
    vector<char> pm;
    bool a = true;
    int count = 0;
    stack<int> st;
    st.push(count);
    count++;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> num;

        while (st.top() != num)
        {
            if (st.top() >= n && st.top() != num)
            {
                a = false;
                break;
            }
            st.push(count);
            count++;

            pm.push_back('+');
        }

        st.pop();
        pm.push_back('-');
    }

    if (a == false)
    {
        cout << "NO" << '\n';
        return 0;
    }

    for (int i = 0; i < pm.size(); i++)
    {
        cout << pm[i] << '\n';
    }
}