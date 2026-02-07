// https://leetcode.com/problems/valid-sudoku/description/
// 2026 - 02 - 07

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    bool ans = true;
    // check rows
    for (int i = 0; i < 9; i++) {
      int freq[10] = {0};
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.')
          continue;
        if (freq[board[i][j] - '0'])
          return false;
        else
          freq[board[i][j] - '0']++;
      }
    }

    // check cols
    for (int i = 0; i < 9; i++) {
      int freq[10] = {0};
      for (int j = 0; j < 9; j++) {
        if (board[j][i] == '.')
          continue;
        if (freq[board[j][i] - '0'])
          return false;
        else
          freq[board[j][i] - '0']++;
      }
    }

    // check squares

    int freq[3][3][10] = {0};
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.')
          continue;

        int sr = i / 3;
        int sc = j / 3;
        if (freq[sr][sc][board[i][j] - '0'])
          return false;
        else
          freq[sr][sc][board[i][j] - '0']++;
      }
    }

    return ans;
  }
};
