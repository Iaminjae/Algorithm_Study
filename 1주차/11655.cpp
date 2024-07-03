#include <iostream>

using namespace std;

int main()
{
    string s;
    getline(cin, s);

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            continue;
        }

        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            int num;
            num = 'Z' - s[i];

            if (num < 13)
            {
                s[i] = 'A' + 13 - num - 1;
                continue;
            }
            s[i] += 13;
        }
        else if (s[i] >= 'a' && s[i] <= 'z')
        {
            int num;
            num = 'z' - s[i];

            if (num < 13)
            {
                s[i] = 'a' + 13 - num - 1;
                continue;
            }
            s[i] += 13;
        }
    }

    cout << s;
}