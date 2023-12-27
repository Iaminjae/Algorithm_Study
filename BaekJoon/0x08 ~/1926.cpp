#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, y;
    int arr[500][500] = {0};
    bool vis[500][500] = {0};
    int count = 0;
    int max = 0;
    queue<pair<int, int>> q;

    cin >> x >> y;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            int area = 0;
            if (!vis[i][j] && arr[i][j] == 1)
            {
                area++;
                q.push({i, j});
                vis[i][j] = 1;
            }
            else
            {
                continue;
            }

            while (!q.empty())
            {
                pair<int, int> cur = q.front();
                q.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (nx < 0 || nx >= x || ny < 0 || ny >= y)
                        continue;
                    if (vis[nx][ny] || arr[nx][ny] != 1)
                        continue;

                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                    area++;
                }
            }
            if (max <= area)
            {
                max = area;
            }
            count++;
        }
    }

    cout << count << '\n';
    cout << max;
}