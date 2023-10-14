#include <iostream>
#include <queue>

using namespace std;

string input[100];
bool vis[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;

int main()
{
    int n;
    int count = 0;
    vector<int> area;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int number = 0;
            if (input[i][j] == '1' && !vis[i][j])
            {
                q.push({i, j});
                vis[i][j] = true;
                number++;
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
                    if (input[nx][ny] == '0' || vis[nx][ny] == 1)
                        continue;

                    vis[nx][ny] = true;
                    q.push({nx, ny});
                    number++;
                }
            }
            area.push_back(number);
            count++;
        }
    }

    for (int i = 0; i < count - 1; i++)
    {
        int idx = i;
        for (int j = i + 1; j < count; j++)
        {
            if (area[idx] >= area[j])
            {
                idx = j;
            }
        }
        swap(area[i], area[idx]);
    }

    cout << count << '\n';
    for (int i = 0; i < count; i++)
    {
        cout << area[i] << '\n';
    }
}