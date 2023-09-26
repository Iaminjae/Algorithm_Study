#include <iostream>
#include <list>

using namespace std;

int main()
{
    string a;
    int num;
    string command;

    cin >> a;

    list<char> li;
    list<char>::iterator iter = li.begin();

    for (int i = 0; i < a.length(); i++)
    {
        li.push_back(a[i]);
    }

    iter = li.end();

    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> command;

        if (command[0] == 'L')
        {
            if (iter == li.begin())
            {
                continue;
            }
            else
            {
                iter--;
            }
        }
        else if (command[0] == 'D')
        {
            if (iter == li.end())
            {
                continue;
            }
            else
            {
                iter++;
            }
        }
        else if (command[0] == 'B')
        {
            if (iter == li.begin())
            {
                continue;
            }
            iter--;
            iter = li.erase(iter);
        }
        else if (command[0] == 'P')
        {
            cin >> command;
            li.insert(iter, command[0]);
        }
        else
            continue;
    }

    for (iter = li.begin(); iter != li.end(); iter++)
    {
        cout << *iter;
    }
}