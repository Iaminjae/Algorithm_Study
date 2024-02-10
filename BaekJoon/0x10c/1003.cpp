#include <iostream>

using namespace std;

int tc;
int num;
int da[45];
int db[45];

int main()
{
    cin >> tc;

    da[0] = 1;
    db[0] = 0;
    da[1] = 0;
    db[1] = 1;

    for (int i = 0; i < tc; i++)
    {
        cin >> num;

        for (int j = 2; j <= num; j++)
        {
            da[j] = da[j - 1] + da[j - 2];
            db[j] = db[j - 1] + db[j - 2];
        }

        cout << da[num] << " " << db[num] << '\n';
    }
}