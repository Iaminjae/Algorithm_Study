#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[1000][1000][2];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
int res;
queue<pair<int, pair<int, int>>> q;

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < m; j++)
        {
            map[i][j][0] = tmp[j] - '0';
        }
    }

    q.push(make_pair(0, make_pair(0, 0)));

    while (!q.empty())
    {
        int broken = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        res = broken;
        q.pop();

        if (x == n - 1 && y == m - 1)
        {
            cout << map[n - 1][m - 1][broken] + 1;
            return 0;
        }

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            {
                continue;
            }

            if (map[nx][ny][0] == 1)
            {
                if (broken == 0)
                {
                    map[nx][ny][broken + 1] = map[x][y][broken] + 1;
                    q.push(make_pair(1, make_pair(nx, ny)));
                }
            }
            else if (map[nx][ny][0] == 0)
            {
                if (broken == 1 && map[nx][ny][broken])
                {
                    continue;
                }
                map[nx][ny][broken] = map[x][y][broken] + 1;
                q.push(make_pair(broken, make_pair(nx, ny)));
            }
        }
    }

    cout << -1;
}
