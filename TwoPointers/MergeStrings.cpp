// URL:
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;

string mergeAlternately(string word1, string word2)
{
    string ans;
    int x = 0;
    int y = 0;
    int n = word1.size(), m = word2.size();
    while (x < n && y < m)
    {
        ans.push_back(word1[x]);
        ans.push_back(word2[y]);
        x++;
        y++;
    }
    while (x < n)
    {
        ans.push_back(word1[x]);
        x++;
    }
    while (y < m)
    {
        ans.push_back(word2[y]);
        y++;
    }
    return ans;
}
int main()
{

    return 0;
}