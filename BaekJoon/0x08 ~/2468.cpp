#include <iostream>
#include <queue>

using namespace std;

int arr[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<pair<int, int>> q;

int main()
{
    int n;
    int maxcount = 1;
    int maxheight = -1;
    int minheight = 101;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if (maxheight < arr[i][j])
            {
                maxheight = arr[i][j];
            }
            if (minheight > arr[i][j])
            {
                minheight = arr[i][j];
            }
        }
    }

    for (int rain = minheight - 1; rain < maxheight; rain++)
    {
        int count = 0;
        int vis[n][n];
        fill(&vis[0][0], &vis[n - 1][n], 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] > rain && vis[i][j] == 0)
                {
                    q.push({i, j});
                    vis[i][j] = 1;
                    count++;
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
                        if (arr[nx][ny] <= rain || vis[nx][ny] != 0)
                            continue;

                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }

        if (maxcount < count)
        {
            maxcount = count;
        }
    }

    cout << maxcount;
}