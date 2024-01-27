#include <iostream>
#include <algorithm>

using namespace std;

int r[1001];
int g[1001];
int b[1001];
int d[1001][3];
int num;

int main()
{
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> r[i] >> g[i] >> b[i];
    }

    d[0][0] = r[0];
    d[0][1] = g[0];
    d[0][2] = b[0];

    for (int i = 1; i < num; i++)
    {
        d[i][0] = min(d[i - 1][1], d[i - 1][2]) + r[i];
        d[i][1] = min(d[i - 1][0], d[i - 1][2]) + g[i];
        d[i][2] = min(d[i - 1][0], d[i - 1][1]) + b[i];
    }

    cout << min({d[num - 1][0], d[num - 1][1], d[num - 1][2]});
}