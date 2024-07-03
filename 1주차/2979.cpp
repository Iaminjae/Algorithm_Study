#include <iostream>
#include <algorithm>

using namespace std;
int a, b, c;
int start, fin;
int arr[100];
int total = 0;
int num;

int main()
{
    cin >> a >> b >> c;

    fill(arr, arr + 100, 0);

    for (int i = 0; i < 3; i++)
    {
        cin >> start >> fin;

        for (int j = start; j < fin; j++)
        {
            arr[j] += 1;
        }
    }

    for (int i = 0; i < 100; i++)
    {
        if (arr[i] == 1)
        {
            total += a;
        }
        else if (arr[i] == 2)
        {
            total += 2 * b;
        }
        else if (arr[i] == 3)
        {
            total += 3 * c;
        }
    }

    cout << total;
}