#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2) a = max(a + nums[i], b);
            else b = max(b + nums[i], a);
        }
        return max(a, b);
    }
};

int main() {
    Solution s;
    vector<int> a;
    a.push_back(1);
    a.push_back(1);
    cout << s.rob(a) << endl;
}