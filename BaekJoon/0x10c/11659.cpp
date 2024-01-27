#include <iostream>

using namespace std;

int n;
int m;
int a, b;
int d[100001];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
        d[i] += d[i - 1];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;

        cout << d[b] - d[a - 1] << '\n';
    }
}