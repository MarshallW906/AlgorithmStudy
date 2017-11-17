#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, ans = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            ans = max(ans, sum);
            sum = max(sum, 0);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> a = {-1};
    cout << s.maxSubArray(a) << endl;
}