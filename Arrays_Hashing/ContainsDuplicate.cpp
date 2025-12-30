// URL:https://leetcode.com/problems/contains-duplicate/description/
#include <iostream>
#include <unordered_set>
using namespace std;

bool containsDuplicate(vector<int> &nums)
{
    unordered_set<int> s1;
    for (auto num : nums)
    {
        if (s1.count(num))
        {
            return true;
        }
        else
        {
            s1.insert(num);
        }
    }
    return false;
}
int main()
{

    return 0;
}