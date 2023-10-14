#include <iostream>
#include <queue>

using namespace std;

int arr[101][101];
int vis[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;

int main()
{
    int m, n, num;
    int count = 0;
    int area[101] = {0};

    cin >> m >> n >> num;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 1;
            vis[i][j] = 0;
        }
    }

    for (int i = 0; i < num; i++)
    {
        int a, b, x, y;

        cin >> a >> b >> x >> y;

        for (int j = b; j < y; j++)
        {
            for (int k = a; k < x; k++)
            {
                arr[j][k] = 0;
                vis[j][k] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 1 && vis[i][j] == 0)
            {
                q.push({i, j});
                vis[i][j] = 1;
                area[count]++;
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

                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;
                    if (arr[nx][ny] == 0 || vis[nx][ny] == 1)
                        continue;

                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                    area[count]++;
                }
            }
            count++;
        }
    }

    cout << count << '\n';
    for (int i = 1; i < count; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (area[i] < area[j])
            {
                swap(area[i], area[j]);
                i = j;
                continue;
            }
        }
    }

    for (int i = 0; i < count; i++)
    {
        cout << area[i] << " ";
    }
}