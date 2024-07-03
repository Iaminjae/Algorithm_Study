#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[10];
vector<int> b;
int sum = 0;
int tmp1, tmp2;

int main()
{
    for (int i = 0; i < 9; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    sort(a, a + 9);

    for (int i = 0; i < 9; i++)
    {
        sum -= a[i];
        for (int j = i + 1; j < 9; j++)
        {
            sum -= a[j];
            if (sum == 100)
            {
                tmp1 = i;
                tmp2 = j;
                break;
            }
            sum += a[j];
        }

        if (sum == 100)
        {
            break;
        }
        sum += a[i];
    }

    for (int i = 0; i < 9; i++)
    {
        if (i == tmp1 || i == tmp2)
        {
            continue;
        }
        cout << a[i] << "\n";
    }
}