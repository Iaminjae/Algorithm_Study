#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc, r, c, num;

    cin >> tc;
    int count[tc];

    for (int i = 0; i < tc; i++)
    {
        cin >> c >> r >> num;
        count[i] = 0;
        int arr[50][50] = {0};
        bool vis[50][50] = {0};
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        int x, y;
        queue<pair<int, int>> q;

        for (int j = 0; j < num; j++)
        {
            cin >> x >> y;
            arr[y][x] = 1;
        }

        for (int j = 0; j < r; j++)
        {
            for (int k = 0; k < c; k++)
            {
                if (arr[j][k] == 0 || vis[j][k] == 1)
                {
                    continue;
                }
                vis[j][k] = 1;
                q.push({j, k});

                while (!q.empty())
                {
                    pair<int, int> cur = q.front();
                    q.pop();

                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                        {
                            continue;
                        }
                        if (vis[nx][ny] == 1 || arr[nx][ny] == 0)
                        {
                            continue;
                        }

                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
                count[i] = count[i] + 1;
            }
        }
    }

    for (int i = 0; i < tc; i++)
    {
        cout << count[i] << '\n';
    }
}