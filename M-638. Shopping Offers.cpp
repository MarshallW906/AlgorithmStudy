#include "./stdc++.h"

using namespace std;

class Solution {
    int dp[7][7][7][7][7][7];

   public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special,
                       vector<int>& needs) {
        int n = price.size();
        int nSpecial = special.size();
        int res = 0;
        for (int i = 0; i < n; i++) res += needs[i] * price[i];

        for (int i = 0; i < nSpecial; i++) {
            vector<int> restNeeds(n, 0);
            bool used = true;
            for (int j = 0; j < n; j++) {
                if (needs[j] < special[i][j]) {
                    used = false;
                    break;
                } else {
                    restNeeds[j] = needs[j] - special[i][j];
                }
            }
            if (used) {
                res = min(res, shoppingOffers(price, special, restNeeds));
            }
        }
        return res;
    }
};
