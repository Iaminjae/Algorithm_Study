#include <iostream>
#include <string>

int alpha[26] = {0};

using namespace std;

int main()
{
    string a;
    string b;
    int count = 0;

    cin >> a;
    cin >> b;

    for (int i = 0; i < a.length(); i++)
    {
        alpha[a[i] - 'a']++;
    }

    for (int i = 0; i < b.length(); i++)
    {
        alpha[b[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
    {
        if (alpha[i] < 0)
        {
            count -= alpha[i];
        }
        else
        {
            count += alpha[i];
        }
    }

    cout << count;
}