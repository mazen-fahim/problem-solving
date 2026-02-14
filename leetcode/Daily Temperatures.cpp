// https://leetcode.com/problems/daily-temperatures/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    int sz = temperatures.size();
    vector<int> ans(sz, 0);
    stack<int> stk;
    stk.push(0);
    for (int i = 1; i < sz; i++) {
      int t = temperatures[i];
      while (!stk.empty()) {
        if (t > temperatures[stk.top()]) {
          ans[stk.top()] = i - stk.top();
          stk.pop();
        } else {
          break;
        }
      }
      stk.push(i);
    }
    return ans;
  }
};
