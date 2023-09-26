#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> li;
    list<int>::iterator iter = li.begin();

    int i;
    int j = 0;
    int num;
    int order;

    cin >> num;
    cin >> order;

    for (i = 1; i <= num; i++)
    {
        li.push_back(i);
    }

    iter = li.begin();
    cout << '<';

    while (li.size() > 1)
    {

        for (i = 1; i < order; i++)
        {
            iter++;
            if (iter == li.end())
            {
                iter = li.begin();
                continue;
            }
        }

        cout << *iter << ", ";

        iter = li.erase(iter);
        if (iter == li.end())
        {
            iter = li.begin();
        }
    }

    cout << *iter << '>';
}