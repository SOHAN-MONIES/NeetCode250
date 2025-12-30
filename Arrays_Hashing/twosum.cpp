// URL:
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;
vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> ans;
    map<int, int> mpp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (mpp.count(target - nums[i]))
        {
            return {i, mpp[target - nums[i]]};
        }
        else
        {
            mpp[nums[i]] = i;
        }
    }
    return {};
}
int main()
{

    return 0;
}