#include <iostream>
#include <queue>

#define A 1000
#define B 1000

using namespace std;

int main()
{
    int n, m;
    int count;
    int x, y;
    queue<pair<int, int>> q;
    int arr[A][B] = {0};
    int leng[A][B] = {0};
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    cin >> n >> m;
    count = n * m;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 1)
            {
                count--;
                q.push({i, j});
            }
            else if (arr[i][j] == -1)
            {
                count--;
                continue;
            }
        }
    }

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
            {
                continue;
            }
            if (arr[nx][ny] == 1 || arr[nx][ny] == -1)
            {
                continue;
            }
            count--;
            arr[nx][ny] = 1;
            leng[nx][ny] = leng[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }

        x = cur.first;
        y = cur.second;
    }

    if (count > 0)
    {
        cout << -1;
    }
    else
    {
        cout << leng[x][y];
    }
}