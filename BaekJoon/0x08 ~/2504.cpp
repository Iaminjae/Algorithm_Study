#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string all;
    stack<char> st;
    int res = 0, temp = 1;

    cin >> all;

    for (int i = 0; i < all.size(); i++)
    {
        if (all[i] == '(')
        {
            temp *= 2;
            st.push(all[i]);
        }
        else if (all[i] == '[')
        {
            temp *= 3;
            st.push(all[i]);
        }
        else if (all[i] == ')')
        {
            if (st.empty() || st.top() != '(')
            {
                res = 0;
                break;
            }
            if (all[i - 1] == '(')
            {
                res += temp;
                temp /= 2;
                st.pop();
            }
            else
            {
                temp /= 2;
                st.pop();
            }
        }
        else if (all[i] == ']')
        {
            if (st.empty() || st.top() != '[')
            {
                res = 0;
                break;
            }
            if (all[i - 1] == '[')
            {
                res += temp;
                temp /= 3;
                st.pop();
            }
            else
            {
                temp /= 3;
                st.pop();
            }
        }
    }

    if (!st.empty())
    {
        res = 0;
    }

    cout << res << '\n';
}