#include <iostream>
#include <queue>

using namespace std;

string map[1000][9];
int move[9];
queue<pair<pair<int, int>, int>> q;

int main()
{
    int n, m, p;
    cin >> n >> m >> p;

    for (int i = 0; i < p; i++)
    {
        cin >> move[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> map[i];

        for (int j = 0; j < m; j++)
        {
            if (map[i][j] >= '1' && map[i][j] < = '9')
            {
                q.push({i, j}, map[i][j]);
            }
        }
    }

    while (!q.empty())
    {
        pair<int, int> cur = q.front().first;
        string pNum = q.front().second;
        q.pop();

        int dx[4] = {move[pNum], 0, -1 * move[pNum], 0};
        int dy[4] = {-1 * move[pNum], 0, move[pNum], 0};

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            {
                continue;
            }

            if (map[nx][ny] != '.')
            {
                continue;
            }
        }
    }
}