#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
int arr[50][50];
int isused[50];
vector<pair<int, int>> v;
vector<pair<int, int>> v1;
vector<pair<int, int>> v2;
int minimum = 10000;
int n;
int m;

void func(int cur, int idx)
{
    if (cur == m)
    {
        int sum = 0;
        for (int i = 0; i < v1.size(); i++)
        {
            int min = 1000;
            for (int j = 0; j < v2.size(); j++)
            {
                int x = v1[i].first - v2[j].first;
                int y = v1[i].second - v2[j].second;

                int tmp = abs(x) + abs(y);
                if (min > tmp)
                {
                    min = tmp;
                }
            }
            sum += min;
        }
        if (minimum >= sum)
        {
            minimum = sum;
        }
        return;
    }

    for (int i = idx; i < v.size(); i++)
    {
        if (!isused[i])
        {
            isused[i] = 1;
            v2.push_back({v[i].first, v[i].second});
            func(cur + 1, i + 1);
            v2.pop_back();
            isused[i] = 0;
        }
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 2)
            {
                v.push_back({i, j});
            }
            else if (arr[i][j] == 1)
            {
                v1.push_back({i, j});
            }
        }
    }

    func(0, 0);

    cout << minimum;
}