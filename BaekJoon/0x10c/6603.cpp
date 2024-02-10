#include <iostream>

using namespace std;
int s[14];
int num[6];
int isused[14];
int k;

void func(int cur)
{
    if (cur == 6)
    {
        for (int i = 0; i < 6; i++)
        {
            cout << num[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < k; i++)
    {
        if (!isused[i])
        {
            if (num[cur - 1] <= s[i] || cur == 0)
            {
                num[cur] = s[i];
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
    while (true)
    {
        cin >> k;

        if (k == 0)
        {
            break;
        }

        for (int i = 0; i < k; i++)
        {
            cin >> s[i];
        }

        func(0);
        cout << "\n";
    }
}