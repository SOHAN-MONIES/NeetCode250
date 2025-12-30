// URL:
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;
/*
✅ Algorithm: Group Anagrams

Problem:
Given an array of strings `strs`,
group the strings such that each group contains strings
that are **anagrams** of each other.

Two strings are anagrams if:
- They contain the same characters
- With the same frequencies

-------------------------------------------------
Approach 1️⃣: Sorting-Based Key (Classic)

Idea:
- Anagrams become identical after sorting their characters.
- Use the sorted string as a key in a hash map.

-------------------------------------------------
Steps:
1. Create an unordered_map:
       key   → sorted version of string
       value → list of original strings
2. For each string:
       - Copy the string
       - Sort the characters
       - Use sorted string as key
       - Push original string into map[key]
3. Collect all map values into result vector

-------------------------------------------------
Example:
Input: ["eat","tea","tan","ate","nat","bat"]

After sorting:
"eat" → "aet"
"tea" → "aet"
"ate" → "aet"

Grouped under key "aet"

-------------------------------------------------
Time Complexity:
O(n × k log k)
- n = number of strings
- k = average string length
- Sorting each string costs O(k log k)

Space Complexity:
O(n × k)
- Hash map stores all strings and keys

-------------------------------------------------
Approach 2️⃣: Frequency Count Key (Optimized)

Idea:
- Anagrams have identical **character frequencies**
- Build a frequency-based key instead of sorting
- Avoids O(k log k) sorting cost

-------------------------------------------------
Key Construction:
- Create count[26] for characters 'a' to 'z'
- Convert counts into a string key like:
      "#1#0#0#2#0..."

-------------------------------------------------
Steps:
1. For each string:
       - Count character frequencies
       - Build frequency-based key
       - Push string into map[key]
2. Collect all map values into result

-------------------------------------------------
Time Complexity:
O(n × k)
- Counting characters is linear

Space Complexity:
O(n × k)
- Hash map + frequency keys

-------------------------------------------------
🎯 Intuition:
- Anagrams share a common invariant
- Sorting gives canonical form
- Frequency array gives canonical signature
- Hash map groups strings by that invariant

-------------------------------------------------
When to Use Which:
- Sorting → simpler, easy to write
- Frequency key → faster for large strings

-------------------------------------------------
*/

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> mpp;
    for (auto str : strs)
    {
        string s = str;
        sort(str.begin(), str.end());
        mpp[str].push_back(s);
    }
    for (auto it : mpp)
    {
        ans.push_back(it.second);
    }
    return ans;
}

vector<vector<string>> groupAnagrams_Space(vector<string> &strs)
{
    unordered_map<string, vector<string>> mpp;

    for (const string &s : strs)
    {
        int count[26] = {0};

        for (char c : s)
            count[c - 'a']++;

        string key;
        for (int i = 0; i < 26; i++)
        {
            key += '#';
            key += to_string(count[i]);
        }

        mpp[key].push_back(s);
    }

    vector<vector<string>> ans;
    for (auto &it : mpp)
        ans.push_back(it.second);

    return ans;
}

int main()
{

    return 0;
}