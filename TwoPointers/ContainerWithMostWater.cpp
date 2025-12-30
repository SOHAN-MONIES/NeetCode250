// URL:
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;
/*
✅ Algorithm: Container With Most Water (Two Pointers)

Problem:
Given an array `height` where height[i] represents the height of a vertical line
at position i, find two lines that together with the x-axis form a container
that holds the **maximum amount of water**.

-------------------------------------------------
Idea:

Use **two pointers** starting from both ends of the array.
The width is maximized initially, and we move inward to improve height.

-------------------------------------------------
Observation:

Water held between two lines depends on:
1. Width  = distance between lines
2. Height = minimum of the two line heights

So:
water = min(height[left], height[right]) × (right - left)

-------------------------------------------------
Key Insight:

The **shorter line limits the water**.
Moving the taller line cannot increase the water,
so we always move the pointer pointing to the **shorter height**.

-------------------------------------------------
Steps:

1. Initialize:
   left = 0
   right = n - 1
   maxArea = 0

2. While left < right:
   - Compute current area:
         area = min(height[left], height[right]) × (right - left)
   - Update maxArea
   - If height[left] < height[right]:
         left++
     else:
         right--

3. Return maxArea

-------------------------------------------------
Example:

height = [1,8,6,2,5,4,8,3,7]

Start:
left=0, right=8 → area=1×8=8

Move left (shorter):
left=1, right=8 → area=7×7=49 (max)

-------------------------------------------------
Time Complexity:
O(n)
- Each pointer moves at most n times

-------------------------------------------------
Space Complexity:
O(1)
- Constant extra space

-------------------------------------------------
🎯 Intuition:
- Max width first, then try to increase height
- Always discard the limiting (shorter) line
- Guarantees optimal solution in one pass

-------------------------------------------------
*/

int maxArea(vector<int> &height)
{
    int n = height.size();
    int ans = 0;
    int l = 0, r = n - 1;
    while (l < r)
    {
        int water = min(height[l], height[r]) * (r - l);
        ans = max(ans, water);
        if (height[l] > height[r])
        {
            r--;
        }
        else
        {
            l++;
        }
    }
    return ans;
}

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(height);
    return 0;
}