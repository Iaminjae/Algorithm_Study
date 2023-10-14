#include <iostream>
#include <queue>

using namespace std;

int dist[1000001];
queue<int> q;

int main()
{
    int f, s, g, u, d;

    cin >> f >> s >> g >> u >> d;

    int ud[2];
    ud[0] = u;
    ud[1] = d * (-1);

    for (int i = 1; i <= f; i++)
    {
        dist[i] = -1;
    }

    q.push(s);
    dist[s] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cur == g)
            break;

        for (int dir = 0; dir < 2; dir++)
        {
            int nx = cur + ud[dir];

            if (nx > f || nx < 1)
            {
                continue;
            }
            if (dist[nx] != -1)
                continue;

            q.push(nx);
            dist[nx] = dist[cur] + 1;
            if (cur == g)
                break;
        }
    }

    if (dist[g] == -1)
    {
        cout << "use the stairs" << '\n';
        return 0;
    }
    else
    {
        cout << dist[g] << '\n';
        return 0;
    }
}