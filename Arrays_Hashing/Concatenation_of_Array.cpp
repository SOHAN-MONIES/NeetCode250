// URL:https://leetcode.com/problems/concatenation-of-array/
#include <iostream>
using namespace std;
vector<int> getConcatenation(vector<int> &nums)
{
    vector<int> ans = nums;
    for (auto num : nums)
    {
        ans.push_back(num);
    }
    return ans;
}
vector<int> getConcatenation_STL(vector<int> &nums)
{
    vector<int> ans = nums;
    ans.insert(ans.end(), nums.begin(), nums.end());
    ans.insert(ans.end(), nums.begin(), nums.end());
    return ans;
}
int main()
{

    return 0;
}