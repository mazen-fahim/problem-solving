// https://leetcode.com/problems/evaluate-reverse-polish-notation/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    stack<int> stk;
    for (auto token : tokens) {
      if (token == "+" || token == "-" || token == "*" || token == "/") {
        int n1 = stk.top();
        stk.pop();
        int n2 = stk.top();
        stk.pop();
        if (token == "+")
          stk.push(n2 + n1);
        else if (token == "-")
          stk.push(n2 - n1);
        else if (token == "*")
          stk.push(n2 * n1);
        else if (token == "/")
          stk.push(n2 / n1);
      } else {
        stk.push(stoi(token));
      }
    }

    return stk.top();
  }
};
