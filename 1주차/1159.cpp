#include <iostream>

using namespace std;
int num;
int arr[26];
char alp;
int total = 0;
string name;

int main()
{
    cin >> num;

    fill(arr, arr + 26, 0);

    for (int i = 0; i < num; i++)
    {
        cin >> name;
        arr[name[0] - 'a'] += 1;
    }

    for (int i = 0; i < 26; i++)
    {
        if (arr[i] >= 5)
        {
            total += 1;
            alp = 'a' + i;
            cout << alp;
        }
    }

    if (total == 0)
    {
        cout << "PREDAJA";
    }
}