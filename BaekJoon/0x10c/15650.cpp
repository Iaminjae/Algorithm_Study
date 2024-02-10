#include <iostream>

using namespace std;
int n, m;
int num[10];
int isused[10];

void func(int cur)
{
    if (cur == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << num[i] << " ";
        }
        cout << '\n';

        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!isused[i])
        {
            if (num[cur - 1] <= i || cur == 0)
            {
                num[cur] = i;
                isused[i] = 1;
                func(cur + 1);
                num[cur] = 0;
                isused[i] = 0;
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    func(0);
}