// URL:
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
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