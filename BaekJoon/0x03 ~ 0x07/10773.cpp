#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n;
    int num;
    int sum = 0;
    stack<int> st;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> num;

        if (num == 0)
        {
            if (st.size() == 0)
            {
                continue;
            }
            sum -= st.top();
            st.pop();
        }
        else
        {
            st.push(num);
            sum += num;
        }
    }
    cout << sum;
}