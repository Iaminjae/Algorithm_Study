#include <iostream>
#include <deque>

#define MAX 5000001

using namespace std;

int arr[MAX];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    deque<pair<int, int>> dq;
    int n, l;
    cin >> n;
    cin >> l;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (!dq.empty() && dq.front().first < i - l + 1)
        {
            dq.pop_front();
        }
        while (!dq.empty() && dq.back().second > arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(make_pair(i, arr[i]));
        cout << dq.front().second << " ";
    }
}