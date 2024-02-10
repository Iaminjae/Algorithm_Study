#include <iostream>

using namespace std;

int num[25];
int cnt = 0;
int n;
int s;

void func(int cur, int total)
{
    if (cur == n)
    {
        if (total == s)
        {
            cnt++;
        }
        return;
    }

    func(cur + 1, total);
    func(cur + 1, total + num[cur]);
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> s;

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    func(0, 0);
    if (s == 0)
    {
        cnt--;
    }
    cout << cnt;
}