#include <iostream>
#include <string>
#include <deque>
#include <cctype>

using namespace std;

int main()
{
    int n, num;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        bool rev = false, error = false;
        string func;
        string arr;
        string s = "";
        deque<int> dq;

        cin >> func;

        cin >> num;

        cin >> arr;

        for (int j = 0; j < arr.size(); j++)
        {
            if (isdigit(arr[j]))
            {
                s += arr[j];
            }
            else
            {
                if (!s.empty())
                {
                    dq.push_back(stoi(s));
                    s = "";
                }
            }
        }

        for (int l = 0; l < func.size(); l++)
        {

            if (func[l] == 'R')
            {
                if (rev)
                {
                    rev = false;
                }
                else
                {
                    rev = true;
                }
            }
            else if (func[l] == 'D')
            {
                if (dq.empty())
                {
                    cout << "error" << '\n';
                    error = true;
                    break;
                }
                else if (rev)
                {
                    dq.pop_back();
                }
                else if (rev == false)
                    dq.pop_front();
            }
        }

        if (!error)
        {
            cout << '[';
        }
        if (rev && !dq.empty())
        {
            for (auto o = dq.rbegin(); o != dq.rend(); o++)
            {
                if (o == dq.rend() - 1)
                    cout << *o;
                else
                    cout << *o << ',';
            }
        }
        else if (!rev && !dq.empty())
        {
            for (auto o = dq.begin(); o != dq.end(); o++)
            {
                if (o == dq.end() - 1)
                    cout << *o;
                else
                    cout << *o << ',';
            }
        }
        if (!error)
            cout << "]\n";
    }
}
