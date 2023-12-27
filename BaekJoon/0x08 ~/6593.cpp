#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

char building[30][30][30];
int vis[30][30][30];
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
queue<tuple<int, int, int>> q;

int main()
{
    while (true)
    {
        int f, r, c;
        int tmp1, tmp2, tmp3;

        cin >> f >> r >> c;

        if (f == 0 && r == 0 && c == 0)
        {
            break;
        }

        for (int i = 0; i < f; i++)
        {
            for (int j = 0; j < r; j++)
            {
                for (int k = 0; k < c; k++)
                {
                    cin >> building[i][j][k];
                    vis[i][j][k] = -1;

                    if (building[i][j][k] == 'S')
                    {
                        q.push(make_tuple(i, j, k));
                        vis[i][j][k] = 0;
                        continue;
                    }

                    if (building[i][j][k] == 'E')
                    {
                        tmp1 = i;
                        tmp2 = j;
                        tmp3 = k;
                        continue;
                    }
                }
            }
        }

        while (!q.empty())
        {
            tuple<int, int, int> cur = q.front();
            q.pop();

            for (int dir = 0; dir < 6; dir++)
            {
                int rx = get<0>(cur) + dx[dir];
                int ry = get<1>(cur) + dy[dir];
                int rz = get<2>(cur) + dz[dir];

                if (rx < 0 || rx > f || ry < 0 || ry > r || rz < 0 || rz > c)
                {
                    continue;
                }

                if (vis[rx][ry][rz] != -1 || building[rx][ry][rz] == '#')
                {
                    continue;
                }

                vis[rx][ry][rz] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
                q.push(make_tuple(rx, ry, rz));

                if (building[rx][ry][rz] == 'E')
                {
                    q = queue<tuple<int, int, int>>();
                    break;
                }
            }
        }

        if (vis[tmp1][tmp2][tmp3] == -1)
        {
            cout << "Trapped!" << '\n';
        }
        else
        {
            cout << "Escaped in " << vis[tmp1][tmp2][tmp3] << " minute(s)." << '\n';
        }
    }
}
