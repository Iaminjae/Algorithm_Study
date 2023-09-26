#include <iostream>
#include <deque>
#include <cmath>

using namespace std;

int main()
{
    deque<int> dq;
    int arr[51] = {1};
    int n, num, find, temp;
    int left, right;
    int countSum = 0;

    cin >> n;

    left = 1;
    right = n;
    for (int i = 0; i < n; i++)
    {
        dq.push_back(i + 1);
    }

    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> find;

        for (int j = 0; j < dq.size(); j++)
        {
            if (dq[j] == find)
            {
                left = j;
                right = dq.size() - j;
            }
        }

        if (left <= right)
        {
            // 2번 연산
            while (find != dq.front())
            {
                temp = dq.front();
                dq.pop_front();
                dq.push_back(temp);
                countSum++;
            }
            dq.pop_front();
        }

        else
        {
            // 3번 연산
            while (find != dq.back())
            {
                temp = dq.back();
                dq.pop_back();
                dq.push_front(temp);
                countSum++;
            }
            temp = dq.back();
            dq.pop_back();
            dq.push_front(temp);
            countSum++;
            dq.pop_front();
        }
    }

    cout << countSum;
}