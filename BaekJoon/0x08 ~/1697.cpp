#include <iostream>
#include <queue>

#define A 100002
using namespace std;

int main()
{
    int dist[A];
    fill(dist, dist + A, -1);
    queue<int> q;
    int n, k;

    cin >> n >> k;
    dist[n] = 0;
    q.push(n);

    while (dist[k] == -1)
    {
        int cur = q.front();
        q.pop();

        for (int next : {cur - 1, cur + 1, cur * 2})
        {
            if (next < 0 || next > 100000)
            {
                continue;
            }
            if (dist[next] != -1)
            {
                continue;
            }

            dist[next] = dist[cur] + 1;
            q.push(next);
        }
    }

    cout << dist[k];
}
