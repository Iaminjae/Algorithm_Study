#include <iostream>

using namespace std;

int main()
{
    int arr[10] = {0};
    int num;
    int save = 0;
    int max = -1;

    cin >> num;

    for (; num > 0; num = num / 10)
    {
        arr[num % 10] += 1;
    }

    for (int i = 0; i < 10; i++)
    {
        if (i == 6 || i == 9)
        {
            save += arr[i];
            continue;
        }

        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    if (save / 2 + save % 2 > max)
    {
        max = save / 2 + save % 2;
    }

    cout << max;
}