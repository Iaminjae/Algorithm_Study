#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int arr[10] = {0};
    int A;
    int B;
    int C;
    int res;

    cin >> A;
    cin >> B;
    cin >> C;

    res = A * B * C;

    for (; res > 0; res = res / 10)
    {
        arr[res % 10] += 1;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << '\n';
    }
}