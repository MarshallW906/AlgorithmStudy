#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minIdx = 0, maxProfit = 0;
        int n = prices.size();
        vector<int> f(n, 0);
        for (int i = 0; i < n; i++) {
            if (prices[i] < prices[minIdx]) {
                minIdx = i;
            } else {
                maxProfit = max(maxProfit, prices[i] - prices[minIdx]);
            }
        }
        return maxProfit;
    }
};