// URL:
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;
/*
✅ Algorithm: Remove Element (Two Pointers / In-Place)

Problem:
Given an array `nums` and an integer `val`,
remove all occurrences of `val` **in-place**.
Return the number of remaining elements.
The order of elements can be changed.

-------------------------------------------------
Idea:

Use two pointers:
- `j` → scans the array
- `i` → tracks position to place valid elements (≠ val)

-------------------------------------------------
Steps:

1. Initialize pointer `i = 0`
   - Represents the index where the next valid element should go

2. Traverse array using pointer `j` from 0 to n-1:
   - If nums[j] != val:
         nums[i] = nums[j]
         i++

3. After traversal:
   - First `i` elements in `nums` contain valid elements
   - Remaining elements can be ignored

4. Return `i` as the new length

-------------------------------------------------
Example:

nums = [3,2,2,3], val = 3

Step-by-step:
j=0 → nums[j]=3 → skip
j=1 → nums[j]=2 → nums[0]=2
j=2 → nums[j]=2 → nums[1]=2
j=3 → nums[j]=3 → skip

Result:
nums = [2,2,_,_]
Return length = 2

-------------------------------------------------
Time Complexity:
O(n)
- Single pass through the array

-------------------------------------------------
Space Complexity:
O(1)
- In-place modification, no extra space

-------------------------------------------------
🎯 Intuition:
- Keep shifting valid elements forward
- Overwrite unwanted values
- Efficient and optimal in-place solution

-------------------------------------------------
*/
int removeElement(vector<int> &nums, int val)
{
    int i = 0;
    for (int j = 0; j < nums.size(); j++)
    {
        if (nums[j] != val)
        {
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}
int removeElement_STL(vector<int> &nums, int val)
{
    auto it = remove(nums.begin(), nums.end(), val);
    return it - nums.begin();
}

int main()
{

    return 0;
}