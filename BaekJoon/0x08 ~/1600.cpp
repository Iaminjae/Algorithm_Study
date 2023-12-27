#include <iostream>
#include <queue>

using namespace std;

int map[202][202];
int vis[202][202][31];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int kx[8] = {2, 1, -2, -1, 2, 1, -2, -1};
int ky[8] = {1, 2, -1, -2, -1, -2, 1, 2};
queue<pair<pair<int, int>, int>> q;

int main()
{
    int k;
    int w, h, layer;
    int visited = 0;
    int res = 100000;

    cin >> k;
    cin >> w >> h;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> map[i][j];
            for (int l = 0; l <= k; l++)
            {
                vis[i][j][l] = -1;
            }
        }
    }

    if (w == h && w == 1)
    {
        cout << 0;
        return 0;
    }

    q.push({{0, 0}, 0});
    vis[0][0][0] = 0;

    while (!q.empty())
    {
        pair<int, int> cur = q.front().first;
        layer = q.front().second;
        q.pop();

        if (layer < k)
        {
            for (int dir = 0; dir < 8; dir++)
            {
                int jx = cur.first + kx[dir];
                int jy = cur.second + ky[dir];

                if (jx < 0 || jx >= h || jy < 0 || jy >= w)
                {
                    continue;
                }

                if (map[jx][jy] == 1)
                {
                    continue;
                }

                for (int i = 0; i <= layer + 1; i++)
                {
                    visited = 0;
                    if (vis[jx][jy][i] != -1)
                    {
                        visited = 1;
                        break;
                    }
                }

                if (visited == 1)
                {
                    continue;
                }

                if (jx == h - 1 && jy == w - 1)
                {
                    cout << vis[cur.first][cur.second][layer] + 1;
                    return 0;
                }

                vis[jx][jy][layer + 1] = vis[cur.first][cur.second][layer] + 1;
                q.push({{jx, jy}, layer + 1});
            }
        }

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= h || ny < 0 || ny >= w)
            {
                continue;
            }

            if (map[nx][ny] == 1)
            {
                continue;
            }

            for (int i = 0; i <= layer; i++)
            {
                visited = 0;
                if (vis[nx][ny][i] != -1)
                {
                    visited = 1;
                    break;
                }
            }

            if (visited == 1)
            {
                continue;
            }

            if (nx == h - 1 && ny == w - 1)
            {
                cout << vis[cur.first][cur.second][layer] + 1;
                return 0;
            }

            q.push({{nx, ny}, layer});
            vis[nx][ny][layer] = vis[cur.first][cur.second][layer] + 1;
        }
    }

    cout << -1;
}