#include <iostream>

using namespace std;

int n;
int d[501][501];

int main()
{
    int maximum = -1;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> d[i][j];

            if (i > 0)
            {
                if (j > 0 && j < i)
                {
                    d[i][j] += max(d[i - 1][j - 1], d[i - 1][j]);
                }
                else if (j == 0)
                {
                    d[i][j] += d[i - 1][j];
                }
                else
                {
                    d[i][j] += d[i - 1][j - 1];
                }
            }

            if (i == (n - 1))
            {
                if (maximum <= d[i][j])
                {
                    maximum = d[i][j];
                }
            }
        }
    }

    cout << maximum;
}