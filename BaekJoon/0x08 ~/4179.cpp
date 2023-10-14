#include <iostream>
#include <queue>

#define A 1001
#define B 1001

using namespace std;

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    string miro[A];
    int visj[A][B] = {0};
    int visf[A][B] = {0};
    queue<pair<int, int>> q;
    queue<pair<int, int>> qf;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    for (int i = 0; i < n; i++)
    {
        cin >> miro[i];
        for (int j = 0; j < m; j++)
        {

            if (miro[i][j] == 'J')
            {
                q.push({i, j});
            }
            else if (miro[i][j] == 'F')
            {
                qf.push({i, j});
            }
        }
    }

    while (!qf.empty())
    {
        pair<int, int> cur = qf.front();
        qf.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            {
                continue;
            }
            if (visf[nx][ny] != 0 || miro[nx][ny] == 'F' || miro[nx][ny] == '#')
            {
                continue;
            }

            visf[nx][ny] = visf[cur.first][cur.second] + 1;
            qf.push({nx, ny});
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

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            {
                cout << visj[cur.first][cur.second] + 1;
                return 0;
            }
            if (visj[nx][ny] != 0 || miro[nx][ny] == 'F' || miro[nx][ny] == 'J' || miro[nx][ny] == '#')
            {
                continue;
            }

            if (visf[nx][ny] != 0 && visf[nx][ny] <= visj[cur.first][cur.second] + 1)
            {
                continue;
            }

            visj[nx][ny] = visj[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE";
}