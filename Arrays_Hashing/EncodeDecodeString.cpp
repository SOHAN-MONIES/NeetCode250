// URL:
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <string.h>
#include <strings.h>
using namespace std;
// Length based hash must be used , as only # will break if string contains #
string encode(vector<string> &s)
{

    string msg = "";
    for (auto str : s)
    {
        int sz = str.size();
        msg.push_back(sz + '0');
        msg.push_back('#');
        for (auto ch : str)
        {

            msg.push_back(ch);
        }
    }
    return msg;
}
vector<string> decode(string s)
{
    vector<string> result;
    int i = 0;

    while (i < s.size())
    {

        int len = 0;
        while (s[i] >= '0' && s[i] <= '9')
        {
            len = len * 10 + (s[i] - '0');
            i++;
        }

        i++;

        result.push_back(s.substr(i, len));

        i += len;
    }

    return result;
}

int main()
{
    vector<string> s = {"Hello", "World"};
    cout << encode(s);
    string m = "#Hello##World#";
    vector<string> w = decode(m);
    for (auto word : w)
    {
        cout << word << endl;
    }
    return 0;
}