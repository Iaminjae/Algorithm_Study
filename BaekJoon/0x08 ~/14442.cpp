#include <iostream>
#include <queue>

using namespace std;
int map[1000][1000];
bool vis[1000][1000][11];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<pair<int, int>, pair<int, int>>> q;

int main()
{
    int n, m, k;
    int broken;
    int count;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line;

        for (int j = 0; j < m; j++)
        {
            map[i][j] = line[j] - '0';
            for (int l = 0; l <= k; l++)
            {
                vis[i][j][l] = 0;
            }
        }
    }

    q.push({{0, 0}, {0, 0}});
    vis[0][0][0] = 1;

    while (!q.empty())
    {
        pair<int, int> cur = q.front().first;
        count = q.front().second.first;
        broken = q.front().second.second;
        q.pop();

        if (cur.first == n - 1 && cur.second == m - 1)
        {
            cout << count + 1;
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

            if (vis[nx][ny][broken] == 0)
            {
                if (map[nx][ny] == 1)
                {
                    if (broken < k && !vis[nx][ny][broken + 1])
                    {
                        q.push({{nx, ny}, {count + 1, broken + 1}});
                        vis[nx][ny][broken + 1] = 1;
                    }
                }
                else if (map[nx][ny] == 0)
                {
                    q.push({{nx, ny}, {count + 1, broken}});
                    vis[nx][ny][broken] = 1;
                }
            }
        }
    }

    cout << -1;
}