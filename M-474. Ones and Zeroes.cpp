#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
  public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, 0));
        int cnt0, cnt1;
        for (auto &s : strs) {
            cnt0 = cnt1 = 0;
            for (auto c : s) {
                if (c == '0') cnt0++;
                else cnt1++;
            }

            // memo[i][j] = the max number of strings that can be formed with i 0's and j 1's
            // from the first few strings up to the current string s
            // Catch: have to go from bottom right to top left
            // Why? If a cell in the memo is updated(because s is selected),
            // we should be adding 1 to memo[i][j] from the previous iteration (when we were not considering s)
            // If we go from top left to bottom right, we would be using results from this iteration => overcounting
            for (int i = m; i >= cnt0; i--) {
                for (int j = n; j >= cnt1; j--) {
                    memo[i][j] = max(memo[i][j], memo[i - cnt0][j - cnt1] + 1);
                }
            }
        }
        return memo[m][n];
    }
};
