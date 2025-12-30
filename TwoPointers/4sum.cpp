// URL:
#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: 4Sum (Sorting + Two Pointers)

Problem:
Given an integer array `nums` and an integer `target`,
return all **unique quadruplets** [a, b, c, d] such that:
    a + b + c + d == target

Each quadruplet must be unique (no duplicates).

-------------------------------------------------
Core Idea:

- Reduce 4Sum → 2Sum using **two nested loops + two pointers**
- Sorting helps:
  - Efficient two-pointer search
  - Easy duplicate removal

-------------------------------------------------
Preprocessing:

1. Sort the array `nums`

-------------------------------------------------
Steps:

1. Iterate index `i` from 0 to n-1:
   - Skip duplicate values for `i`

2. Iterate index `j` from i+1 to n-1:
   - Skip duplicate values for `j`

3. Use two pointers:
   - left = j + 1
   - right = n - 1

4. While left < right:
   - Compute:
         sum = nums[i] + nums[j] + nums[left] + nums[right]

   - If sum == target:
         → Store quadruplet
         → Skip duplicates for left & right
         → left++, right--

   - Else if sum < target:
         → Increase sum → left++

   - Else:
         → Decrease sum → right--

5. Continue until all valid quadruplets are found

-------------------------------------------------
Duplicate Handling:

- Skip same values for `i` and `j`
- After finding a valid quadruplet:
     - Skip equal adjacent elements for `left` and `right`

This guarantees **unique results only**.

-------------------------------------------------
Why Two Pointers Work:

After fixing `i` and `j`:
- The remaining problem is:
      nums[left] + nums[right] = target - (nums[i] + nums[j])
- Sorted array allows monotonic movement:
      left++ increases sum
      right-- decreases sum

-------------------------------------------------
Example:

nums = [1,0,-1,0,-2,2], target = 0
Sorted → [-2,-1,0,0,1,2]

Valid quadruplets:
[-2,-1,1,2]
[-2,0,0,2]
[-1,0,0,1]

-------------------------------------------------
Time Complexity:
O(n³)
- Two loops + two-pointer scan

-------------------------------------------------
Space Complexity:
O(1) extra space
- Output space excluded

-------------------------------------------------
🎯 Intuition:
Fix two numbers, then smartly search the remaining two using
two pointers while avoiding duplicates.

-------------------------------------------------
*/

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            int l = j + 1;
            int r = n - 1;
            while (l < r)
            {
                long sum = (long)nums[i] + nums[j] + nums[l] + nums[r];
                if (sum == target)
                {
                    ans.push_back({nums[i], nums[j], nums[l], nums[r]});

                    while (l < r && nums[l] == nums[l + 1])
                    {
                        l++;
                    }
                    while (l < r && nums[r] == nums[r - 1])
                    {
                        r--;
                    }
                    l++;
                    r--;
                }
                else if (sum < target)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}