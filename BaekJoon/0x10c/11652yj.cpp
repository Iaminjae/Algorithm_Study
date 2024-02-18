#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N, max_cnt = -1;
    int cnt = 1;
    long long tmp;
    long long arr[100001];

    cin >> N;
    for (int j = 0; j < N; j++)
    {
        cin >> arr[j];
    }
    sort(arr, arr + N);

    tmp = arr[0];
    for (int i = 0; i < N - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            cnt++;
            if (cnt > max_cnt)
            {
                max_cnt = cnt;
                tmp = arr[i];
            }
        }
        else
        {
            cnt = 1;
        }
    }

    cout << tmp;
}