#include <iostream>
#include <queue>

using namespace std;
int line[110000];
int vis[110000];
int remember[110000];
queue<int> q;

int main()
{
    int n, k;
    bool finish = 0;
    vector<int> v;

    cin >> n >> k;

    if (n == k)
    {
        cout << 0 << '\n';
        cout << n;
        return 0;
    }

    q.push(n);
    line[n] = 0;
    vis[n] = 1;
    remember[n] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        int dx[3] = {cur - 1, cur + 1, cur * 2};

        for (int dir = 0; dir < 3; dir++)
        {
            int nx = dx[dir];

            if (nx < 0 || nx > 100001)
            {
                continue;
            }

            if (vis[nx] == 1)
            {
                continue;
            }

            q.push(nx);
            vis[nx] = 1;
            line[nx] = line[cur] + 1;
            remember[nx] = cur;

            if (nx == k)
            {
                finish = 1;
                break;
            }
        }

        if (finish == 1)
        {
            break;
        }
    }

    cout << line[k] << '\n';

    v.push_back(k);

    while (true)
    {
        v.push_back(remember[k]);
        k = remember[k];
        if (k == n)
        {
            break;
        }
    }

    while (!v.empty())
    {
        cout << v.back() << " ";
        v.pop_back();
    }
}