#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int arr[101][101][101];
int dist[101][101][101];
queue<tuple<int, int, int>> q;

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main()
{
    int n, m, h;
    int count;
    int x, y, z;

    cin >> n >> m >> h;
    count = n * m * h;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cin >> arr[i][j][k];

                if (arr[i][j][k] == 1)
                {
                    count--;
                    dist[i][j][k] = 0;
                    q.push({i, j, k});
                    continue;
                }
                else if (arr[i][j][k] == -1)
                {
                    dist[i][j][k] = -1;
                    count--;
                    continue;
                }
                dist[i][j][k] = -1;
            }
        }
    }

    while (!q.empty())
    {
        tuple<int, int, int> cur = q.front();
        q.pop();

        for (int dir = 0; dir < 6; dir++)
        {
            int nz = get<0>(cur) + dz[dir];
            int nx = get<1>(cur) + dx[dir];
            int ny = get<2>(cur) + dy[dir];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h)
            {
                continue;
            }
            if (dist[nz][nx][ny] != -1 || arr[nz][nx][ny] == -1)
            {
                continue;
            }

            q.push({nz, nx, ny});
            dist[nz][nx][ny] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            count--;
        }

        z = get<0>(cur);
        x = get<1>(cur);
        y = get<2>(cur);
    }

    if (count > 0)
    {
        cout << -1;
        return 0;
    }
    else
    {
        cout << dist[z][x][y];
        return 0;
    }
}