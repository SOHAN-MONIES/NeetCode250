// URL:
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;

bool check(string &s, int l, int r)
{
    while (l < r)
    {
        if (s[l] != s[r])
            return false;
        l++;
        r--;
    }
    return true;
}

bool validPalindrome(string s)
{
    int l = 0, r = s.size() - 1;
    while (l < r)
    {
        if (s[l] != s[r])
        {
            return check(s, l + 1, r) || check(s, l, r - 1);
        }
        l++;
        r--;
    }
    return true;
}
int main()
{
    validPalindrome("abca");
    return 0;
}