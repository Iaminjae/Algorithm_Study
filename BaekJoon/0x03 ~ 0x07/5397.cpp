#include <iostream>
#include <list>

using namespace std;

int main()
{
    int caseNum;

    cin >> caseNum;

    while (caseNum != 0)
    {
        caseNum--;

        string aa;
        list<char> li;
        list<char>::iterator iter = li.begin();

        cin >> aa;

        for (int i = 0; i < aa.length(); i++)
        {
            if (aa[i] == '<')
            {
                if (iter == li.begin())
                {
                    continue;
                }
                iter--;
            }
            else if (aa[i] == '>')
            {
                if (iter == li.end())
                {
                    continue;
                }
                iter++;
            }
            else if (aa[i] == '-')
            {
                if (iter == li.begin())
                {
                    continue;
                }
                iter--;
                iter = li.erase(iter);
            }
            else
            {
                li.insert(iter, aa[i]);
            }
        }

        for (iter = li.begin(); iter != li.end(); iter++)
        {
            cout << *iter;
        }
        cout << '\n';
    }
}