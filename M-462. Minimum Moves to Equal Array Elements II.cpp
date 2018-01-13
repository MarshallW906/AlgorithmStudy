#include "./stdc++.h"

using namespace std;

class Solution {
   public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), res = 0;
        for (int i = 0; i < n / 2; ++i) res += (nums[n - 1 - i] - nums[i]);
        return res;
    }
};
