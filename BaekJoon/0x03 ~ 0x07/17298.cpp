#include <iostream>
#include <stack>

using namespace std;

int a[1000001];
int nge[1000001];
stack<int> st;

int main()
{
    int n, num;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && a[st.top()] < a[i])
        {
            nge[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }

    while (!st.empty())
    {
        nge[st.top()] = -1;
        st.pop();
    }

    for (int i = 0; i < n; i++)
    {
        cout << nge[i] << " ";
    }
}