#include <iostream>
#include <queue>

using namespace std;
int line[140000];
int vis[140000];
queue<int> q;
queue<int> q2;
int dx[2] = {-1, 1};

int main()
{
    int n, k;
    bool finish = 0;
    cin >> n >> k;

    line[k] = 0;
    line[n] = 0;
    vis[n] = 1;
    q.push(n);

    if (n == k)
    {
        cout << 0;
        return 0;
    }

    while (!q.empty())
    {
        int cur = q.front();
        q2.push(cur);
        q.pop();

        while (!q2.empty())
        {
            int dbcur = q2.front() * 2;
            q2.pop();

            if (dbcur > 100000 || dbcur == 0)
            {
                continue;
            }

            if (vis[dbcur] == 1)
            {
                continue;
            }

            q2.push(dbcur);
            q.push(dbcur);
            vis[dbcur] = 1;
            line[dbcur] = line[cur];

            if (dbcur == k)
            {
                finish = true;
                break;
            }
        }

        for (int dir = 0; dir < 2; dir++)
        {
            int nx = cur + dx[dir];

            if (nx < 0 || nx > 100000)
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

            if (nx == k)
            {
                finish = true;
                break;
            }
        }

        if (finish == true)
        {
            break;
        }
    }

    cout << line[k];
}