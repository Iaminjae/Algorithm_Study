#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

string map[1002];
int vis[1002][1002][12][2];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<tuple<int, int, int, int>> q;

int main()
{
    int n, m, k;
    int count, broken;
    bool dayTime;

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> map[i];
        for (int j = 0; j < m; j++)
        {
            vis[i][j][0][0] = 0;
        }
    }

    q.push({0, 0, 0, 0});
    vis[0][0][0][0] = 1;

    while (!q.empty())
    {
        pair<int, int> cur = make_pair(get<0>(q.front()), get<1>(q.front()));
        broken = get<2>(q.front());
        dayTime = get<3>(q.front());
        q.pop();

        bool nextTime = 1 - dayTime;

        if (cur.first == n - 1 && cur.second == m - 1)
        {
            cout << vis[cur.first][cur.second][broken][dayTime];
            return 0;
        }

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            {
                continue;
            }

            if (dayTime == 0)
            {
                if (map[nx][ny] == '1')
                {
                    if (broken == k)
                    {
                        continue;
                    }

                    if (vis[nx][ny][broken + 1][nextTime] > 0)
                    {
                        continue;
                    }

                    q.push({nx, ny, broken + 1, nextTime});
                    vis[nx][ny][broken + 1][nextTime] = vis[cur.first][cur.second][broken][dayTime] + 1;
                }
                else if (map[nx][ny] == '0')
                {
                    if (vis[nx][ny][broken][nextTime] > 0)
                    {
                        continue;
                    }
                    q.push({nx, ny, broken, nextTime});
                    vis[nx][ny][broken][nextTime] = vis[cur.first][cur.second][broken][dayTime] + 1;
                }
            }
            else
            {
                if (map[nx][ny] == '1')
                {
                    if (vis[nx][ny][broken][nextTime] > 0)
                    {
                        continue;
                    }
                    q.push({cur.first, cur.second, broken, nextTime});
                    vis[cur.first][cur.second][broken][nextTime] = vis[cur.first][cur.second][broken][dayTime] + 1;
                }
                else if (map[nx][ny] == '0')
                {
                    if (vis[nx][ny][broken][nextTime] > 0)
                    {
                        continue;
                    }
                    q.push({nx, ny, broken, nextTime});
                    vis[nx][ny][broken][nextTime] = vis[cur.first][cur.second][broken][dayTime] + 1;
                }
            }
        }
    }

    cout << -1;
}