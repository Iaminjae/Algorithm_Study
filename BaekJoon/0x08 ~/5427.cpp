#include <iostream>
#include <queue>

using namespace std;

string miro[1001];
int dists[1003][1003];
int distf[1003][1003];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    int tc, w, h;

    cin >> tc;

    for (int i = 0; i < tc; i++)
    {
        string miro[1001];
        bool possible = false;
        queue<pair<int, int>> qs;
        queue<pair<int, int>> qf;
        cin >> w >> h;

        for (int j = 0; j < h; j++)
        {
            cin >> miro[j];

            for (int k = 0; k < w; k++)
            {

                if (miro[j][k] == '@')
                {
                    dists[j][k] = 0;
                    distf[j][k] = -1;
                    qs.push({j, k});
                    continue;
                }
                else if (miro[j][k] == '*')
                {
                    distf[j][k] = 0;
                    dists[j][k] = -1;
                    qf.push({j, k});
                    continue;
                }

                dists[j][k] = -1;
                distf[j][k] = -1;
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

                if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                    continue;
                if (miro[nx][ny] == '#' || distf[nx][ny] >= 0)
                    continue;

                distf[nx][ny] = distf[cur.first][cur.second] + 1;
                qf.push({nx, ny});
            }
        }

        while (!qs.empty())
        {
            pair<int, int> cur = qs.front();
            qs.pop();

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                {
                    cout << dists[cur.first][cur.second] + 1 << '\n';
                    possible = true;
                    break;
                }

                if (miro[nx][ny] == '#' || miro[nx][ny] == '*' || dists[nx][ny] != -1)
                    continue;
                if ((dists[cur.first][cur.second] + 1) >= distf[nx][ny] && distf[nx][ny] != -1)
                    continue;

                dists[nx][ny] = dists[cur.first][cur.second] + 1;
                qs.push({nx, ny});
            }
            if (possible)
                break;
        }

        if (!possible)
        {
            cout << "IMPOSSIBLE" << '\n';
        }
    }
}