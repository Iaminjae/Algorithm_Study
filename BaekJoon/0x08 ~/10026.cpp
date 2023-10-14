#include <iostream>
#include <queue>

#define R 0
#define G 1
#define B 2

using namespace std;

int main()
{
    int n;
    string col;

    cin >> n;

    char arr[n][n];
    bool vis[101][101] = {0};
    bool visb[101][101] = {0};
    queue<pair<int, int>> q;
    queue<pair<int, int>> qb;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int count[2] = {0};

    for (int i = 0; i < n; i++)
    {
        cin >> col;
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = col[j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j] == 0)
            {
                q.push({i, j});

                vis[i][j] = 1;
            }
            else
                continue;

            while (!q.empty())
            {
                pair<int, int> cur = q.front();
                q.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        continue;
                    if (vis[nx][ny] == 1 || arr[nx][ny] != arr[cur.first][cur.second])
                        continue;

                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }

            count[0] += 1;
        }

        for (int j = 0; j < n; j++)
        {
            if (visb[i][j] == 0)
            {
                qb.push({i, j});
                visb[i][j] = 1;
            }
            else
                continue;

            while (!qb.empty())
            {
                pair<int, int> cur = qb.front();
                qb.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        continue;
                    if (visb[nx][ny] == 1)
                        continue;
                    if (arr[nx][ny] != arr[cur.first][cur.second] && arr[cur.first][cur.second] == 'B')
                        continue;
                    if (arr[nx][ny] != arr[cur.first][cur.second] && arr[nx][ny] == 'B')
                        continue;

                    visb[nx][ny] = 1;
                    qb.push({nx, ny});
                }
            }

            count[1] += 1;
        }
    }

    cout << count[0] << " " << count[1];
}