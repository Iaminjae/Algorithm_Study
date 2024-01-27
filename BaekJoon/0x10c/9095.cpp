#include <iostream>

using namespace std;

int tc;
int d[12];
int n;

int main()
{
    cin >> tc;

    d[1] = 1;
    d[2] = 2;
    d[3] = 4;

    for (int j = 4; j <= 10; j++)
    {
        d[j] = d[j - 1] + d[j - 2] + d[j - 3];
    }

    for (int i = 0; i < tc; i++)
    {
        cin >> n;
        cout << d[n] << '\n';
    }
}