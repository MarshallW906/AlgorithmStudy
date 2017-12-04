class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int val[10010] = {0}, n = nums.size();
        for (int i = 0; i < n; i++) val[nums[i]] += nums[i];

        int a = 0, b = 0;
        for (int i = 0; i < 10010; i++) {
            if (i % 2) a = max(a + val[i], b);
            else b = max(b + val[i], a);
        }
        return max(a, b);
    }
};