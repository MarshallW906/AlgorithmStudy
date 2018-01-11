#include "./stdc++.h"

using namespace std;

/**
 * DP.
 * I just forgot to let dp[i] = dp[i - 1] even though (profit[i] < maxProfit)
 */
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> maxfw, maxbk;
        maxfw.resize(n);
        maxbk.resize(n);
        int minIdx = 0, maxProfit = 0;
        for (int i = 0; i < n; i++) {
            if (prices[minIdx] > prices[i]) minIdx = i;
            maxProfit = maxfw[i] = max(maxProfit, prices[i] - prices[minIdx]);
        }
        for (int i = 0; i < n; i++) cout << maxfw[i] << ' ';
        cout << endl;

        int maxIdx = n - 1, maxProfit2 = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (prices[maxIdx] < prices[i]) maxIdx = i;
            maxProfit2 = maxbk[i] = max(maxProfit2, prices[maxIdx] - prices[i]);
        }

        for (int i = 0; i < n; i++) cout << maxbk[i] << ' ';
        cout << endl;

        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0)
                ret = max(ret, maxbk[i]);
            else
                ret = max(ret, maxbk[i] + maxfw[i - 1]);
        }
        return ret;
    }
};