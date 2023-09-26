#include <iostream>

using namespace std;

int arr[101] = {0};

int main()
{
    int n;
    int need;
    int count = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> need;

    for (int i = 0; i < n; i++)
    {
        if (need == arr[i])
        {
            count++;
        }
    }

    cout << count;
}