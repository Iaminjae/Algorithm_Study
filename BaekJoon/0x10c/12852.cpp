#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int d[1000001];
int num;
queue<int> q;
int temp;

int main()
{
    cin >> num;

    d[1] = 0;

    for (int i = 2; i <= num; i++)
    {
        d[i] = d[i - 1] + 1;

        if (i % 2 == 0)
        {
            d[i] = min(d[i], d[i / 2] + 1);
        }
        if (i % 3 == 0)
        {
            d[i] = min(d[i], d[i / 3] + 1);
        }
    }

    q.push(num);
    int i = num;

    while (i >= 1)
    {
        temp = i - 1;
        if (i % 2 == 0)
        {
            if (d[temp] >= d[i / 2])
            {
                temp = i / 2;
            }
        }
        if (i % 3 == 0)
        {
            if (d[temp] >= d[i / 3])
            {
                temp = i / 3;
            }
        }

        i = temp;

        if (i < 1)
        {
            break;
        }
        q.push(i);
    }

    cout << d[num] << '\n';
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}