// https://leetcode.com/problems/valid-sudoku/description/
// 2026 - 02 - 07

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isClosingBracket(char c) {
    return (c == '}') || (c == ')') || (c == ']');
  }
  bool isValid(string s) {
    stack<char> stk;
    map<char, char> m = {
        {')', '('},
        {']', '['},
        {'}', '{'},
    };

    for (auto c : s) {
      if (stk.size() && isClosingBracket(c) && (stk.top() == m[c])) {
        stk.pop();
      } else
        stk.push(c);
    }

    return stk.empty();
  }
};
