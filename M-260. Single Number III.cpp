#include "./stdc++.h"

using namespace std;

class Solution {
   public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        int diff = 0;
        for (int i = 0; i < n; i++) diff ^= nums[i];
        diff &= -diff;
        vector<int> ret(2, 0);
        for (int i = 0; i < n; i++) {
            if ((nums[i] & diff) == 0)
                ret[0] ^= nums[i];
            else
                ret[1] ^= nums[i];
        }
        return ret;
    }
};