// URL:
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;
/*
✅ Algorithm: Boats to Save People (Greedy + Two Pointers)

Problem:
You are given an array `people` where people[i] is the weight of the i-th person,
and an integer `limit` representing the maximum weight a boat can carry.

Each boat can carry **at most two people** whose combined weight
does not exceed `limit`.

Goal:
Find the **minimum number of boats** required to rescue everyone.

-------------------------------------------------
Idea:

Use a **greedy strategy** with **two pointers** after sorting:
- Pair the lightest and heaviest person whenever possible
- Otherwise, send the heaviest person alone

-------------------------------------------------
Preprocessing:

1. Sort the `people` array in ascending order

-------------------------------------------------
Steps:

1. Initialize:
   - left = 0   → lightest person
   - right = n-1 → heaviest person
   - boats = 0

2. While left < right:
   - If people[left] + people[right] ≤ limit:
         → Pair them in one boat
         → left++, right--
   - Else:
         → Heaviest person goes alone
         → right--
   - Increment boats

3. If one person remains (left == right):
   - Assign one boat

4. Return boats

-------------------------------------------------
Why Greedy Works:

- The heaviest person must be placed in a boat
- Best chance to save space is pairing with the lightest person
- If they can't pair, no one else can pair with the heaviest

-------------------------------------------------
Example:

people = [3,2,2,1], limit = 3
Sorted → [1,2,2,3]

Pairing:
3 alone → boat 1
2 + 1 → boat 2
2 alone → boat 3

Answer = 3

-------------------------------------------------
Time Complexity:
O(n log n)
- Sorting dominates

-------------------------------------------------
Space Complexity:
O(1)
- In-place sorting, constant extra space

-------------------------------------------------
🎯 Intuition:
Always try to fit the heaviest person with the lightest possible partner.
This minimizes wasted space and total boats.

-------------------------------------------------
*/

int numRescueBoats(vector<int> &people, int limit)
{
    int n = people.size();
    sort(people.begin(), people.end());
    int boats = 0;
    int l = 0;
    int r = n - 1;
    while (l < r)
    {
        if (people[l] + people[r] <= limit)
        {
            boats++;
            l++;
            r--;
        }
        else if (people[r] <= limit)
        {
            boats++;
            r--;
        }
    }
    if (l == r)
    {
        boats++;
    }
    return boats;
}
int main()
{
    vector<int> people = {3, 2, 2, 1};
    return 0;
}