#include <iostream>
#include <queue>

using namespace std;

int dist[301][301];
int dx[8] = {2, 1, 2, 1, -2, -1, -2, -1};
int dy[8] = {1, 2, -1, -2, 1, 2, -1, -2};
queue<pair<int, int>> q;

int main()
{
    int tc, n;
    int x, y;

    cin >> tc;
    int ans[tc];

    for (int i = 0; i < tc; i++)
    {
        cin >> n;

        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                dist[j][k] = -1;
            }
        }

        for (int j = 0; j < 2; j++)
        {
            cin >> x >> y;

            if (j == 0)
            {
                q.push({x, y});
                dist[x][y] = 0;
            }
            else
                continue;
        }

        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();

            for (int dir = 0; dir < 8; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;
                if (dist[nx][ny] != -1)
                    continue;

                dist[nx][ny] = dist[cur.first][cur.second] + 1;
                q.push({nx, ny});
            }
        }

        ans[i] = dist[x][y];
    }

    for (int i = 0; i < tc; i++)
    {
        cout << ans[i] << '\n';
    }
}