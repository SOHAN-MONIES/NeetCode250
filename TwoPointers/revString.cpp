// URL:
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;
void reverseString(string &s)
{
    int x = 0;
    int y = s.size() - 1;
    while (x < y)
    {
        swap(s[x], s[y]);
        x++;
        y--;
    }
}

int main()
{
    string s = "LENISHA DSOUZA";

    reverseString(s);
    for (auto ch : s)
    {
        cout << ch;
    }

    return 0;
}