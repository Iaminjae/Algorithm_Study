#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int map[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;
vector<pair<int, int>> v;

int main()
{
    int n;
    int res = 100000;
    int land = 1;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 1)
            {
                map[i][j] = -1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == -1)
            {
                map[i][j] = land;
                q.push({i, j});
            }

            while (!q.empty())
            {
                pair<int, int> cur = q.front();
                q.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                    {
                        continue;
                    }

                    if (map[nx][ny] == land)
                    {
                        continue;
                    }

                    if (map[nx][ny] == 0)
                    {
                        v.push_back({cur.first, cur.second});
                        continue;
                    }

                    q.push({nx, ny});
                    map[nx][ny] = land;
                }
            }

            land++;
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        int ix = v.at(i).first;
        int iy = v.at(i).second;

        for (int j = i + 1; j < v.size(); j++)
        {
            int jx = v.at(j).first;
            int jy = v.at(j).second;

            if (map[ix][iy] == map[jx][jy])
            {
                continue;
            }
            else
            {
                int dist = abs(ix - jx) + abs(iy - jy) - 1;
                if (res > dist)
                {
                    res = dist;
                }
                else
                    continue;
            }
        }
    }

    cout << res;
}