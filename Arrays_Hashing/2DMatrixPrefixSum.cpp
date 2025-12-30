// URL:
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;
/*
✅ Algorithm: Range Sum Query 2D – Immutable (2D Prefix Sum)

Problem:
You are given a 2D matrix.
You need to answer multiple queries of the form:
    sumRegion(row1, col1, row2, col2)
which returns the sum of elements inside the rectangle
with top-left (row1, col1) and bottom-right (row2, col2).

-------------------------------------------------
Idea:

Use a **2D Prefix Sum Matrix** to preprocess cumulative sums
so that each query can be answered in O(1) time.

-------------------------------------------------
Prefix Sum Definition:

prefix[i][j]:
- Sum of all elements in the submatrix
  from (0,0) to (i-1, j-1)

We use an extra row and column (size n+1 × m+1)
to avoid boundary checks.

-------------------------------------------------
Prefix Construction Formula:

prefix[i][j] =
    matrix[i-1][j-1]
  + prefix[i][j-1]
  + prefix[i-1][j]
  - prefix[i-1][j-1]

-------------------------------------------------
Query Formula:

Sum of rectangle (row1, col1) to (row2, col2):

sum =
    prefix[row2+1][col2+1]
  - prefix[row1][col2+1]
  - prefix[row2+1][col1]
  + prefix[row1][col1]

-------------------------------------------------
Why It Works:

- prefix[row2+1][col2+1] gives sum of entire top-left area
- Subtract extra top and left regions
- Add back overlapping region (inclusion-exclusion)

-------------------------------------------------
Time Complexity:
- Preprocessing: O(n × m)
- Each Query: O(1)

-------------------------------------------------
Space Complexity:
O(n × m)
- Stores prefix sum matrix

-------------------------------------------------
🎯 Intuition:
Trade preprocessing time for extremely fast queries.
Once prefix sums are built, any rectangular sum
can be answered instantly.

-------------------------------------------------
*/

class NumMatrix
{
public:
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        prefix.resize(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                prefix[i][j] = matrix[i - 1][j - 1] + prefix[i][j - 1] + prefix[i - 1][j] - prefix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return prefix[row2 + 1][col2 + 1] - prefix[row1][col2 + 1] - prefix[row2 + 1][col1] + prefix[row1][col1];
    }
};
int main()
{

    return 0;
}