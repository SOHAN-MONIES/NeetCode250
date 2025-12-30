// URL:
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
using namespace std;

int romanToInt(string s)
{
    unordered_map<char, int> val = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

    int ans = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (i + 1 < s.size() && val[s[i]] < val[s[i + 1]])
        {
            ans -= val[s[i]];
        }
        else
        {
            ans += val[s[i]];
        }
    }
    return ans;
}

int main()
{
    cout << romanToInt("MCMXCIV");
    return 0;
}