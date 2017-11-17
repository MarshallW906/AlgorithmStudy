class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sz = nums.size();
        vector<int> sums(nums);
        for (int subLen = 2; subLen <= sz; subLen++) {
            for (int i = subLen - 1; i < sz; i++) {
                sums[i] += nums[i - subLen + 1];
                if (k == 0 && sums[i] == 0) return true;
                else if (k == 0) continue;
                else if (sums[i] % k == 0) return true;
            }
        }
        return false;
    }
};
