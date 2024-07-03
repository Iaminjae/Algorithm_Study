#include <iostream>

using namespace std;
int n;
int tmp;
bool da = true;
string s;
string prefix;
string suffix;
string ex;

int main()
{
    cin >> n;
    cin >> s;

    tmp = s.find('*');
    prefix = s.substr(0, tmp);
    suffix = s.substr(tmp + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> ex;

        if (prefix.size() + suffix.size() > ex.size())
        {
            cout << "NE" << "\n";
        }
        else
        {
            if (prefix == ex.substr(0, prefix.size()) && suffix == ex.substr(ex.size() - suffix.size()))
            {
                cout << "DA" << "\n";
            }
            else
            {
                cout << "NE" << "\n";
            }
        }
    }
}
