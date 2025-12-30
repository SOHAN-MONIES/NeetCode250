// URL:
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;
int majorityElement(vector<int> &nums)
{

    int candidate = 0, count = 0;
    for (auto num : nums)
    {
        if (count == 0)
        {
            candidate = num;
        }
        count += (candidate == num) ? 1 : -1;
    }
    count = 0;
    for (auto num : nums)
    {
        if (num == candidate)
        {
            count++;
        }
    }
    if (count > nums.size() / 2)
        return candidate;
    return 0;
}

int main()
{

    return 0;
}