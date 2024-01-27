#include <iostream>

using namespace std;

int d[301][3];
int num;
int point[301];

int main()
{
    cin >> num;

    for (int i = 1; i <= num; i++)
    {
        cin >> point[i];
    }

    d[1][1] = point[1];
    d[2][1] = point[2];
    d[2][2] = d[1][1] + point[2];

    for (int i = 3; i <= num; i++)
    {
        d[i][1] = max(d[i - 2][1], d[i - 2][2]) + point[i];
        d[i][2] = d[i - 1][1] + point[i];
    }

    cout << max(d[num][1], d[num][2]);
}