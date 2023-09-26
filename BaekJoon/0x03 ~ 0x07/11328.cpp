#include <iostream>
#include <string>

using namespace std;

string a[1001];
string b[1001];

int main()
{
    int N;
    string a1;
    string b1;
    int alpha[26] = {0};
    bool possible = true;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        cin >> b[i];
    }

    for (int i = 0; i < N; i++)
    {
        possible = true;
        a1 = a[i];
        b1 = b[i];

        if (a1.length() != b1.length())
        {
            possible = false;
        }
        else
        {
            for (int j = 0; j < a1.length(); j++)
            {
                alpha[a1[j] - 'a']++;
                alpha[b1[j] - 'a']--;
            }

            for (int k = 0; k < 26; k++)
            {
                if (alpha[k] != 0)
                {
                    possible = false;
                }
                else
                    continue;
            }
        }

        if (possible == true)
        {
            cout << "Possible" << '\n';
        }
        else
        {
            cout << "Impossible" << '\n';
        }

        for (int l = 0; l < 26; l++)
        {
            alpha[l] = 0;
        }
    }
}