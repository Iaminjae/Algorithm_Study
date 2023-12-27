#include <iostream>
#include <queue>

using namespace std;

int mat[301][301];
int vis[301][301];
queue<pair<int, int>> q;
queue<pair<int, int>> qc;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    int n, m;
    int count = 0;
    cin >> n >> m;
    int year = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
            vis[i][j] = 0;

            if (mat[i][j] != 0)
            {
                count++;
            }
        }
    }

    while (true)
    {
        int piece = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] > 0 && vis[i][j] == year)
                {
                    q.push({i, j});
                    vis[i][j] = year + 1;

                    while (!q.empty())
                    {
                        pair<int, int> cur = q.front();
                        q.pop();

                        for (int dir = 0; dir < 4; dir++)
                        {
                            int nx = cur.first + dx[dir];
                            int ny = cur.second + dy[dir];

                            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                            {
                                continue;
                            }

                            if (mat[nx][ny] == 0)
                            {
                                if (mat[cur.first][cur.second] > 0)
                                {
                                    qc.push({cur.first, cur.second});
                                }
                                continue;
                            }

                            if (mat[nx][ny] > 0 && vis[nx][ny] == year)
                            {
                                q.push({nx, ny});
                                vis[nx][ny] = year + 1;
                                continue;
                            }
                        }
                    }

                    piece += 1;
                }
            }
        }

        while (!qc.empty())
        {
            pair<int, int> cur = qc.front();
            qc.pop();

            if (mat[cur.first][cur.second] == 0)
            {
                continue;
            }

            mat[cur.first][cur.second] -= 1;

            if (mat[cur.first][cur.second] == 0)
            {
                count--;
            }
        }

        year++;
        if (piece >= 2)
        {
            break;
        }
        if (count <= 0)
        {
            cout << 0;
            return 0;
        }
    }

    cout << year - 1;
}