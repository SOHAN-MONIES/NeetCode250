// URL:
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;

bool check(vector<char> &rows)
{
    map<char, int> mpp;
    for (auto ch : rows)
    {
        if (ch != '.')
        {
            mpp[ch]++;
            if (mpp[ch] > 1)
            {
                return false;
            }
        }
    }
    return true;
}
bool checkMat(int r1, int r2, int c1, int c2, vector<vector<char>> &board)
{
    map<char, int> mpp;
    for (int i = r1; i <= r2; i++)
    {
        for (int j = c1; j <= c2; j++)
        {
            if (board[i][j] != '.')
            {
                mpp[board[i][j]]++;
                if (mpp[board[i][j]] > 1)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

bool isValidSudoku(vector<vector<char>> &board)
{
    for (auto it : board)
    {
        if (!check(it))
        {
            return false;
        }
    }
    for (int c = 0; c <= 8; c++)
    {
        map<char, int> mpp;
        for (int i = 0; i <= 8; i++)
        {
            if (board[i][c] != '.')
            {
                mpp[board[i][c]]++;
                if (mpp[board[i][c]] > 1)
                {
                    return false;
                }
            }
        }
    }
    int r1 = 0;
    int r2 = 2;

    for (int i = 0; i < 3; i++)
    {
        int c1 = 0;
        int c2 = 2;
        for (int j = 0; j < 3; j++)
        {
            if (!checkMat(r1, r2, c1, c2, board))
            {
                return false;
            }
            c1 += 3;
            c2 += 3;
        }
        r1 += 3;
        r2 += 3;
    }
    return true;
}
int main()
{

    return 0;
}