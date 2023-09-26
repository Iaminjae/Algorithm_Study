#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    while (true)
    {
        string input;
        getline(cin, input);

        if (input == ".")
        {
            break;
        }

        stack<char> st;
        bool bal = true;
        char sentence;

        for (int i = 0; i < input.length(); i++)
        {
            sentence = input[i];

            if (sentence == '(' || sentence == '[')
            {
                st.push(sentence);
            }
            else if (sentence == ')')
            {
                if (!st.empty() && st.top() == '(')
                {
                    st.pop();
                    continue;
                }
                else
                {
                    bal = false;
                    break;
                }
            }
            else if (sentence == ']')
            {
                if (!st.empty() && st.top() == '[')
                {
                    st.pop();
                    continue;
                }
                else
                {
                    bal = false;
                    break;
                }
            }
        }

        if (bal && st.empty())
        {
            cout << "yes" << '\n';
        }
        else
        {
            cout << "no" << '\n';
        }
    }
}