#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string word;
    int arr[26] = {0};

    cin >> word;

    for (int i = 0; i < word.size(); i++)
    {
        arr[word[i] - 'a'] += 1;
    }

    for (int i = 0; i < 26; i++)
    {
        cout << arr[i] << " ";
    }
}