#include "./stdc++.h"

using namespace std;

class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int max = 0, n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (i + nums[i] > max) max = i + nums[i];
            if (max >= n - 1) return true;
            if (max < i + 1) break;
        }
        return max >= n - 1;
    }
};
