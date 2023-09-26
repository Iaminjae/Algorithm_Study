#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string &s, string &sep)
{
    vector<string> ret;
    int pos = 0;

    while (pos < s.size())
    {
        int nxt_pos = s.find(sep, pos);

        if (nxt_pos == -1)
            nxt_pos = s.size();
        if (nxt_pos - pos > 0)
        {
            ret.push_back(s.substr(pos, nxt_pos - pos));
        }
        pos = nxt_pos + sep.size();
    }

    return ret;
}

int main()
{

    string s1 = "welcome to the black parade";
    string sep = " ";
    vector<string> chunks = split(s1, sep);

    for (auto chunk : chunks)
    {
        cout << chunk << '/';
    }
    cout<<" ";
}