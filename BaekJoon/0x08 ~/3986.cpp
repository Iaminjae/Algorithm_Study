#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n, good = 0;
    string word;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        stack<char> st;
        cin >> word;

        for (int j = 0; j < word.size(); j++)
        {
            if (!st.empty() && st.top() == word[j])
            {
                st.pop();
                continue;
            }
            st.push(word[j]);
        }

        if (st.empty())
        {
            good++;
        }
    }

    cout << good;
}