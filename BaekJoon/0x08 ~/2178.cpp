#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    string num;
    int arr[100][100] = {0};
    int vis[100][100] = {0};
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    queue<pair<int, int>> q;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = num[j] - '0';
        }
    }

    vis[0][0] = 1;
    q.push({0, 0});

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
            if ((vis[nx][ny] != 0) || arr[nx][ny] == 0)
            {
                continue;
            }

            vis[nx][ny] = vis[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }
    cout << vis[n - 1][m - 1];
}