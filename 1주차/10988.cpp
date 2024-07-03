#include <iostream>

using namespace std;

int alp[26];
bool palin = true;
string word;

int main()
{
    cin >> word;

    fill(alp, alp + 26, 0);

    for (int i = 0; i < word.size() / 2; i++)
    {
        if (word[i] != word[word.size() - i - 1])
        {
            palin = false;
            break;
        }
    }

    cout << palin;
}