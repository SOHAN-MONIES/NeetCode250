// URL:
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;
int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> s1;
    for (auto num : nums)
    {
        s1.insert(num);
    }
    int longest = 0;
    for (auto it : s1)
    {
        if (s1.find(it - 1) == s1.end())
        {
            int current = it;
            int cnt = 1;
            while (s1.find(current + 1) != s1.end())
            {
                cnt++;
                current++;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}
int main()
{

    return 0;
}