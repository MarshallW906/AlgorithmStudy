#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        
        int n = nums.size();
        vector<int> f(n, 0);
        f[0] = nums[0];
        f[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++)
            f[i] = max(f[i - 1], f[i - 2] + nums[i]);
        return f[n - 1];
    }
};

int main() {
    Solution s;
    
}