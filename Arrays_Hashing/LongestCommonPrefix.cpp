// URL:
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;
bool check(int idx, vector<string> &strs)
{
    for (int i = 0; i < strs.size() - 1; i++)
    {
        if (idx >= strs[i].size() || idx >= strs[i + 1].size())
        {
            return false;
        }
        if (strs[i][idx] != strs[i + 1][idx])
        {
            return false;
        }
    }
    return true;
}

string longestCommonPrefix(vector<string> &strs)
{
    if (strs.empty())
        return "";
    if (strs.size() == 1)
        return strs[0];
    string ans = "";
    for (int idx = 0;; idx++)
    {
        if (check(idx, strs))
        {
            ans.push_back(strs[0][idx]);
        }
        else
        {
            break;
        }
    }
    return ans;
}
int main()
{

    return 0;
}