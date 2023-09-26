#include <iostream>

using namespace std;

int num[1000001];
int tmp[2000002];

int main()
{
    int n;
    int number;
    int x;
    int count = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> number;
        num[i] = number;
        tmp[number] = 1;
    }

    cin >> x;

    for (int i = 0; i < n; i++)
    {
        if (x - num[i] >= 0 && tmp[x - num[i]] != 0 && x - num[i] > num[i])
        {
            count++;
        }
    }

    cout << count;
}