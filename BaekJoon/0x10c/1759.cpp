#include <iostream>
#include <algorithm>

using namespace std;
int l;
int c;
char alp[15];
char tmp[15];
int isused[15];
int vow = 0;
int con = 0;

void func(int cur)
{
    if (cur == l)
    {
        if (vow >= 1 && con >= 2)
        {
            for (int i = 0; i < l; i++)
            {
                cout << tmp[i];
            }
            cout << "\n";
            return;
        }
        return;
    }

    for (int i = 0; i < c; i++)
    {
        if (!isused[i])
        {
            if (cur == 0 || alp[i] - tmp[cur - 1] >= 0)
            {
                tmp[cur] = alp[i];
                isused[i] = 1;
                if (alp[i] == 'a' || alp[i] == 'e' || alp[i] == 'i' || alp[i] == 'o' || alp[i] == 'u')
                {
                    vow++;
                }
                else
                {
                    con++;
                }
                func(cur + 1);
                if (alp[i] == 'a' || alp[i] == 'e' || alp[i] == 'i' || alp[i] == 'o' || alp[i] == 'u')
                {
                    vow--;
                }
                else
                {
                    con--;
                }
                isused[i] = 0;
                tmp[cur] = ' ';
            }
        }
    }
}

int main()
{
    cin >> l >> c;

    for (int i = 0; i < c; i++)
    {
        cin >> alp[i];
    }

    sort(alp, alp + c);

    func(0);
}