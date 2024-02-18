#include <iostream>
#include <vector>

using namespace std;
int cnt = 0;
int num;
int maxnum = -10;
vector<int> v;
int dur[10];
int wei[10];

void func(int cur)
{
    if (cur == num)
    {
        cnt = 0;
        for (int i = 0; i < num; i++)
        {
            if (dur[i] <= 0)
            {
                cnt++;
            }
        }
        v.push_back(cnt);
        return;
    }

    if (dur[cur] <= 0)
    {
        func(cur + 1);
        return;
    }

    bool flag = false;

    for (int i = 0; i < num; i++)
    {
        if (i != cur && dur[i] > 0)
        {
            dur[cur] -= wei[i];
            dur[i] -= wei[cur];
            flag = true;
            func(cur + 1);
            dur[cur] += wei[i];
            dur[i] += wei[cur];
        }
    }
    if (!flag)
    {
        func(num);
    }
}

int main()
{
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> dur[i] >> wei[i];
    }

    func(0);

    for (int i = 0; i < v.size(); i++)
    {
        maxnum = max(maxnum, v[i]);
        // cout << "vector 값 : " << v[i] << "\n";
    }

    cout << maxnum;
}